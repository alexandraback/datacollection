/*
 TASK:
 LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <bitset>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <valarray>
//#include "vc.h"
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp {

	enum {
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO = 0;
const long double INF = 1 / ZERO, EPSILON = 1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)

struct state {
	int st, en, s;
};
struct node {
	int mn, val;
	node *lf, *rt;

	node() {
		memset(this, 0, sizeof *this);
	}
}*root;
void update(node *&n, int val) {
	if (!n)
		n = new node;

	n->val = max(n->val, val);
	n->mn = max(n->mn, val);
}
void update(node *&n, int ns, int ne, int qs, int qe, int val) {
	if (!n)
		n = new node;
	if (ns > qe || ne < qs)
		return;
	if (ns >= qs && ne <= qe) {
		n->mn = max(n->mn, val);
		n->val = val;
		return;
	}
	if (n->val) {
		update(n->lf, n->val);
		update(n->rt, n->val);
	}
	int md = ns + ((ne - ns) >> 1);
	update(n->lf, ns, md, qs, qe, val);
	update(n->rt, md + 1, ne, qs, qe, val);
	n->mn = min(n->lf->mn, n->rt->mn);
}

int query(node *&n, int ns, int ne, int qs, int qe) {

	if (!n)
		n = new node;
	if (ns > qe || ne < qs)
		return INT_MAX;
	if (ns >= qs && ne <= qe) {
		return n->mn;
	}
	if (n->val) {
		update(n->lf, n->val);
		update(n->rt, n->val);
	}
	int md = ns + ((ne - ns) >> 1);
	return min(query(n->lf,ns,md,qs,qe),query(n->rt,md+1,ne,qs,qe));
}

int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in", "rt", stdin);
	freopen("1.out", "wt", stdout);
#endif
	int t, tt = 1;
	cin >> t;
	while (t--) {
		int res = 0;
		map<int, vector<state> > attacks;
		int n;
		cin >> n;
		int mn = INT_MAX, mx = INT_MIN;
		while (n--) {
			int d, m, st, en, s, dd, dp, ds;
			cin >> d >> m >> st >> en >> s >> dd >> dp >> ds;
			while (m--) {
				state ss = { st * 2, en * 2, s };
				attacks[d].push_back(ss);
				mn = min(mn, st * 2);
				mx = max(mx, en * 2);
				st += dp;
				en += dp;
				s += ds;
				d += dd;
			}
		}
		root=new node;
		for(map<int, vector<state> >::iterator it=attacks.begin();it!=attacks.end();it++)
		{
			vector<state> &v=it->second;
			rep(i,sz(v))
			{
				res+=query(root,mn,mx,v[i].st,v[i].en)<v[i].s;
			}
			rep(i,sz(v))
				update(root,mn,mx,v[i].st,v[i].en,v[i].s);
		}
		cout << "Case #" << tt++ << ": " << res << endl;
	}
	return 0;
}
