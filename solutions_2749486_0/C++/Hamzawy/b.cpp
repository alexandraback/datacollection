/*
 * b.cpp
 *
 *  Created on: May 12, 2013
 *      Author: AhmedSamir
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef _MSC_VER
//#define rep(i,m) for(decltype(m) i=0;i<m;i++)
//#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
//#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

#define SMALL_INPUT
//#define LARGE_INPUT

int X, Y;

struct triple {
	int ind, x, y;
	triple(int ind, int x, int y) :
		ind(ind), x(x), y(y) {
	}
	triple() {
	}
	bool operator<(const triple& t) const {
		if (t.ind != ind)
			return ind < t.ind;
		if (t.x != x)
			return x < t.x;
		return y < t.y;
	}
};

struct ownhash {
	int operator()(const triple& t) const {
		return t.ind + t.x * 1001 + t.y * 1001 * 1001;
	}
	bool operator()(const triple& t1, const triple& t2) const {
		return t1.ind == t2.ind && t1.x == t2.x && t1.y == t2.y;
	}
};

//hash_map<triple, int, ownhash, ownhash> mem;
map<triple, int> mem;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int dp(int ind, int x, int y) {
	//	cerr << ind << endl;
	if (x == X && y == Y)
		return 0;
	if (ind > 100)
		return 1e9;
	triple t(ind, x, y);
	if (mem.find(t) != mem.end())
		return mem[t];
	int res = 1e9;
	//	for (int i = 0; i < 4; ++i)
	//		res = min(res, 1 + dp(ind + 1, x + dx[i] * ind, y + dy[i] * ind));
	res = min(res, 1 + dp(ind + 1, x + (x > X ? -ind : ind), y));
	res = min(res, 1 + dp(ind + 1, x, y + (y > Y ? -ind : ind)));
	return mem[t] = res;
}

//bool vis[510][1010][1010];
int main() {
	freopen("b.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("b-small-attempt0.in", "rt", stdin);
	freopen("b-small.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("b-large.in", "rt", stdin);
	freopen("b-large.txt", "wt", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	rep(T,tc) {
		scanf("%d%d", &X, &Y);
		int x = 0, y = 0, len = 0;
		string ans;
		while (x < X) {
			ans += "WE";
			x++;
			len++;
		}
		while (x > X) {
			ans += "EW";
			x--;
			len++;
		}
		while (y < Y) {
			ans += "SN";
			y++;
			len++;
		}
		while (y > Y) {
			ans += "NS";
			y--;
			len++;
		}
//		cout << len << endl;
		cout << "Case #" << T + 1 << ": " << ans << endl;
		//		mem.clear();
		//		cerr << dp(1, 0, 0) << endl;
		//		X += 500, Y += 500;
		//		vector<triple> q;
		//		q.push_back(triple(0, 500, 500));
		//		triple t;
		//		int len = 0;
		//		int ind = 0;
		//		while (!q.empty()) {
		//			int sz = q.size();
		//			while (ind < sz) {
		//				t = q[ind++];
		//				if (t.x == X && t.y == Y)
		//					goto out;
		//				for (int i = 0; i < 4; ++i){
		//					if(val())
		//					res = min(res, 1 + dp(ind + 1, x + dx[i] * ind, y + dy[i]
		//							* ind));
		//				}
		//			}
		//			len++;
		//		}
		//		out: ;
		//		cout << "";
#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
