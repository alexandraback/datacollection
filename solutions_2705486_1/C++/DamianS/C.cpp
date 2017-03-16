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
#include <fstream>
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
set<string> S;
int dp[5000][6];

int main()
{
    //ios_base::sync_with_stdio(0);
    string s;
    ifstream f("dict.txt");
    int ile=0;
    vi v(100);
    while(f>>s)
    {
		S.insert(s);
	}
	int te=0;
    tests
    {
		cin>>s;
		//s="";
		//while(s.sz<4000) s+=char('a'+rand()%26);
		//DBG(s);
		int n=s.sz;
		DBG(n);
		FOR(i,n+1)FOR(j,6)dp[i][j]=1<<30;
		FOR(j,6)dp[0][j]=0;
		REP(i,1,n)
		{
			//DBG(i);
			REP(k,1,min(10,i))
			{
				string g=s.substr(i-k,k);
				if (IN(g,S))
				{
					FOR(j,6)REMIN(dp[i][min(5,j+k)],dp[i-k][j]);
				}
				FOR(l1,k)REP(c,'a','z')
				{
					string G=g;
					G[l1]=c;
					if (IN(G,S))
					{
						REMIN(dp[i][min(5,k-l1)],dp[i-k][max(1,5-l1)]+1);
					}
				}
				FOR(l2,k)FOR(l1,l2)
				{
					if (l2-l1<5) continue;
					REP(c1,'a','z')REP(c2,'a','z')
					{
						string G=g;
						G[l1]=c1;
						G[l2]=c2;
						if (l2-l1>=5 && IN(G,S))
						{
							REMIN(dp[i][min(5,k-l2)],dp[i-k][max(1,5-l1)]+2);
						}
					}
				}
			}
			//DBG(i);
			//DBG(vi(dp[i],dp[i]+6))
			REPD(j,4,1)REMIN(dp[i][j],dp[i][j+1]);
		}
		
		printf("Case #%d: %d\n",++te,dp[n][1]);
	}
    
    return 0;
}
