#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_tree;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define INF 1000000001
#define LINF 1000000000000000001ll
#define PB push_back
#define EPS 1e-7
#define X first
#define Y second
#define MP make_pair
#define ITER(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
/*
 int t, lk, ll, ls;
 string k, l;
 int maxban = 0;
 int a[100];
 int all = 0;
 void upd(string s) {
 int cnt = 0;
 FOR(i,0,s.size())
 if (s.substr(i, ll) == l)
 cnt++;
 maxban = max(cnt, maxban);
 a[cnt]++;
 all++;
 }
 void func(string s) {
 if (s.size() == ls) {
 upd(s);
 return;
 }
 FOR(i,0,k.size())
 func(s + k[i]);
 }
 int main() {
 ios::sync_with_stdio(0);
 freopen("A.in","r",stdin);	freopen("A.out","w",stdout);

 cin >> t;

 cout << fixed;
 cout << setprecision(6);
 FOR(ttt,0,t)
 {
 cin >> lk >> ll >> ls >> k >> l;
 FILL(a, 0);
 all = 0;
 maxban = 0;
 func("");
 double ans = 0;
 FOR(i,0,100)
 ans += (i * a[i] + 0.0) / all;
 ans=maxban-ans;
 cout << "Case #" << ttt + 1 << ": " << ans << "\n";
 }
 return 0;
 }

 */

VI mask[47];
void init() {
	mask[0].PB(0);
	FOR(i,1,31)
	{
		FOR(ad,(i+1)/2,i+1)
		{
			FOR(j,0,mask[i-ad].size())
				if ((mask[i - ad][j] & (1 << ad)) == 0)
					mask[i].PB(mask[i - ad][j] | (1 << ad));
		}
	}
}
int t, c, d, v;
map<int, int> mapp, nmap;
bool fre[47];
int ad(int oldmask, int newmask) {
	int cn = 0;
	FOR(i,0,31)
	{
		int b1 = (oldmask & (1 << i));
		int b2 = (newmask & (1 << i));
		if (!b1 && b2)
			cn += fre[i] ? 0 : 1;
	}

	return cn;
}
bool ok(int m) {
	FOR(i,0,v+1)
		if (fre[i])
			m |= (1 << i);
	FOR(i,1,v+1)
	{
		bool f = 0;
		FOR(j,0,mask[i].size())
			if ((mask[i][j] & (m)) == mask[i][j])
				f = 1;
		if (!f)
			return 0;
	}

	return 1;
}
int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> t;
	init();
	FOR(ttt,0,t)
	{
		cin >> c >> d >> v;
		FILL(fre, 0);
		FOR(i,0,d)
		{
			int x;
			cin >> x;
			fre[x] = 1;
		}
		int ans = INF;
		int r = 0;
		FOR(mas,0,1<<17)
		{
			if (ok(mas)) {
				int v = 0;
				FOR(i,0,17)
				{
					if (mas & (1 << i))
						v += fre[i] ? 0 : 1;
				}
				ans = min(ans, v);
				if (v < ans) {
					ans = v;
					r = mas;
				}
			}

		}
		//	cerr<<r;
		cout << "Case #" << ttt + 1 << ": " << ans << "\n";
	}
	return 0;
}
