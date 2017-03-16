#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct edge
{
	int dest[1000];
	int numDest;

	edge() { numDest = 0; }
};


edge data[1000];

int main()
{	
	int numCase, cases, numNode, numDepend, i, j, dependOn, count[1000], numPath[1000], current;	
	queue<int> bfs;
	bool exist;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i\n", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		scanf("%i", &numNode);

		// init
		memset(count, 0, numNode * 4);
		for(i = 0; i < numNode; i++)
			data[i].numDest = 0;
		
		for(i = 0; i < numNode; i++)
		{
			scanf("%i", &numDepend);
			for(j = 0; j < numDepend; j++)
			{
				scanf("%i", &dependOn);			
				count[dependOn - 1]++;
				data[dependOn - 1].dest[data[dependOn - 1].numDest++] = i;
			}
		}
		
		exist = false;
		for(i = 0; i < numNode; i++)
		{			
			if(count[i] >= 2)
			{
				memset(numPath, 0, numNode * 4);
				bfs.push(i);
				while(!bfs.empty())
				{
					current = bfs.front();
					bfs.pop();
					for(j = 0; j < data[current].numDest; j++)
					{
						numPath[ data[current].dest[j] ] ++;
						bfs.push(data[current].dest[j]);
						if(numPath[ data[current].dest[j] ] >= 2)
						{
							exist = true;
							break;
						}
					}

					if(exist)
					{
						while(!bfs.empty())
							bfs.pop();
					}
				}
			}
		}

		if(exist == true)
			printf("Case #%i: Yes\n", numCase);
		else
			printf("Case #%i: No\n", numCase);
	}

	return 0;
}