#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

const int N = 105;
const int MAXVAL = 1000010;
const int inf = 1000000;

int a, n, x[N], d[N][MAXVAL];

void sol(int c) {
	int i, j, smax = 0;
	cin >> a >> n;
	smax = a;
	for(i = 1; i <= n; ++i)
		cin >> x[i], smax = max(smax, x[i]);
	sort(x + 1, x + n + 1);
	smax++;
	
	for(i = 0; i <= n + 1; ++i)
		for(j = 1; j <= smax; ++j)
			d[i][j] = inf;
	
	d[0][a] = 0;
	
	if(c == 39) {
		c = 39;
	}
	
	for(i = 0; i <= n; ++i)
		for(j = 1; j <= smax; ++j) if(d[i][j] != inf) {
			d[i][min(smax, j + j - 1)] = min(d[i][min(smax, j + j - 1)], d[i][j] + 1);
			if(x[i] < j)
				d[i + 1][min(smax, j + x[i])] = min(d[i + 1][min(smax, j + x[i])], d[i][j]);
			else
				d[i + 1][j] = min(d[i + 1][j], d[i][j] + 1);
		}
	
	cout << "Case #" << c << ": ";
	int rez = 1000000;
	for(j = 1; j <= smax; ++j)
		rez = min(rez, d[n + 1][j]);
	cout << rez << "\n";
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("out", "w", stdout);
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; ++i)
		sol(i);
	
	return 0;
}
