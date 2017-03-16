#include<stdio.h>
#include<set>

using namespace std;

#define MAX 100

bool CanMake(int lawn[][MAX], int r, int c, int treshold)
{
	bool freerow[MAX];
	bool freecol[MAX];
	for(int i=0;i<r;i++)
	{
		freerow[i]=true;
		for(int j=0;j<c;j++)
			if(lawn[i][j]>treshold)
				freerow[i]=false;
	}
	for(int i=0;i<c;i++)
	{
		freecol[i]=true;
		for(int j=0;j<r;j++)
			if(lawn[j][i]>treshold)
				freecol[i]=false;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(lawn[i][j]==treshold)
			{
				if(!freerow[i] && !freecol[j])
					return false;
			}
		}
	}
	return true;
}

bool CanMake(int lawn[][MAX], int r, int c)
{
	set<int> heights;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			heights.insert(lawn[i][j]);
	for(set<int>::reverse_iterator i = heights.rbegin(); i!=heights.rend(); i++)
	{
		if(!CanMake(lawn,r,c,*i))
			return false;
	}
	return true;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int lawn[MAX][MAX];
	int T, r, c;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&lawn[i][j]);
		if(CanMake(lawn,r,c)) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
	return 0;
}