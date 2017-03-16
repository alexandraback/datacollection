#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Node
{
	int ID;
	struct Node *pNext;
};
struct Node Table[10001];
struct Node* pMap[1001],*p;
int Tag[1001],index;

queue<int> Q;
int main()
{
	freopen("C:\\A-large.in", "r", stdin);
	freopen("C:\\A-l.out", "w", stdout);
	int i,j,T,cases=0,N,M,D, Isdiamond;
	scanf("%d", &T);
	while(++cases <= T)
	{
		Isdiamond = 0;
		index = 0;
		memset(pMap, 0, sizeof(pMap));
		scanf("%d", &N);
		for(i=1; i<=N; i++)
		{
			scanf("%d", &M);
			for(j=1; j<=M; j++)
			{
				scanf("%d", &D);
				Table[index].pNext = pMap[i];
				pMap[i] = &Table[index];
				Table[index].ID = D;
				index++;
			}
		}
		
		for(i=1; i<=N; i++)
		{
			memset(Tag, 0, sizeof(Tag));
			while(!Q.empty())
				Q.pop();
			Q.push(i);
			Tag[i] = 1;
			while (!Q.empty()&&!Isdiamond)
			{
				D = Q.front();
				Q.pop();
				p = pMap[D];
				while (p!=NULL)
				{
					if(Tag[p->ID])
					{
						Isdiamond = 1;
						break;
					}
					Q.push(p->ID);
					Tag[p->ID] = 1;
					p = p->pNext;
				}
			}
			if(Isdiamond)
				break;
		}
		if(Isdiamond)
			printf("Case #%d: Yes\n", cases);
		else
			printf("Case #%d: No\n", cases);
	}

	return 0;
}