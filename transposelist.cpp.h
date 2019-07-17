#include "dlist.h"
#include "transposelist.h"

template <class Object>
int TransposeList<Object>::find(const Object &obj) {
	DListNode<Object> *found = DList<Object>::header->next;

	int i = 0;
	for (; found != NULL && found->item != obj; found = found->next, ++i)
	{
		++DList<Object>::cost;
	}
	if (found == NULL)										// not found 
	{
		return -1;
	}
	else if (found == DList<Object>::header->next)			// no need to swap 
	{
		return 0;
	}
	else
	{
		if (found->prev != NULL)							// remove found from the current position
		{
			found->prev->next = found->next;
		}
		if (found->next != NULL)
		{
			found->next->prev = found->prev;
		}

		DListNode<Object> *prevPtr = found->prev;
		found->prev = prevPtr->prev;							//insert found before previous
		found->next = prevPtr;
		prevPtr->prev->next = found;
		prevPtr->prev = found;
	}
	return i;
}


