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

LL rvs(LL a){
	if(a == 0) return 0;
	LL x = 0;
	while(a > 0){
		x = x * 10 + a % 10;
		a /= 10;
	}
	return x;
}

int f[1111111];

void init(){
	f[1] = 1;
	for(int i = 1; i <= 1000000; i++){
		if(f[i + 1] == 0 || f[i] + 1 < f[i + 1]) f[i + 1] = f[i] + 1;
		int r = rvs(i);
		if(r <= i) continue;
		if(f[r] == 0 || f[i] + 1 < f[r]) f[r] = f[i] + 1;
	}
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	init();
	cin >> T;
	for(int cases = 1; cases <= T; cases++){
		LL n;
		cin >> n;
		printf("Case #%d: %d\n", cases, f[n]);
	}
}