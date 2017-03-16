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

string s[4];

bool check(char c)
{
	FOR(i,4)
	{
		bool ok=1;
		FOR(j,4) if (!(s[i][j]==c || s[i][j]=='T')) ok=0;
		if (ok) return 1;
	}
	FOR(i,4)
	{
		bool ok=1;
		FOR(j,4) if (!(s[j][i]==c || s[j][i]=='T')) ok=0;
		if (ok) return 1;
	}
	{
		bool ok=1;
		FOR(j,4) if (!(s[j][j]==c || s[j][j]=='T')) ok=0;
		if (ok) return 1;
	}
	{
		bool ok=1;
		FOR(j,4) if (!(s[j][3-j]==c || s[j][3-j]=='T')) ok=0;
		if (ok) return 1;
	}
	return 0;
}

int main()
{
	int te=0;
    tests
    {
		FOR(i,4) cin>>s[i];
		int ile=0;
		FOR(i,4)FOR(j,4) ile+=(s[i][j]=='.');
		if (check('X')) {printf("Case #%d: X won\n",++te);continue;}
		if (check('O')) {printf("Case #%d: O won\n",++te);continue;}
		if (ile) {printf("Case #%d: Game has not completed\n",++te);continue;}
		printf("Case #%d: Draw\n",++te);
	}
    
    return 0;
}
