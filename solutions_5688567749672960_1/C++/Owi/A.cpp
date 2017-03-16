#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

const int MAXN = 511111;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const LL MAXL = (LL)(0x7fffffffffffffff);
const int MAXI = 0x7fffffff;

LL rvs(LL a, LL &d){
	d = 0;
	if(a == 0) return 0;
	LL x = 0;
	while(a > 0){
		x = x * 10 + a % 10;
		a /= 10;
		d++;
	}
	return x;
}

LL hf(LL a, LL &s, LL d){
	LL r = 0, t = 0, x = 1;
	while(t < d / 2){
		x *= 10;
		t++;
	}
	r = a / x;
	s = r - 1;
	return  r;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("outputA.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for(int cases = 1; cases <= T; cases++){
		LL n;
		cin >> n;
		LL x = 1;
		LL ans = 1, d = 0, t = 0, tt = 0, s = 0;
		LL q = 10, w = 9, r = rvs(n, d);
		LL h = hf(n, s, d);
		LL xxx;
		h = rvs(h, xxx);
		s = rvs(s, xxx);
		vector<LL> res;
		if(x == n) res.push_back(1);
		for(int i = 0; i < 100; i++){
			if(res.empty()){
				res.push_back(n - x + ans);
			}
			else{
				res[0] = min(res[0], n - x + ans);
			}
			if(!(t & 1)){
				LL y = q + w, dd, ry = rvs(y, dd);
				if(ry > n){
					y = q + h;
				}
				ry = rvs(y, dd);
				if(ry > n){
					y = q + s;
				}
				if(y > n) break;
				ans += y - x;
				x = y;
				q *= 10;
				if(tt & 1) w = w * 10 + 9;
				tt++;
			}
			else{
				LL dd = 0, rr = rvs(x, dd);
				if(rr <= x) break;
				if(rr > n) break;
				x = rr;
				ans++;
			}
			t++;
		}
		printf("Case #%d: %lld\n", cases, res[0]);
	}
}