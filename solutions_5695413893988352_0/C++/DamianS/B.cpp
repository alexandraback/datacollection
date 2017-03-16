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
vector<pair<ll,ll> > v;

ll toll(string z)
{
	ll wyn=0;
	FOR(i,z.sz) wyn=wyn*10+z[i]-'0';
	return wyn;
}

void go(string x,string y,int i,int rel)
{
	if (i==n)
	{
		ll X=0;
		ll Y=0;
		FOR(j,n) X=X*10+x[j]-'0';
		FOR(j,n) Y=Y*10+y[j]-'0';
		v.pb(mp(X,Y));
		return;
	}
    		if (rel==0)
    		{
    			FOR(cx,10)FOR(cy,10)
    			{
    				if (x[i]!='?' && x[i]!='0'+cx) continue;
    				if (y[i]!='?' && y[i]!='0'+cy) continue;
    				string xx=x;
    				string yy=y;
    				xx[i]='0'+cx;
    				yy[i]='0'+cy;
    				if (cx<cy)
    				{
    					go(xx,yy,i+1,-1);
    				}
    				else if (cx>cy)
    				{
    					go(xx,yy,i+1,1);
    				}
    				else go(xx,yy,i+1,0);
    			}
    		}
    		else if (rel==-1)
    		{
    			if (x[i]=='?' && y[i]=='?')
    			{
    				x[i]='9';
    				y[i]='0';
    			}
    			else if (x[i]!='?' && y[i]=='?')
    			{
    				y[i]='0';
    			}
    			else if (x[i]=='?' && y[i]!='?')
    			{
    				x[i]='9';
    			}
    			else
    			{
    				
    			}
    			go(x,y,i+1,rel);
    		}
    		else
    		{
    			if (x[i]=='?' && y[i]=='?')
    			{
    				x[i]='0';
    				y[i]='9';
    			}
    			else if (x[i]!='?' && y[i]=='?')
    			{
    				y[i]='9';
    			}
    			else if (x[i]=='?' && y[i]!='?')
    			{
    				x[i]='0';
    			}
    			else
    			{
    				
    			}
    			go(x,y,i+1,rel);
    		}
    	
}


int main()
{
    int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	string x,y;
    	cin>>x>>y;
    	n=x.sz;
    	v.clear();
    	go(x,y,0,0);
    	pair<ll,ll> best=v[0];
    	FOR(i,v.sz)
    	{
    		if (abs(v[i].fi-v[i].se)<abs(best.fi-best.se)) best=v[i];
    		else if (abs(v[i].fi-v[i].se)==abs(best.fi-best.se) && v[i].fi<best.fi) best=v[i];
    		else if (abs(v[i].fi-v[i].se)==abs(best.fi-best.se) && v[i].fi==best.fi && v[i].se<best.se) best=v[i];
    	}
    	//DBG(best);
    	printf("Case #%d: ",tnr+1);
    	ll X[2]={best.fi,best.se};
    	FOR(j,2)
    	{
    		vi z;
	    	FOR(i,n)
	    	{
	    		z.pb(X[j]%10);
	    		X[j]/=10;
	    	}
	    	reverse(ALL(z));
	    	FOR(i,n) cout<<z[i];
	    	if (j==0) cout<<" ";
	    }
	    cout<<endl;

    }

	return 0;
}


