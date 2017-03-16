#include "DisjointSet.h"

DisjointSet::DisjointSet(size_t numElements) : _set(numElements, -1)
{
	_roots = numElements;
}

const size_t DisjointSet::countRoots()
{
	return _roots;
}

void DisjointSet::unionSets(size_t root1, size_t root2)
{
	if(root1 == root2)
	{
		return;
	}
	
	if(_set[root2] < _set[root1])
	{
		//root2 is deeper and should now be root.
		_set[root1] = root2;
		_roots--;
		return;
	}
	
	if(_set[root1] == _set[root2])
	{
		//update height.
		--_set[root1];
	}
	//make root 1 new root.
	_set[root2] = root1;
	_roots--;
}

size_t DisjointSet::find(size_t x)
{
	if(_set[x] < 0)
	{
		return x;
	}	
	return _set[x] = find(_set[x]);
}

