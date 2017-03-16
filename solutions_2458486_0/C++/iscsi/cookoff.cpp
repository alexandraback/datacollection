#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;

int main()
{
#ifdef HOME
	freopen ("D-small-attempt0.in","r",stdin);
	freopen ("D-small-attempt0.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		int K,N;
		scanf("%d %d",&K,&N);
		map<int,int> keyId;
		vector<int> start(K);
		REP(i,K)
		{
			scanf("%d",&start[i]);
		}
		VVI keys(N);
		VI kk(N);
		REP(i,N)
		{
			int Ti,Ki;
			scanf("%d",&Ti);
			int tmp;
			if(!keyId.count(Ti))
			{
				tmp=keyId.size();
				keyId[Ti]=tmp;
			}
			tmp=keyId[Ti];
			kk[i]=tmp;
			scanf("%d",&Ki);
			keys[i].resize(Ki);
			REP(j,Ki)
				scanf("%d",&keys[i][j]);
		}
		VI ns;
		REP(i,start.size()) if(keyId.count(start[i])) ns.push_back(start[i]);
		ns.swap(start);
		VVI v(1<<N,VI(1,-1));
		v[(1<<N)-1].clear();
		for(int mask=(1<<N)-2;mask>=0;--mask)
		{
			VI mk(N);
			REP(i,start.size())
				++mk[keyId[start[i]]];
			REP(i,N)if((1<<i) & mask) 
			{
				--mk[kk[i]];
				REP(j,keys[i].size())
					++mk[keyId[keys[i][j]]];
			}
			REP(i,N) if(((1<<i) & (~mask))  && mk[kk[i]])
			{
				int newm=mask|(1<<i);
				if(v[newm].empty() || v[newm][0]!=-1)
				{
					VI nn(1,i);
					nn.insert(nn.end(),v[newm].begin(),v[newm].end());
					if((v[mask].size()==1 && v[mask][0]==-1 ) || v[mask]>nn)
					{
						v[mask].swap(nn);
					}
				}
			}
		}
		if(v[0].size()==1 && v[0][0]==-1)
		{
			printf("Case #%d: IMPOSSIBLE\n",testcase);
		}
		else
		{
			printf("Case #%d: ",testcase);
			REP(i,v[0].size())
				printf("%d ",v[0][i]+1);
			printf("\n");
		}
	}
	return 0;
} 