#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int v[20000][12];
map<long long,int> yes[20000];
int cnt[20000];
int idx[2][20000];
int total;

void gen(int pos, int digit, int maxd)
{
	if (pos>=12)
	{
		total++;
		memcpy (v[total],v[total-1],sizeof (v[0]));
		return;
	}
	for (int i=digit;i<=maxd;i++)
	{
		v[total][pos]=i;
		gen(pos+1,i,maxd);
	}
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int r,n,m,k,i,j,u,b;

		scanf ("%d %d %d %d",&r,&n,&m,&k);
		total=0;
		gen(0,2,m);
		for (i=0;i<total;i++)
		{
			for (j=0;j<(1<<n);j++)
			{
				long long p=1;
				for (int jj=0;jj<n;jj++)
				{
					if (j&(1<<jj)) p*=v[i][jj];
				}
				yes[i][p]++;
			}
		}
		printf ("Case #%d:\n",step);
		while (r--)
		{
			memset (cnt,0,sizeof(cnt));
			for (i=0;i<total;i++)idx[0][i]=i;
			idx[0][i]=-1;
			b=0;
			for (i=0;i<k;i++)
			{
				long long a;
				scanf ("%lld",&a);
				int cc=0;
				for (int j=0;idx[b][j]>=0;j++)
				{
					u=idx[b][j];
					if (yes[u].count(a)>0)
					{
						cnt[u]+=yes[u][a];
						idx[!b][cc++]=u;
					}
				}
				idx[!b][cc]=-1;
				b=!b;
			}
			int imx=-1;
			for (i=0;idx[b][i]>=0;i++)
			{
				if (imx<0 || cnt[idx[b][i]]>cnt[imx])
				{
					imx=idx[b][i];
				}
			}
			for (i=0;i<n;i++) printf ("%d",v[imx][i]);
			printf ("\n");
		}
	}
	return 0;
}