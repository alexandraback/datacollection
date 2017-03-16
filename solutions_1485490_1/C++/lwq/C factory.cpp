#include<stdio.h>
#include<string.h>
#include<vector.h>
FILE *in,*out;
int m,n;
long long i[1024][2];
long long j[1024][2];
const int hm=1048576;
vector<long long> h[hm];
vector<long long> hv[hm];
long long dfs(int p,int q,long long x,long long y)
{
	long long t;
	int u;
	long long v,o;
	int a;
	t=(x+y)%1234567891LL;
	t*=100; t+=p;
	t*=100; t+=q;
	u=t%1048573;
	for(a=0;a<(signed)h[u].size();a++) if( h[u][a]==t ) break;
	if( a<(signed)h[u].size() ) return hv[u][a];
	if( p==m || q==n )
	{
		o=0;
	}
	else if( i[p][0]==j[q][0] )
	{
		if( i[p][1]-x<j[q][1]-y )
		{
			o=i[p][1]-x+dfs(p+1,q,0,y+i[p][1]-x);
		}
		else
		{
			o=j[q][1]-y+dfs(p,q+1,x+j[q][1]-y,0);
		}
	}
	else
	{
		o=dfs(p+1,q,0,y);
		v=dfs(p,q+1,x,0);
		if( v>o ) o=v;
	}
	h[u].push_back(t);
	hv[u].push_back(o);
	return o;
}
int main()
{
	in =fopen("c.in" ,"r");
	out=fopen("c.out","w");
	int tests,test;
	int a;
	fscanf(in,"%d",&tests);
	for(test=0;test<tests;test++)
	{
		fprintf(out,"Case #%d: ",test+1);
		for(a=0;a<hm;a++)
		{
			h[a].clear();
			hv[a].clear();
		}
		fscanf(in,"%d%d",&m,&n);
		for(a=0;a<m;a++) fscanf(in,"%I64d%I64d",&i[a][1],&i[a][0]);
		for(a=0;a<n;a++) fscanf(in,"%I64d%I64d",&j[a][1],&j[a][0]);
		fprintf(out,"%I64d\n",dfs(0,0,0,0));
	}
	return 0;
}