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

int n;
int keys[20][200];
int types[20];
bool use[1<<20];
int can[1<<20];
vector<int> best;
vector<int> cur;
vector<int> ke;

void doit (int mask)
{
	if (use[mask]) return;
	use[mask]=true;
	if (cur.size() > best.size())
	{
		best = cur;
	}
	for (int i=0;i<n;i++)
	{
		if (!(mask&(1<<i)) && can[mask]&(1<<i))
		{
			cur.push_back(i+1);
			doit(mask|(1<<i));
			cur.pop_back();
		}
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
		int k,i,a;
		int res=0;

		scanf ("%d %d",&k,&n);
		ke.assign(200,0);
		memset (keys,0,sizeof (keys));
		while (k--)
		{
			scanf ("%d",&a);
			ke[a-1]++;
		}
		for (i=0;i<n;i++)
		{
			scanf ("%d %d",&types[i],&k);
			types[i]--;
			while (k--)
			{
				scanf ("%d",&a);
				keys[i][a-1]++;
			}
		}
		memset (use,0,sizeof (use));
		memset (can,0,sizeof (can));
		for (i=0;i<(1<<n);i++)
		{
			int m=0;
			for (int j=0;j<n;j++)
			{
				int t=types[j];
				int s=ke[t];
				for (int k=0;k<n;k++)
				{
					if (i&(1<<k))
					{
						s=s-(types[k]==t)+keys[k][t];
					}
				}
				if (s>0) m|=(1<<j);
			}
			can[i]=m;
		}
		best.clear();
		cur.clear();
		doit (0);
		printf ("Case #%d:",step);
		if (best.size() != n) printf (" IMPOSSIBLE");
		else
		{
			for (i=0;i<best.size();i++) printf (" %d",best[i]);
		}
		printf ("\n");
	}
	return 0;
}