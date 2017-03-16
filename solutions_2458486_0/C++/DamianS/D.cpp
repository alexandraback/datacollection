#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
int K,N;
vi s;
int need[22];
vi sa[22];
vi dp[1<<20];
vi lex[1<<20];
bool dasie[1<<20];

int main()
{
	int te=0;
    tests
    {
		cin>>K>>N;
		s.resize(K);
		FOR(i,K) cin>>s[i];
		dp[0]=s;
		FOR(i,N)
		{
			cin>>need[i];
			int x;CZ(x);
			sa[i].resize(x);
			FOR(j,x) cin>>sa[i][j];
		}
		dasie[0]=1;
		FOR(i,1<<N)
		{
			if (!i) continue;
			dasie[i]=0;
			vi best(1,10000);
			FOR(j,N)
			{
				if (!((1<<j)&i))continue;
				if (!dasie[i^(1<<j)]) continue;
				bool ok=0;
				FORE(k,dp[i^(1<<j)])
				{
					if (*k==need[j])
					{
						ok=1;
						break;
					}
				}
				if (ok)
				{
					dasie[i]=1;
					vi z=lex[i^(1<<j)];
					z.pb(j);
					REMIN(best,z);
				}
			}
			//DBG(mp(i,dasie[i]));
			if (!dasie[i]) continue;
			lex[i]=best;
			int m=0;
			while(!((1<<m)&i) || !dasie[i^(1<<m)]) m++;
			dp[i]=dp[i^(1<<m)];
			FOR(j,sa[m].sz) dp[i].pb(sa[m][j]);
			FOR(j,dp[i].sz)
			{
				if (dp[i][j]==need[m])
				{
					swap(dp[i][j],dp[i].back());
					dp[i].pop_back();
					break;
				}
			}
			//DBG(lex[i]);
		}
		if (!dasie[(1<<N)-1]) printf("Case #%d: IMPOSSIBLE\n",++te);
		else 
		{
			printf("Case #%d: ",++te);
			FOR(i,N) printf("%d ",lex[(1<<N)-1][i]+1);
			puts("");
		}
	}
    
    return 0;
}
