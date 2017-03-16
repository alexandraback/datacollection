#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int R,C,M,T;
bool visit[55][55][2505];
bool possible[55][55][2505];
int  choice[55][55][2505];

bool solve(int row, int lastZero, int target)
{
	if (target == 0)
	{
		if (row >= R || lastZero == 0)
	 		return true;
	 	return false;
	}
	if (row >= R) return false;
	if (target < 0) return false;
	if (lastZero == 0) return false;

	if (visit[row][lastZero][target])
		return possible[row][lastZero][target];

	visit[row][lastZero][target]=true;
	int w = min(lastZero+1,C);
	for (int myZero = 0; myZero <= lastZero; myZero++)
		if (solve(row+1,myZero,target-w))
		{
			choice[row][lastZero][target] = myZero;
			return possible[row][lastZero][target] = true;
		}
	return possible[row][lastZero][target] = false;
}
void putRow(int w,bool first)
{
	int i = 0;
	if (first) {printf("c"); i++;}
	for (;i<w && i<C;i++) printf(".");
	for (;i<C;i++) printf("*");
	printf("\n");
}
int main()
{
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		scanf("%d %d %d",&R,&C,&M);
		//if (R<C) swap(R,C); //now R>=C
		printf("Case #%d:\n",kase);
		if (M + 1 == R*C)
		{
			printf("c");
			for (int i=1;i<C;i++) printf("*"); printf("\n");
			for (int i=1;i<R;i++) 
			{
				for (int j=0;j<C;j++)
					printf("*");
				printf("\n");
			}
		}
		else 
		{
			//at least one zero
			bool found = false;
			memset(visit,0,sizeof(visit));
			for (int z=1;z<=C;z++)
			{
				int w = min(z+1,C);
				if (solve(1,z,R*C - M - w))
				{
					int cz=z,ct=R*C-M-w;
					putRow(min(cz+1,C),true);
					for (int cr=1;cr<R;cr++)
					{
						if (ct > 0)
						{
							putRow(min(cz+1,C),false);
							int nt = ct - min(cz+1,C);
							int nz = choice[cr][cz][ct];
							ct = nt, cz = nz;
						}
						else putRow(0,false);
					}
					found = true;
					break;
				}
			}
			if (not found) printf("Impossible\n");
		}
	}
	return 0;
}