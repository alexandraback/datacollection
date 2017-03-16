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
int n,m;
string s[111];
int kol[111];
int g[111][111];

bool check(vi stos,vi martwe)
{
	queue<int> Q;
	bool odw[111]={0};
	FOR(i,stos.sz) {Q.push(stos[i]);odw[stos[i]]=1;}
	
	while(Q.sz)
	{
		int u=Q.front();Q.pop();
		odw[u]=1;
		FOR(i,n) if (!martwe[i] && !odw[i] && g[u][i])
		{
			Q.push(i);
			odw[i]=1;
		}
	}
	FOR(i,n) if (!martwe[i] && !odw[i]) return 0;
	return 1;
}

vi wynik;

bool go(vi stos,vi wyn,vi martwe)
{
	//DBG(stos);
	//DBG(wyn);
	//DBG(martwe);
	if (wyn.sz==n)
	{
		wynik=wyn;
		return 1;
	}
	if (!check(stos,martwe)) return 0;
	//DBG("checkok");
	bool odw[111]={0};
	FOR(i,wyn.sz) odw[wyn[i]]=1;
	FOR(i,n)
	{
		int u=kol[i];
		if (odw[u]) continue;
		vi stos1=stos,wyn1=wyn,martwe1=martwe;
		while(1)
		{
			if (stos1.sz==0) break;
			if (g[stos1.back()][u])
			{
				stos1.pb(u);
				wyn1.pb(u);
				if (go(stos1,wyn1,martwe1)) return 1;
				else break;
			}
			else 
			{
				martwe1[stos1.back()]=1;
				stos1.pop_back();
			}
		}
	}
	DBG("ZLEEEEEEE");
	return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int te;cin>>te;
    REP(tes,1,te)
    {
		cin>>n>>m;
		vector<pair<string,int> > v;
		FOR(i,n)
		{
			cin>>s[i];
			v.pb(mp(s[i],i));
		}
		FOR(i,n+1)FOR(j,n+1) g[i][j]=0;
		FOR(i,m)
		{
			int x,y;cin>>x>>y;
			x--;y--;
			g[x][y]=1;
			g[y][x]=1;
		}
		
		sort(ALL(v));
		FOR(i,n)kol[i]=v[i].se;
		//DBG(vi(kol,kol+n));
		FOR(i,n)
		{
			int u=kol[i];
			vi stos(1,u),wyn(1,u),martwe(n,0);
			if (go(stos,wyn,martwe)) break;
		}
		//DBG(wynik);
		string S;
		FOR(i,n) S+=s[wynik[i]];
		printf("Case #%d: %s\n",tes,S.c_str());
	}
    
    return 0;
}
