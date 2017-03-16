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

const int MAXN = 1e5 + 5;

int v[MAXN];
char c[MAXN];

int val[5][5];

int mul(int a, int b){
	if (a < 0){
		a = -a;
		b = -b;
	}
	if (b < 0){
		return -val[a][-b];
	} else {
		return val[a][b];
	}
}

int get_code(char c){
	return c - 'i' + 2;
}

void init(){
	int i;
	for(i = 1; i <= 4; i++){
		val[1][i] = val[i][1] = i;
	}
	for(i = 2; i <= 4; i++){
		val[i][i] = -1;
	}
	val[2][3] = 4;
	val[3][2] = -4;
	val[3][4] = 2;
	val[4][3] = -2;
	val[4][2] = 3;
	val[2][4] = -3;	
}

void solve(int t){
	int len, i, j, n;
	ll x;
	printf("CASE #%d: ", t);
	scanf("%d%lld%s", &len, &x, &c[0]);
	x = min(x, 12ll + x % 4ll);
	n = len * x;
	for(i = 0; i < len; i++){
		for(j = 0; j < x; j++){
			v[i + j * len] = get_code(c[i]);	
		}
	}
	int res = 1;
	for(i = 0; i < n; i++){
		res = mul(res, v[i]);
		//printf("%d ", res);
	}
	if (res != -1){
		printf("NO\n");
		return;
	}
	int l = n, r = -1;
	res = 1;
	for(i = 0; i < n; i++){
		res = mul(res, v[i]);
		if (res == 2){
			l = i;
			break;
		}
	}
	res = 1;
	for(i = n - 1; i >= 0; i--){
		res = mul(v[i], res);
		if (res == 4){
			r = i;
			break;
		}
	}
	//printf("%d %d ", l, r);
	if (l < r){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	scanf("%d", &t);
	init();
	for(int i = 1; i <= t; i++){
		solve(i);	
	}
}
