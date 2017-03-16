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

const int MAXN = 1e3 + 5, INF = 1e8;

int v[MAXN];

void solve(int t){
	int ans = INF, n, a, i, j, cur;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> v[i];
	}
	for(i = 1; i < MAXN; i++){
		cur = i;
		for(j = 0; j < n; j++){
			cur += (v[j] - 1) / i;
		}
		ans = min(ans, cur);
	}
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
