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


vector<vector<int> > v1;
int n1,n2;
vector<int> sk2;
vector<bool> odw1;

void czysc(int newn1, int newn2)
{n1=newn1;n2=newn2;
v1.clear();v1.resize(n1);}

inline void dod_kr(int a,int b)
{v1[a].pb(b);}

bool augment(int k1)
{
	if (k1==-1) return 1;
	if (odw1[k1]) return 0;
	odw1[k1]=1;
	FOR(i,v1[k1].sz)
	if (augment(sk2[v1[k1][i]]))
	{
		sk2[v1[k1][i]]=k1;
		return 1;
	}
	return 0;
}

int maxskoj()
{
	sk2.clear();sk2.resize(n2,-1);
	odw1.clear();odw1.resize(n1);
	int w=0;
	FOR(i,n1)
	{
		fill(odw1.begin(),odw1.end(),0);
		w+=augment(i);
	}
	return w;
}

vector<string> p,q;

int getp(string s)
{
	return lower_bound(ALL(p),s)-p.begin();
}

int getq(string s)
{
	return lower_bound(ALL(q),s)-q.begin();
}

int main()
{
    int te;
	cin>>te;
	
	
    FOR(tnr,te)
    {
    	int m;cin>>m;
    	vector<pair<string,string> > e;
    	p.clear();
    	q.clear();
    	FOR(i,m)
    	{
    		string s1,s2;cin>>s1>>s2;
    		p.pb(s1);
    		q.pb(s2);
    		e.pb(mp(s1,s2));
    	}
    	sort(ALL(p));un(p);
    	sort(ALL(q));un(q);
    	czysc(p.sz,q.sz);
    	FOR(i,m) dod_kr(getp(e[i].fi),getq(e[i].se));
    	
    	printf("Case #%d: ",tnr+1);
    	cout<<m-((int)p.sz+q.sz-maxskoj())<<endl;

    }

	return 0;
}


