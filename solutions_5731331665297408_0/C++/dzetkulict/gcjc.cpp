#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int zip[100];
int zips[100];
int visited[100];
int order[100];
int stack[100];
int sts,n,oc;
vector<vector<int> > x;

void go2(int c)
{
	if (visited[c]) return;
	visited[c]=3;
	for (size_t l=0;l<x[c].size();++l) go2(x[c][l]);
}

void go(int c)
{
	stack[sts]=c;
	visited[c]=1;
	order[oc]=c;
	++sts;
	++oc;
	int i,j,k;
	while (1)
	{
		for (i=0;i<n;++i)
		{
			int z=zips[i];
			for (j=0;j<n;++j) if (zip[j]==z) break;
			if (visited[j]) continue;
			for (k=sts-1;k>=0;--k)
			{
				int found=0;
				for (size_t l=0;l<x[stack[k]].size();++l) if (x[stack[k]][l]==j) { found=1; }
				if (found) break;
			}
			if (k==sts-1)
			{
				go(j);
				break;
			} else
			{
				int l,ok=1;
				for (l=0;l<=k;++l) go2(stack[l]);
				for (l=0;l<n;++l)
				{
					if (visited[l]==0) ok=0;
					if (visited[l]==3) visited[l]=0;
				}
				if (ok)
				{
					--sts;
					return;
				}
			}
		}
		if (i==n) break;
	}
	--sts;
}

int main()
{
	int tc,m,i,j;
	scanf("%d",&tc);
	tc=0;
	while (scanf("%d %d",&n,&m)==2)
	{
		x.clear();
		x.resize(n);
		for (i=0;i<n;++i)
		{
			scanf("%d",zip+i);
			zips[i]=zip[i];
			visited[i]=0;
		}
		sort(zips,zips+n);
		for (i=0;i<m;++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			--a; --b;
			x[a].push_back(b);
			x[b].push_back(a);
		}
		j=0;
		for (i=1;i<n;++i) if (zip[i]<zip[j]) j=i;
		sts=0;
		oc=0;
		go(j);
		printf("Case #%d: ",++tc);
		for (i=0;i<oc;++i) printf("%d",zip[order[i]]);
		printf("\n");
	}
}
