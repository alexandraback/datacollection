#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int t, n, s, p, ans, tmp;
int f[200];

bool cmp(const int &a, const int &b) {
	return a > b;
}

void init()
{
	cin >> n >> s >> p;
	for (int i = 0; i < n; i++) 
		cin >> f[i];
	sort(f, f + n, cmp);
}

void work()
{
	ans = 0;
	for (int i = 0; i < n; i++) {
		tmp = f[i] / 3;
		if (f[i] % 3 != 0) ++tmp;
		if (tmp >= p) {
			++ans; continue;
		}	
		tmp = 2 * max(p-2, 0) + p;
		if ((f[i] >= tmp) && (s > 0)) {
			--s;
			++ans;
		}
	}
	cout << ans << endl; 
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}

