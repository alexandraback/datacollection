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

ll mpow(ll a, ll b, ll MOD)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}

inline int rev(int x,int P){return mpow(x,P-2,P);}

int gauss(vector<vi> A,vi b,vi &x,int P)
{ 
	int m=A.sz,n=A[0].sz,k,r;
    vi q;
	for(k=0;k<min(m,n);k++)
    {
		int i,j;
		for(j=k;j<n;j++) for(i=k;i<m;i++) if (A[i][j]) goto found; break;
		found:
		if (j!=k) FOR(t,m) swap(A[t][j],A[t][k]);
		q.pb(j);
		if (i!=k){swap(A[i],A[k]);swap(b[i],b[k]);}
		REP(j,k+1,m-1) if (A[j][k])
        {
			int l=(A[j][k]*rev(A[k][k],P))%P;
			REP(i,k+1,n-1) A[j][i]=(P+A[j][i]-(l*A[k][i])%P)%P;
			b[j]=(P+b[j]-(l*b[k])%P)%P;
		}
	}
	r=k;x.clear();x.resize(n,0);
	REP(k,r,m-1) if (b[k]) return -1;
	REPD(k,r-1,0) 
    {
		int s=b[k];
		REP(j,k+1,r-1) s=(P+s-(A[k][j]*x[j])%P)%P;
		x[k]=(s*rev(A[k][k],P))%P;
	}
	REPD(k,r-1,0) swap(x[k],x[q[k]]);
	return n-r;
}


int main()
{

    vector<string> v;
    v.pb("ZERO");
	 v.pb("ONE");
	  v.pb("TWO");
	  v.pb("THREE");
	  v.pb("FOUR");
	   v.pb("FIVE");
	    v.pb("SIX");
		 v.pb("SEVEN");
		  v.pb("EIGHT");
		   v.pb("NINE");
	vector<vector<int> > z;
	vector<vector<int> > A(26,vector<int>(10,0));
	FOR(i,10)
	{
		FOR(j,v[i].sz) A[v[i][j]-'A'][i]++;
	}
    int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	string s;cin>>s;
    	
    	vector<int> x(10,0);
    	vector<int> y(26,0);
    	FOR(i,s.sz)
    	{
    		int d=s[i]-'A';
    		y[d]++;
    	}
    	int p=10007;
    	vector<vector<int> > AA=A;
    	//DBG(A);
    	//DBG(y);
    	gauss(AA,y,x,p);
    	//DBG(x);
    	s="";
    	FOR(c,10)FOR(j,x[c]) s+=char('0'+c);
    	printf("Case #%d: ",tnr+1);
    	cout<<s<<endl;
    }

	return 0;
}



