#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		int n;
		cin >> n;
		int cnt[3000] = {};
		for(int i = 0; i < 2*n-1; ++i){
			for(int j = 0, x; j < n; ++j) {
				scanf("%d", &x);
				++cnt[x];
			}
		}
		printf("Case #%d:", tt);
		for(int i = 1; i <= 2500; ++i){
			if(cnt[i] && (cnt[i]&1)) printf(" %d", i);
		}
		puts("");
	}
}