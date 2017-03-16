
#include <stdio.h>
#include <algorithm>
int size;
int others;
int other[100];
int minMoves;
int movesToAbsorbPrevious;

void absorb(int index)
{
	int movesToRemoveRest = others - index;
	if(minMoves > movesToAbsorbPrevious + movesToRemoveRest)
	{
		minMoves = movesToAbsorbPrevious + movesToRemoveRest;
	}

	int movesToAbsorbCurrent = 0;

	while(size<=other[index])
	{
		size+=size-1;
		movesToAbsorbCurrent++;
	}
	size += other[index];
	movesToAbsorbPrevious += movesToAbsorbCurrent;
}

int countMinMoves()
{
	std::sort(other, other + others);
	movesToAbsorbPrevious = 0;
	minMoves = others;
	if(size == 1)
		return minMoves;

	for(int i=0; i<others; i++)
	{
		absorb(i);
	}
	if(minMoves > movesToAbsorbPrevious)
	{
		minMoves = movesToAbsorbPrevious;
	}
	return minMoves;
}

int main()
{
	int count;
	scanf("%d", &count);

	for(int i=0; i<count; i++)
	{
		scanf("%d%d", &size, &others);
		for(int j=0; j<others; j++)
		{
			scanf("%d", &other[j]);
		}
		printf("Case #%d: %d\n", i+1, countMinMoves());
	}
	return 0;
}