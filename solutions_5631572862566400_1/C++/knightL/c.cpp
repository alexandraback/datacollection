#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

const int MAXN=1001;

int F[MAXN];
int used[MAXN];
int cid[MAXN];
int cycleLen[MAXN];

vector<vector<int> > v, cycle;

int getLongest(int cur, int p)
{
	int res=0;
	for(int i=0;i<v[cur].size();i++)
	{
		int to=v[cur][i];
		if(to!=p)
			res=max(res, getLongest(to, cur)+1);
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int n;
		scanf("%d",&n);
		v.clear();
		v.resize(n);
		cycle.clear();
		cycle.resize(n);
		REP(i,n)
		{
			scanf("%d",&F[i]);
			F[i]--;
			v[F[i]].push_back(i);
			used[i]=0;
			cid[i]=0;
			cycleLen[i]=0;

		}
		REP(i,n)
		{
			int cur=i;
			REP(j,n)
				cur=F[cur];
			REP(j,n)
			{
				cid[cur]=i+1;
				cur=F[cur];
			}
		}
		REP(i,n)
			if(cid[i]>0)
			{
				cycleLen[cid[i]-1]++;
				cycle[cid[i]-1].push_back(i);
			}
		int res=0;
		REP(i,n)
			res=max(res, cycleLen[i]);


		int cnt2=0;
		int max2=0;
		REP(i,n)
			if(cycleLen[i]==2)
			{
				cnt2++;
				max2+=getLongest(cycle[i][0], cycle[i][1])+getLongest(cycle[i][1],cycle[i][0]);
			}
		res=max(res, 2*(cnt2)+max2);

		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
