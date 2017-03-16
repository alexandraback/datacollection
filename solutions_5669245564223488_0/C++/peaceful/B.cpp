//#include <algorithm>
//#include <numeric>
//#include <cmath>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
//#include <iostream>
//#include <sstream>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <string>
//#include <vector>
//#include <stdio.h>
//typedef long long ll;
//#define mset(a, val) memset(a, val, sizeof(a))
//#define up(i, s, t) for (ll i = (s); i < (t); i += 1)
//#define down(i, s, t) for (ll i = (s); i > (t); i -= 1)
//#define rd1(a) scanf("%d", &a)
//#define rd2(a, b) scanf("%d %d", &a, &b)
//#define rd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
//#define rd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
//#define pii pair<int, int>
//
//using namespace std;
//const int MAXINT = 0x6fffffff;
//const ll MAXLONG = (ll) 1 << 60;
//const int MAXN = 105;
//const int MOD = 1e9 + 7;
//
//string str[MAXN];
//int n;
//ll res;
//int vis[MAXN];
//int sor[MAXN];
//
////void dfs(int idx, int last) {
////	if (idx >= n) {
////		res ++;
////		res %= MOD;
////		return;
////	}
////		
////	up(i, 0, n) {
////		if (vis[i]) continue;
////
////		if (last == -1 || ) {
////		}
////	}
////}
//
//bool cmp (int a, int b) {
//	return sor[a] < sor[b];
//}
//
//bool check() {
//	
//	string s;
//	up(i, 0, n) {
//		int sid = sor[i];
//		s += str[sid];
//	}
//
//	int vis[30];
//	mset(vis, 0);
//	bool ok = true;
//		
//		
//	int len = s.length();
//
//	int idx = 0;
//	while (idx < len) {
//		int nxt = idx + 1;
//		char ch = s[idx];
//		if (vis[ch - 'a']) {
//			ok = false;
//			goto here;
//		}
//		vis[ch - 'a'] = true;
//
//		while (nxt < len && s[nxt] == ch) {
//			nxt ++;
//		}
//
//		idx = nxt;
//	}
//
//	
//here:
//	return ok;
//}
//
//int main () {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
//
//	int t;
//	cin >> t;
//	up(ca, 1, t + 1) {
//		printf("Case #%lld: ", ca);
//		
//		cin >> n;
//		
//
//		up(i, 0, n) {
//			cin >> str[i];
//			sor[i] = i;
//		}
//
//		ll res = 0;
//		do {
//			bool ret = check();
//			if (ret) {
//				res ++;
//				res %= MOD;
//			}
//		} while (next_permutation(sor, sor + n));
//
//		printf("%lld\n", res);
//	}
//    return 0;
//}