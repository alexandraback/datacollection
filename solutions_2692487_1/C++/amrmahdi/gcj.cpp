///*
// * gcj.cpp
// *
// *  Created on: May 4, 2013
// *      Author: amrmahdi
// */
//
//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <queue>
//#include <string.h>
//#define rep(x,n) for(int x=0;x<n;++x)
//#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
//#define repi(x, s, e) for(int x=(s); x<(int)(e); ++x)
//#define mem(a, b) memset(a, b, sizeof(a))
//
//#define mp(x,y) make_pair(x,y)
//#define getBit(code, i) (code & (1LL << i))
//#define setBit(code, i) (code | (1LL << i))
//#define xetBit(code, i) (code & ~(1LL << i))
//#define PI acos(-1.0)
//#define oo (int)10e7
//#define rd(x) scanf("%d", &x)
//#define rdfile(x) freopen(x, "r", stdin)
//#define wtfile(x) freopen(x, "w", stdout)
//using namespace std;
//
//#define CLOCKS_PER_SEC 1000000
//#define negmod(x, mod) ((x + mod) % mod)
//
//long long a, n, os[105];
//
//int main() {
//
//	rdfile("in.txt");
////	wtfile("out.txt");
//	int cases;
//	cin >> cases;
//	repi(css,1, cases+1) {
//		cin >> a >> n;
//		rep(i, n) {
//			cin >> os[i];
//		}
//		sort(os, os + n);
//		int res = 0;
//
//		rep(i, n) {
//			if(a > os[i]) {
//				a += os[i];
//			} else {
//				if(a - 1 == 0) {
//					++res;
//					continue;
//				}
//				long long add = os[i] / (a - 1);
//				res += add;
//				a += (a - 1) * add;
//			}
//		}
//
//		printf("Case #%d: %d\n", css, res);
//	}
//	return 0;
//}
