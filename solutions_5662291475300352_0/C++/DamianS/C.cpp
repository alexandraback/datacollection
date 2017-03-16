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
int m[11],d[11];
int n;

int main()
{
	int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	hk=0;
    	cin>>n;
    	FOR(i,n)
    	{
    		int D,H,M;
    		cin>>D>>H>>M;
    		FOR(j,H)
    		{
    			m[hk]=M+j;
    			d[hk]=D;
    			hk++;
    		}
    	}
    	if (hk<=1) 
		{
			printf("Case #%d: 0\n",tnr+1);
			continue;
		}
		vector<pair<ll,ll> > v;
		FOR(i,2)
		{
			v.pb(mp((360-d[i])*1LL*m[i],i));
			v.pb(mp((720-d[i])*1LL*m[i],i));
		}
		sort(ALL(v));
		if (v[0].se!=v[1].se && v[1].fi<v[2].fi) printf("Case #%d: 0\n",tnr+1);
    	else printf("Case #%d: 1\n",tnr+1);
    }

	return 0;
}


