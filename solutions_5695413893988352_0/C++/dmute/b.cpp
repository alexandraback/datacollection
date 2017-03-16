#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

typedef long long ll;
ll ans = 1ll << 62;
ll cn = 0, jn = 0;
char C[30], J[30];

void out(ll x, int d) {
	int arr[20], l = 0;
	memset(arr, 0, sizeof arr);
	if (x == 0) {
		arr[++ l] = 0;
	}
	while (x > 0) {
		arr[++ l] = x % 10;
		x /= 10;
	}
	printf(" ");
	for (int i = d; i > 0; i --) 
		printf("%d", arr[i]);
}

void solve(int t) {
	scanf("%s%s", C, J);
	ans = 1ll << 62;
	cn = jn = 0;
	int n = strlen(C);
	for (int i1 = 0; i1 < 10; i1 ++)
		for (int i2 = 0; i2 < 10; i2 ++)
			for (int i3 = 0; i3 < 10; i3 ++) {
				ll ct = 0;
				if (n >= 1) ct = ct * 10 + ((C[0] == '?') ? i1 : C[0] - '0');
				if (n >= 2) ct = ct * 10 + ((C[1] == '?') ? i2 : C[1] - '0');
				if (n >= 3) ct = ct * 10 + ((C[2] == '?') ? i3 : C[2] - '0');

				for (int j1 = 0; j1 < 10; j1 ++)
					for (int j2 = 0; j2 < 10; j2 ++)
						for (int j3 = 0; j3 < 10; j3 ++) {
							ll jt = 0;
							if (n >= 1) jt = jt * 10 + ((J[0] == '?') ? j1 : J[0] - '0');
							if (n >= 2) jt = jt * 10 + ((J[1] == '?') ? j2 : J[1] - '0');
							if (n >= 3) jt = jt * 10 + ((J[2] == '?') ? j3 : J[2] - '0');
							
							if (abs(jt - ct) < ans) {
								ans = abs(jt - ct);
								cn = ct;
								jn = jt;
							}

							if (abs(jt - ct) == ans && ct < cn) {
								cn = ct;
								jn = jt;
							}

							if (abs(jt - ct) == ans && ct == cn && jt < jn) {
								jn = jt;
							}
						}
			}
	printf("Case #%d:", t);
	out(cn, strlen(C));
	out(jn, strlen(J));
	printf("\n");
}

int main() {
	int tst;
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++) {
		solve(t);
	}
	return 0;
}