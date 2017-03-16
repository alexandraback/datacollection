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
const ll inf = (ll)1e18 + 10000;
ll cn = 0, jn = 0, ans;
char C[30], J[30], CC[30], JJ[30];

void update(int n, char *C, char *J) {
	ll ct = 0;
	ll jt = 0;
	for (int i = 0; i < n; i ++) {
		ct = ct * 10 + C[i] - '0';
		jt = jt * 10 + J[i] - '0';
	}
	if (abs(ct - jt) < ans) {
		ans = abs(ct - jt);
		cn = ct;
		jn = jt;
	}
	if (abs(ct - jt) == ans && ct < cn) {
		cn = ct;
		jn = jt;
	}
	if (abs(ct - jt) == ans && ct == cn && jt < jn) {
		jn = jt;
	}
}

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
	int n = strlen(C);
	ans = inf;
	cn = jn =0;

	for (int same = -1; same < n; same ++) {
		// check possible
		bool poss = true;
		for (int i = 0; i <= same; i ++) {
			if (C[i] == '?' || J[i] == '?' || C[i] == J[i]) continue;
			poss = false;
			break;
		}
		if (!poss) continue;
		
		// 1: C > J
		memcpy(CC, C, sizeof C);
		memcpy(JJ, J, sizeof J);
		for (int i = 0; i <= same; i ++) {
			if (CC[i] != '?') JJ[i] = CC[i];
			else if (JJ[i] != '?') CC[i] = JJ[i];
			else CC[i] = JJ[i] = '0';
		}
		if (same == n - 1) {
			update(n, CC, JJ);
			continue;
		} 
		if (CC[same + 1] == '?' && JJ[same + 1] == '?') {
			CC[same + 1] = '1';
			JJ[same + 1] = '0';
		} else if (CC[same + 1] != '?' && JJ[same + 1] != '?') {
			if (CC[same + 1] <= JJ[same + 1]) {
				continue;  // no solution
			}
		} else if (CC[same + 1] != '?' && JJ[same + 1] == '?') {
			if (CC[same + 1] == '0') continue;
			JJ[same + 1] = CC[same + 1] - 1;
		} else {
			if (JJ[same + 1] == '9') continue;
			CC[same + 1] = JJ[same + 1] + 1;
		}
		for (int i = same + 2; i < n; i ++) {
			if (CC[i] == '?') CC[i] = '0';
			if (JJ[i] == '?') JJ[i] = '9';
		}

		update(n, CC, JJ);
	}

	for (int same = -1; same < n; same ++) {
		// check possible
		bool poss = true;
		for (int i = 0; i <= same; i ++) {
			if (C[i] == '?' || J[i] == '?' || C[i] == J[i]) continue;
			poss = false;
			break;
		}
		if (!poss) continue;
		
		// 2: J > C
		memcpy(JJ, C, sizeof C);
		memcpy(CC, J, sizeof J);
		for (int i = 0; i <= same; i ++) {
			if (CC[i] != '?') JJ[i] = CC[i];
			else if (JJ[i] != '?') CC[i] = JJ[i];
			else CC[i] = JJ[i] = '0';
		}
		if (same == n - 1) {
			update(n, CC, JJ);
			continue;
		} 
		if (CC[same + 1] == '?' && JJ[same + 1] == '?') {
			CC[same + 1] = '1';
			JJ[same + 1] = '0';
		} else if (CC[same + 1] != '?' && JJ[same + 1] != '?') {
			if (CC[same + 1] <= JJ[same + 1]) {
				continue;  // no solution
			}
		} else if (CC[same + 1] != '?' && JJ[same + 1] == '?') {
			if (CC[same + 1] == '0') continue;
			JJ[same + 1] = CC[same + 1] - 1;
		} else {
			if (JJ[same + 1] == '9') continue;
			CC[same + 1] = JJ[same + 1] + 1;
		}
		for (int i = same + 2; i < n; i ++) {
			if (CC[i] == '?') CC[i] = '0';
			if (JJ[i] == '?') JJ[i] = '9';
		}

		update(n, JJ, CC);
	}

	printf("Case #%d:", t);
	out(cn, n);
	out(jn, n);
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