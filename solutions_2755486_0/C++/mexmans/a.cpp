#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1005;
const int INF = (int)1e9;
int d[maxn],n[maxn],lf[maxn],rg[maxn],s[maxn],dd[maxn],dp[maxn],ds[maxn];
int tr[maxn * maxn * 16],mi[maxn * maxn * 16];
struct event {
	int lf,rg,d,s;
	event(int lf, int rg, int d, int s) : lf(lf), rg(rg), d(d), s(s) {}	
};
bool cmp(event e1, event e2) {
	return e1.d < e2.d;
}
void build(int l, int r, int idx) {
	tr[idx] = mi[idx] = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(l,m,2 * idx);
	build(m + 1,r,2 * idx + 1);
}
void push(int idx) {
	mi[2 * idx] = max(mi[2 * idx],mi[idx]);
	mi[2 * idx + 1] = max(mi[2 * idx + 1],mi[idx]);
	tr[2 * idx] = max(tr[2 * idx],mi[idx]);
	tr[2 * idx + 1] = max(tr[2 * idx + 1],mi[idx]);
}
void doit(int l, int r, int a, int b, int val, int idx) {
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		tr[idx] = max(tr[idx],val);
		mi[idx] = max(mi[idx],val);
	} else {
		int m = (l + r) >> 1;
		push(idx);
		doit(l,m,a,b,val,2 * idx);
		doit(m + 1,r,a,b,val,2 * idx + 1);
		tr[idx] = min(tr[2 * idx],tr[2 * idx + 1]);
	}
}
int getMin(int l, int r, int a, int b, int idx) {
	if (b < l || r < a) return INF;
	if (a <= l && r <= b) return tr[idx];
	push(idx);
	int m = (l + r) >> 1;
	return min(getMin(l,m,a,b,2 * idx),getMin(m + 1,r,a,b,2 * idx + 1));
}
void solve() {
	int N; cin >> N;
	vector<int> x;
	vector<event> events;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&lf[i],&rg[i],&s[i],&dd[i],&dp[i],&ds[i]);
		for (int j = 0; j < n[i]; j++) {
			events.pb(event(lf[i] * 2,rg[i] * 2,d[i],s[i]));
			x.pb(lf[i] * 2);
			x.pb(rg[i] * 2);
			d[i] += dd[i];
			s[i] += ds[i];
			lf[i] += dp[i];
			rg[i] += dp[i];
		}
	}
	sort(all(x));
	x.erase(unique(all(x)),x.end());
	vector<int> add;
	for(int i = 0; i < sz(x) - 1; i++) {
		add.pb((x[i + 1] + x[i]) / 2);
	}
	for (int i = 0; i < sz(add); i++) {
		x.pb(add[i]);
	}
	sort(all(x));
	build(0,sz(x) - 1,1);
	sort(all(events),cmp);
	int res = 0;
	for (int i = 0; i < sz(events);) {
		int j = i;
		while(j < sz(events) && events[i].d == events[j].d) j++;
		int k = i;
		while(k < j) {
			int ll = lower_bound(all(x),events[k].lf) - x.begin();
			int rr = lower_bound(all(x),events[k].rg) - x.begin();
			int ma = getMin(0,sz(x) - 1,ll,rr,1);
			if (ma < events[k].s) {
				res++;
			}
			k++;
		}
		while(i < j) {
			int ll = lower_bound(all(x),events[i].lf) - x.begin();
			int rr = lower_bound(all(x),events[i].rg) - x.begin();
			doit(0,sz(x) - 1,ll,rr,events[i].s,1);
			i++;
		}
	}
	printf("%d\n",res);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ",test);
		solve();
	}
	return 0;
}
