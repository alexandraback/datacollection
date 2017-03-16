#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define MAX_X 1000000*15+10
set<int> diagtable[MAX_X];
set<int> diagpos[10000];
/*
//  pos, id
map<int, int> diagsprime;
//  id, pos
map<int, int> sums;*/

int nomoves(int x, int y)
{
	int diag1 = abs(x)+abs(y);
	auto it = diagtable[diag1].begin();
	return *it;
}
int can_in_moves(int x, int y, int n)
{
	int diag1 = abs(x)+abs(y);
	return diagtable[diag1].count(n);
}

int main()
{
	diagtable[0].insert(0);
	diagpos[0].insert(0);
	
	for(int i=0;i<823;i++)
	{
		fprintf(stderr, "Number %d: %d\n", i, diagpos[i].size());
		for(int pos : diagpos[i])
		{
			//printf("Present at %d\n", pos);
			if(pos+i+1<MAX_X)
			{
				diagtable[pos+i+1].insert(i+1);
				diagpos[i+1].insert(pos+i+1);
				//printf("  %d at position %d\n", i+1, pos+i+1);
			}
			{
				diagtable[abs(pos-i-1)].insert(i+1);
				diagpos[i+1].insert(abs(pos-i-1));
				//printf("  %d at position %d\n", i+1, abs(pos-i-1));
			}
			{
				diagtable[abs(i+1-pos)].insert(i+1);
				diagpos[i+1].insert(abs(i+1-pos));
				//printf("  %d at position %d\n", i+1, abs(pos-i-1));
			}
		}
	}
	
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		int x,y;
		
		scanf("%d %d", &x, &y);
		int bx=x, by=y;
		
		string sol;
		
		//printf("Point %d,%d:\n", x, y);
		int m = nomoves(x,y);
		
		while(m)
		{
			
			//printf("(%d , %d) : %d\n", x, y, m);

			if(can_in_moves(x,y-m,m-1))
			{
				sol+="N";
				y-=m;
				m--;
				continue;
			}
			if(can_in_moves(x,y+m,m-1))
			{
				sol+="S";
				y+=m;
				m--;
				continue;
			}
			if(can_in_moves(x-m,y,m-1))
			{
				sol+="E";
				x-=m;
				m--;
				continue;
			}
			if(can_in_moves(x+m,y,m-1))
			{
				sol+="W";
				x+=m;
				m--;
				continue;
			}
		}
		
		string psol(sol.rbegin(), sol.rend());
		
		printf("Case #%d: %s\n",i, psol.c_str());
		
		/*int tx=0,ty=0;
		for(int i=0;i<psol.size();i++)
		{
			if(psol[i]=='N') ty+=i+1;
			if(psol[i]=='S') ty-=i+1;
			if(psol[i]=='E') tx+=i+1;
			if(psol[i]=='W') tx-=i+1;
		}
		printf("FINISHED at %d %d (%d %d)\n", tx, ty, bx, by);
		if(tx!=bx || ty!=by)
			printf("ERROR\nERROR\nERROR\n");*/
	}
}
