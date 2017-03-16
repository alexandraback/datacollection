#include<stdio.h>
#include<string.h>
#include<vector.h>
FILE *in,*out;
vector<int> i[16384];
int c[16384];
int j[16384];
int b[16384];
bool dfs(int x)
{
	int a;
	if( b[x]==1 ) return true;
	b[x]=1;
	for(a=0;a<c[x];a++)
	{
		if( dfs(i[x][a]) ) return true;
	}
	return false;
}
int main()
{
	in =fopen("a.in" ,"r");
	out=fopen("a.out","w");
	int tests,test;
	int n;
	int a,s,d;
	fscanf(in,"%d",&tests);
	for(test=0;test<tests;test++)
	{
		fprintf(out,"Case #%d: ",test+1);
		fscanf(in,"%d",&n);
		for(a=0;a<n;a++)
		{
			c[a]=0;
			i[a].clear();
			j[a]=0;
		}
		for(a=0;a<n;a++)
		{
			fscanf(in,"%d",&c[a]);
			for(s=0;s<c[a];s++)
			{
				fscanf(in,"%d",&d); d--;
				i[a].push_back(d);
				j[d]++;
			}
		}
		for(a=0;a<n;a++)
		{
			if( j[a]==0 )
			{
				for(s=0;s<n;s++) b[s]=0;
				if( dfs(a) ) break;
			}
		}
		if( a<n ) fprintf(out,"Yes\n");
		else fprintf(out,"No\n");
	}
	return 0;
}