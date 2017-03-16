#include <stdio.h>
#include <stdlib.h>

int compareAscending (const void * a, const void * b)
{
  return ( (*(int*)a) - (*(int*)b));
}


int main()
{
	int numCases = 0;

	int A,N;
		
	int rest, rest2;

	int motes[100];
	
	int i,j,k;

	int numMoves;
	
	scanf("%d",&numCases);

	for (i=0;i<numCases;i++)
	{	
		numMoves = 0;
		scanf("%d",&A);
		scanf("%d",&N);
		for (j=0;j<N;j++)
		{
			scanf("%d",&(motes[j]));
		}

		qsort(motes,N,sizeof(int),compareAscending);
		/* first absorb all possible motes */

		for (j=0;j<N;j++)
		{
			if (A>motes[j])
			{
				A+=motes[j];
			}
			else
				break;
		}
	
		while (j<N && motes[j]-A+1<A)
		{
			A+=A-1;
			numMoves++; // added a mote
			while(j<N && motes[j]<A)
			{
				A+=motes[j];
				j++;
			}
		}

		// need to remove rest of the motes
		rest=(N-j);

		rest2 = 0;

		if (A-1 != 0) {

		while (j<N)
		{
			A+=A-1;
			rest2++; // added a mote
			while(j<N && motes[j]<A)
			{
				A+=motes[j];
				j++;
			}
		}
		}
		else rest2 = rest+1;

		if (rest<rest2)
			numMoves+=rest;
		else
			numMoves+=rest2;


		printf("Case #%d: %d\n",i+1,numMoves);
	}

	return 0;
	
}
