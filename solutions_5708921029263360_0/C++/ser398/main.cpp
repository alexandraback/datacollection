#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forab(i,a,b) for(int i=(int)a;i<(int)b;i++) //WARNING!! long long
#define mp make_pair
#define pb push_back
#define all(a,n) a,a+n
#define dprintf if(DEBUG)printf
#define dputs if(DEBUG)puts
#define dassert if(DEBUG)assert
#define fi first
#define se second
#define j0 jqwerty
#define j1 jasdf
#define i0 iqwerty
#define i1 iasdf
#define sq(x) (x)*(x)

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int DEBUG=1;

int a[10][10];
int b[10][10];
int c[10][10];
int ans;
int j, p, s, k;
vector<int> q,w,e;
vector<int> aq, aw, ae;
void gen(int f, int g, int h){
	if(ans < q.size()){
		ans = q.size();
		aq = q;
		aw = w;
		ae = e;
	}
	if(h == s){
		return gen(f, g + 1, 0);
	}
	if(g == p){
		return gen(f + 1, 0, 0);
	}
	if(f == j){
		return;
	}
	gen(f, g, h + 1);

	bool fl = false;
	a[f][g]++;
	if(a[f][g] > k) fl = 1;
	b[g][h]++;
	if(b[g][h] > k) fl = 1;
	c[h][f]++;
	if(c[h][f] > k) fl = 1;
	q.pb(f + 1);
	w.pb(g + 1);
	e.pb(h + 1);
	if(!fl)gen(f, g, h + 1);
	
	a[f][g]--;
	b[g][h]--;
	c[h][f]--;
	q.pop_back();
	w.pop_back();
	e.pop_back();
	
}
void solve(){
	cin >> j >> p >> s >> k;
	ans = 0;
	memset(a, 0,sizeof a);
	q.clear();
	w.clear();
	e.clear();
	aq.clear();
	aw.clear();
	ae.clear();
	
	gen(0,0,0);
	cout << ans << endl;
	forn(i, ans){
		cout << aq[i] << " " << aw[i] << " "<< ae[i] << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	forn(i, t){
		cerr << i << endl;
		printf("Case #%d: ", i + 1);
		solve();
		
	}
	return 0;
}
