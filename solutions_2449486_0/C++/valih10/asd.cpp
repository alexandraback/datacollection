#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 110;

int n, m, x[N][N], sminl[N], sminc[N];

void sol(int pas) {
	cout << "Case #" << pas << ": ";
	int i, j;
	cin >> n>> m;
	for(i = 0; i < N; ++i)
		sminl[i] = sminc[i] = 0;
	
	for(i = 1;  i <= n; ++i)
		for(j = 1; j <= m; ++j) {
			cin >> x[i][j];
			sminl[i] = max(sminl[i], x[i][j]);
			sminc[j] = max(sminc[j], x[i][j]);
		}
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j) {
			if(min(sminl[i], sminc[j]) > x[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	
	cout << "YES\n";
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("tttt", "w", stdout);
	int t;cin >> t;
	
	for(int i = 1; i <= t; ++i)
		sol(i);
	
	return 0;
}
