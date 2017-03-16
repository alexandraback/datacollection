#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 2000 + 10;

int n;
double a[N];
double b[N];
int vis[N];

void solve(int test)
{
	printf("Case #%d: ", test);
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
		vis[i] = false;
	}
	for(int i = 0; i < n; ++ i) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int ret1 = 0, ret2 = 0;
	for(int i = 0; i < n; ++ i) {
		int flag = -1;
		for(int j = 0; j < n; ++ j) {
			if (! vis[j] && b[j] < a[i]) {
				flag = j;
				break;
			}
		}
		if (flag == -1) {
			for(int j = n - 1; j >= 0; -- j) {
				if (! vis[j]) {
					flag = j;
					break;
				}
			}
		} else ++ ret1;
		vis[flag] = true;
	}
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++ i) {
		int flag = -1;
		for(int j = 0; j < n; ++ j) {
			if (b[j] > a[i] && ! vis[j]) {
				flag = j;
				break;
			}
		}
		if (flag == -1) {
			++ ret2;
			for(int j = 0; j < n; ++ j) {
				if (! vis[j]) {
					flag = j;
					break;
				}
			}
		}
		vis[flag] = true;
	}
	cout << ret1 << ' ' << ret2 << endl;
}

int main()
{
	freopen("D-small-attempt0.in", "r", stdin); freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-small-attempt1.in", "r", stdin); freopen("D-small-attempt1.out", "w", stdout);
	//freopen("D-large.in", "r", stdin); freopen("D-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
