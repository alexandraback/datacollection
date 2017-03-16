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

int v[100][3];
int cnt[100];
int total;

void gen(int pos, int digit, int maxd)
{
	if (pos>=3)
	{
		total++;
		v[total][0]=v[total-1][0];
		v[total][1]=v[total-1][1];
		v[total][2]=v[total-1][2];
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
		int r,n,m,k,i,j;

		scanf ("%d %d %d %d",&r,&n,&m,&k);
		total=0;
		gen(0,2,m);

		printf ("Case #%d:\n",step);
		while (r--)
		{
			vector<bool> used(total,true);
			memset (cnt,0,sizeof(cnt));
			for (i=0;i<k;i++)
			{
				int a;
				scanf ("%d",&a);
				for (int ii=0;ii<total;ii++)
				{
					if (used[ii])
					{
						used[ii]=false;
						for (j=0;j<(1<<n);j++)
						{
							int pp=1;
							for (int jj=0;jj<n;jj++)
							{
								if (j&(1<<jj)) pp*=v[ii][jj];
							}
							if (pp==a)
							{
								cnt[ii]++;
								used[ii]=true;
							}
						}
					}
				}
			}
			int imx=-1;
			for (i=0;i<total;i++)
			{
				if (used[i] && (imx<0 || cnt[i]>cnt[imx]))
				{
					imx=i;
				}
			}
			for (i=0;i<n;i++) printf ("%d",v[imx][i]);
			printf ("\n");
		}
	}
	return 0;
}