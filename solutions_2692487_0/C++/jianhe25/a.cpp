#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

int x, n;
int a[120];
int main() {
	int test;
	cin >> test;
	for (int cas = 1; cas <= test; ++cas)
	{
		cin >> x >> n;
		REP(i, n) cin >> a[i];

		sort(a, a+n);

		int ans = n;
		int i = 0;
		int addCount = 0;
		while (i < n) {
			while (i < n && a[i] < x) {
				x += a[i];
				i++;
			}
			if (n - i + addCount < ans)
				ans = n - i + addCount;
			x += x-1;
			if (x == 1) {
				break;
			}
			addCount++;
		}
		printf("Case #%d: ",cas);
		cout << ans << endl;
	}
}

