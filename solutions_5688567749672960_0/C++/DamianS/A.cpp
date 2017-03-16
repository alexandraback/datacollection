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
#include <complex>
#include <ctime>
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

int n;

int rev(int x)
{
	int y=0;
	while(x>0)
	{
		int c=x%10;
		x/=10;
		y=y*10+c;
	}
	return y;
}
#define N (1<<20)
#define INF (1<<22)
int dist[1<<20];

int gobfs()
{
	FOR(i,N) dist[i]=INF;
	dist[1]=1;
	queue<int> Q;
	Q.push(1);
	while(Q.sz)
	{
		int u=Q.front();Q.pop();
		if (u==n) return dist[u];
		int kr[]={u+1,rev(u)};
		FOR(j,2)
		{
			int ne=kr[j];
			if (ne>=N) continue;
			if (dist[ne]!=INF) continue;
			dist[ne]=dist[u]+1;
			Q.push(ne);
		}
	}
	return -1;
}

int main()
{
	int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	cin>>n;
    	printf("Case #%d: ",tnr+1);
    	cout<<gobfs()<<endl;
    }

	return 0;
}


