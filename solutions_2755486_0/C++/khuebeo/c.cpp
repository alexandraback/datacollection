//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(ll i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(ll i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(ll i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <ll, ll> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxtribe 1111 
#define oo 1000111000111000LL

struct _tribe {
	ll d, n, w, e, s, delta_d, delta_p, delta_s;
} tribe[maxtribe];

struct _attack {
	ll d,w,e,s;
};

struct _tree {
	ll left,right,item,wait;
} tree[50111000];

int cnt;

int NEW() {
	++cnt;
	tree[cnt].left=tree[cnt].right=tree[cnt].item=tree[cnt].wait=0;
	return cnt;
}

void createChild(int x) {
	if(tree[x].left==0) tree[x].left=NEW();
	if(tree[x].right==0) tree[x].right=NEW();
	
}

void updateChild(int x) {
	if(tree[x].wait!=0) {
		tree[tree[x].left].item=max(tree[tree[x].left].item,tree[x].wait);
		tree[tree[x].left].wait=max(tree[tree[x].left].wait,tree[x].wait);
		tree[tree[x].right].item=max(tree[tree[x].right].item,tree[x].wait);
		tree[tree[x].right].wait=max(tree[tree[x].right].wait,tree[x].wait);
		tree[x].wait=0;	
	}
}

ll query(ll x,ll y,ll l,ll r,ll vt) {
	if(y<l || r<x) return oo;
	if(x<=l && r<=y) return tree[vt].item;
	createChild(vt);
	updateChild(vt);
	return min(query(x,y,l,(l+r)/2,tree[vt].left),query(x,y,(l+r)/2+1,r,tree[vt].right));
}

ll QU(ll x,ll y) {
	
	x+=oo;
	y+=oo;
	y--;
	
	return query(x,y,1,2*oo,1);
}

void update(ll x,ll y,ll s,ll l,ll r,ll vt) {
	if(y<l || r<x) return;
	
	
	if(x<=l && r<=y) {
		tree[vt].wait=max(tree[vt].wait,s);
		tree[vt].item=max(tree[vt].item,s);
		return;
	}
	createChild(vt);
	updateChild(vt);
	update(x,y,s,l,(l+r)/2,tree[vt].left);
	update(x,y,s,(l+r)/2+1,r,tree[vt].right);
	
	tree[vt].item=min(tree[tree[vt].left].item,tree[tree[vt].right].item);
}

void UP(ll x,ll y,ll s) {
	x+=oo;
	y+=oo;
	y--;
	update(x,y,s,1,2*oo,1);
}


bool cmp(_attack a1,_attack a2) {
	return a1.d<a2.d;
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	ll ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		int n;
		cin >> n;
		FOR(i,1,n) cin >> tribe[i].d >> tribe[i].n >> tribe[i].w >> tribe[i].e >> tribe[i].s >> tribe[i].delta_d >> tribe[i].delta_p >> tribe[i].delta_s;
		
		vector<_attack> list;		
		FOR(i,1,n) {
			REP(j,tribe[i].n) {
				_attack attack;
				attack.d=tribe[i].d+j*tribe[i].delta_d;
				attack.w=tribe[i].w+j*tribe[i].delta_p;
				attack.e=tribe[i].e+j*tribe[i].delta_p;
				attack.s=tribe[i].s+j*tribe[i].delta_s;
				
				list.PB(attack);
			}
		}		
		sort(list.begin(),list.end(),cmp);
		
		/*
		REP(i,list.size()) {
			DEBUG(list[i].d);
			DEBUG(list[i].w);
			DEBUG(list[i].e);
			DEBUG(list[i].s);
			cerr << endl;
		}
		*/
		cnt=0;NEW();
		
		ll i=0,res=0;
		while(i<list.size()) {
			ll j=i;
			while(j+1<list.size() && list[i].d==list[j+1].d) j++;
			
			FOR(k,i,j) {
				ll t=QU(list[k].w,list[k].e);
				if(t<list[k].s) res++;
				
			}
			
			FOR(k,i,j) UP(list[k].w,list[k].e,list[k].s);
			
			i=j+1;
		}
		
		cout << "Case #" << test <<": " << res << endl;
	}
}
	
