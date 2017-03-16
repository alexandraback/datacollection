#include<cstdio>
#include<stdlib.h>
#include<vector>
#define MAX 500
using namespace std;
typedef vector<char> VC;
int X,Y;
bool dfs(int jump,int px,int py,VC vec)
{
	if(jump>MAX) return 0;
	if(px==X && py==Y)
	{
		for(px=0;px<vec.size();px++) putchar(vec[px]);
		puts("");
		return 1;
	}
	switch(rand()%4)
	{
		case 0:	vec.push_back('N');
				py+=jump;
				break;
		case 1:	vec.push_back('S');
				py-=jump;
				break;
		case 2:	vec.push_back('E');
				px+=jump;
				break;
		case 3:	vec.push_back('W');
				px-=jump;
				break;
	}
	return dfs(jump+1,px,py,vec);
}
main()
{
	freopen("B-small.in","r",stdin);
	freopen("B-small-out.txt","w",stdout);
	int Test,Case,i,j,k,nt;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scanf("%d %d",&X,&Y);
		printf("Case #%d: ",Case);
		while(!dfs(1,0,0,VC(0)));
	}
}
