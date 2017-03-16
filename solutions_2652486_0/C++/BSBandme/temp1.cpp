/*
 * temp.cpp
 *
 *  Created on: 2012-7-18
 *      Author: BSBandme
 */
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
#include <sstream>

using namespace std;

#define mpr make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans =  a > b ? a : b;
	if(c != -1234567) ans = max1(ans, c);
	if(d != -1234567) ans = max1(ans, d);
	return ans;
}
template <class T> inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
	T ans = a < b ? a : b;
	if(c != -1234567) ans = min(ans, c);
	if(d != -1234567) ans = min(ans, d);
	return ans;
}
template <class T> inline T gcd1(T a, T b) {
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return gcd1(b, a % b);
}
template <class T> inline T lb(T num) {return num & (-num); }
inline int jud(double a, double b){
	if(abs1(a - b) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	if(na == 1) return 0;
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
		if(f_small && jud(*(a + be), val) == 1 && be != 0) be--;
		if(!f_small && jud(*(a + be), val) == -1 && be != na - 1) be++;
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
		if(!f_small && jud(*(a + be), val) == -1 && be != 0) be--;
		if(f_small && jud(*(a + be), val) == 1 && be != na - 1) be++;
	}
	return be;
}
inline int bitnum(ull nValue){
    nValue = ((0xaaaaaaaaaaaaaaaaull & nValue)>>1) + (0x5555555555555555ull & nValue);
    nValue = ((0xccccccccccccccccull & nValue)>>2) + (0x3333333333333333ull & nValue);
    nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue)>>4) + (0x0f0f0f0f0f0f0f0full & nValue);
    nValue = ((0xff00ff00ff00ff00ull & nValue)>>8) + (0x00ff00ff00ff00ffull & nValue);
    nValue = ((0xffff0000ffff0000ull & nValue)>>16) + (0x0000ffff0000ffffull & nValue);
    nValue = ((0xffffffff00000000ull & nValue)>>32) + (0x00000000ffffffffull & nValue);
	return nValue;
}
long long pow(long long n, long long m, long long mod = 0){
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


//.........................mi.......feng.......xian.......wai.......jin.......zhi.......challenge...............................................


int f[6];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, ncase, l, r, k;
	scanf("%d", &n);
	scanf("%d%d%d%d", &ncase, &l, &r, &k);
	printf("Case #1:\n");
	for(int i1 = 0; i1 < ncase; i1++){
		int arr[10];
		for(int i = 0; i < k; i++) scanf("%d", arr + i);
		memset(f, 0, sizeof(f));
		for(int i = 0; i < k; i++){
			int k = arr[i], ransum = 0;
			ransum = 0; while(k % 3 == 0) ransum++, k /= 3;
			f[3] = max1(f[3], ransum);
			ransum = 0;while(k % 5 == 0) ransum++, k /= 5;
			f[5] = max1(f[5], ransum);
			ransum = 0; while(k % 2 == 0) ransum++, k /= 2;
			f[2] = max1(f[2], ransum);
		}
		for(int i = 0; i < f[3]; i++) printf("3");
		for(int j = 0; j < f[5]; j++) printf("5");
		int sum = 3 - f[3] - f[5];
		if(f[3] + f[5] >= 2){
			if(f[2] == 2) printf("4");
			else printf("2");
		}else {
			for(int i = 1; i <= sum; i++){
				if(f[2] >= i * 2) printf("4");
				else printf("2");
			}
		}
		printf("\n");
	}

	return 0;
}



