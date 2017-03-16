#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

ll st10[18];

int dig_cnt(ll v){
	int ans = 0;
	for(; v; v /= 10){
		ans++;
	}
	return ans;
}

ll get1(ll v){
	int d = dig_cnt(v);
	int lim = (d + 1) / 2, i;
	ll ans = 0;
	for(i = 0; i < lim; i++, v /= 10ll){
		ans = ans + (v % 10ll) * st10[i];
	}
	return ans;
}

ll get2(ll v){
	int d = dig_cnt(v);
	int lim = (d + 1) / 2, i;
	ll ans = 0;
	for(i = 0; i < lim; i++, v /= 10ll);
	for(; v; v /= 10ll){
		ans = ans * 10ll + v % 10ll;
	}
	return ans;
}

ll get_ans(ll v){
	if (v <= 10){
		return v;
	}
	int d = dig_cnt(v);
	ll ans = 10;
	for(int i = 2; i < d; i++){
		ans = ans + st10[(i + 1) / 2] - 1 + st10[i / 2];	
	}
	if (v == st10[d - 1]){
		return ans;
	}
	ll v1 = get1(v);
	ll v2 = get2(v);
	//cout << v1 << " " << v2 << endl;
	if (v1 > 0){
		ans += v1;
		if (v2 > 1){
			ans += v2;
		}
		return ans;
	}
	return get_ans(v - 1) + 1;
}

void solve(int t){
	int i;
	st10[0] = 1;
	for(i = 1; i < 18; i++){
		st10[i] = st10[i - 1] * 10ll;
	}
	ll v;
	cin >> v;
	ll ans = get_ans(v);
	cout << "Case #" << t << ": " << ans << endl;
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);	
	}
}
