#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <memory.h>
#include <iterator>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
#define sz(m) ((m).size())
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0,i##e=n;i<i##e;++i)
#define fori(i,m) forn(i,sz(m))
#ifdef _MSC_VER
#define each(i,m) for(auto i=m.begin(),i##e=m.end();i!=i##e;++i)
#else
#define each(i,m) for(typeof(m.begin())i=m.begin(),i##e=m.end();i!=i##e;++i)
#endif
#define srt(s) sort(all(s))
#define maxup(a,b) a=max(a,b)
#define minup(a,b) a=min(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second


struct ev
{
	int d;
	int w, e;
	int s;
	ev() {}
	ev(int d, int w, int e, int s) : d(d), w(w), e(e), s(s) { }
	bool operator < (const ev& rhs) { return d < rhs.d; }
};

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int N;
		cin >> N;
		vector<int> d(N), n(N), w(N), e(N), s(N), delta_d(N), delta_p(N), delta_s(N);
		vector<ev> events;
		for (int i = 0; i < N; ++i) {
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
			for (int j = 0; j < n[i]; ++j) {
				events.pb(ev(d[i] + delta_d[i] * j, w[i] + delta_p[i] * j, e[i] + delta_p[i] * j, s[i] + delta_s[i] * j));
			}
		}
		srt(events);
		int pd = events[0].d;
		map<int, int> h, nh;
		int result = 0;
		fori(i, events) {
			ev& e = events[i];
			if (e.d != pd) {
				pd = e.d;
				h = nh;
			}
			bool ok = false;
			for (int j = e.w; j < e.e; ++j) {
				if (h.find(j) == h.end() || h[j] < e.s) {
					//cerr << "Attack at day " << e.d << " on [" << e.w << "," << e.e << "] succeed at " << j << endl;
					nh[j] = e.s;
					ok = true;
				}
			}
			if (ok) ++result;
		}
		cout << "Case #" << test << ": " << result << endl;
	}
}
