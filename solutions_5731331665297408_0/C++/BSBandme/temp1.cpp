/*
 * temp.cpp
 *
 *  Created on: 2012-7-18
 *      Author: BSBandme
 */
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}

// f_lb == 1代表返回相同的一串的左边界，f_small == 1代表返回如果没有寻找的值返回小的数
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define  MOD 1000000007
template <class t1, class t2>
inline void add(t1 &a, t2 b) {
	a += b;
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
}

#define debug
//.........................mi.......feng......xian.......xia.......jin.......zhi.......hack...............................................

const int maxn = 55;
struct node {
	vi to;
	int zip;
	bool operator < (const node &a) const {
		 return zip < a.zip;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
	#ifdef debug //......................................................................................................
	freopen("input.txt", "r", stdin);
	#endif //...........................................................................................................
	int ncase;
	scanf("%d", &ncase);
	for(int i1 = 0; i1 < ncase; i1++) {
		int n, m;
		scanf("%d%d", &n, &m);
		node orig[maxn];
		for(int i = 0; i < n; i++) scanf("%d", &orig[i].zip);
		bool mp[maxn][maxn];
		memset(mp, 0, sizeof(mp));
		for(int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			orig[a].to.push_back(b);
			orig[b].to.push_back(a);
			mp[a][b] = mp[b][a] = 1;
		}
		int rno = 0;
		for(int i = 0; i < n; i++) if(orig[i].zip < orig[rno].zip)
			rno = i;
		vi ans;
		vector <pii> can;
		int st[maxn], lst = 0;
		int f[maxn] = {0};
		f[rno] = 1;
		can.push_back(mpr(orig[rno].zip, rno));
		int rf[maxn] = {0};
		for(int i = 0; i < n; i++) {
			sort(can.begin(), can.end());
			for(int j = 0; j < (int)can.size(); j++) {
				int no = can[j].second;
				int rlst = lst;
				while(rlst && mp[st[rlst - 1]][no] == 0) {
					rlst--;
				}
				bool flag = 1;
				int temprf[maxn];
				memcpy(temprf, rf, sizeof(rf));
				for(int k = rlst; k < lst; k++) temprf[st[k]] = 1;
				if(rlst) {
					int q[maxn], lq = 0, rq = 0, rrflag[maxn] = {0};
					for(int k = 0; k < n; k++) if(f[k] == 2 && temprf[k] == 0) {
						q[rq++] = k;
						rrflag[k] = 1;
					}
					for(; lq < rq; lq++) {
						int no = q[lq];
						for(int k = 0; k < (int)orig[no].to.size(); k++) {
							int rno = orig[no].to[k];
							if(rrflag[rno] == 0 && temprf[rno] == 0) {
								rrflag[rno] = 1;
								q[rq++] = rno;
							}
						}
					}
					for(int k = 0; k < n; k++) if(temprf[k] == 0 && rrflag[k] == 0)
						flag = 0;
					if (!flag) continue;
				}
				memcpy(rf, temprf, sizeof(temprf));
				lst = rlst;
				ans.push_back(can[j].first);
				f[no] = 2;
				for (int k = 0; k < (int) orig[no].to.size(); k++)
					if (f[orig[no].to[k]] == 0) {
						int tno = orig[no].to[k];
						f[tno] = 1;
						can.push_back(mpr(orig[tno].zip, tno));
					}
				st[lst++] = no;
				can.erase(can.begin() + j);
				break;
			}
		}
		printf("Case #%d: ", i1 + 1);
		if(n == 1) printf("%d", orig[0].zip);
		else for(int i = 0; i < n; i++) printf("%d", ans[i]);
		printf("\n");
	}

    return 0;
}



