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

int hk;
vector<pair<ll,ll> > v;
int n;

int main()
{
	int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	hk=0;
    	v.clear();
    	cin>>n;
    	FOR(i,n)
    	{
    		int D,H,M;
    		cin>>D>>H>>M;
    		FOR(j,H)
    		{
    			v.pb(mp(M+j,D));
    			hk++;
    		}
    	}
    	vector<ll> lewo,prawo;
    	FOR(i,hk) lewo.pb((360-v[i].se)*v[i].fi);
    	FOR(i,hk)
    	{
    		REP(k,1,3*hk+4) prawo.pb((360-v[i].se)*v[i].fi+k*360*v[i].fi);
    	}
    	sort(ALL(lewo));
    	sort(ALL(prawo));
    	int best=1<<20;
    	vector<ll> prob=prawo;FOR(i,lewo.sz) prob.pb(lewo[i]);
    	FOR(j,prob.sz)
    	{
    		ll P=prob[j];
    		int ile=0;
    		FOR(i,lewo.sz) if (lewo[i]>=P) ile++;
    		FOR(i,prawo.sz) if (prawo[i]<P) ile++;
    		REMIN(best,ile);
    	}
    	printf("Case #%d: %d\n",tnr+1,best);
    }

	return 0;
}


