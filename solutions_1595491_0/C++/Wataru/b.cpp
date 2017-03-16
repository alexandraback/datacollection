#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int n, s, p;
vector <int> a;

int mxs[31];
int mx[31];

void Solve()
{
	cin >> n >> s >> p;
	a.resize(n);
	int i, j;
	vector <int> dp;
	dp.resize(s+1);
	for (i = 0; i < n; i++) {
		cin >> a[i];
		for (j = s; j >= 0; j--) {
			//try s;
			if (mx[a[i]] >= p)
				dp[j]++;
			if (a[i] >= 2 && j > 0) {
				int sz = 0;
				if (mxs[a[i]] >= p) sz = 1;
				if (dp[j] < dp[j-1]+sz) dp[j] = dp[j-1]+sz;
			}
		}
	}
	cout << dp[s] << "\n";
}

void Gen()
{
	int i, j, k, t;
	for (i = 0; i <= 30; i++) {
		for (t = 0; t <= i; t++) {
			for (k = t; k <= i; k++) {
				j = i - k - t;
				if (j < k) break;
				if (j > t+2) continue;
				if (j == t+2) mxs[i] = max(mxs[i], j);
				else mx[i] = max(mx[i], j);
			}
		}
	}
}

int main()
{
	Gen();
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
