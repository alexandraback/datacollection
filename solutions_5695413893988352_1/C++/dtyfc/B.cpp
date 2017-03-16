#include <bits/stdc++.h>
using namespace std;
char a[30], b[30], p1[30], p2[30];
int n;
const long long INF = (long long)1e18 + 5;
pair <long long, long long> ans; 
pair <long long, long long> getSolution(int pos, int dig_a, int dig_b) {
	long long A = 0;
	long long B = 0;
	pos++;
	if(dig_a < dig_b) {
		for(int i = 0; i < pos - 1; i++) {
			int c = 0;
			if(a[i] != '?') c = a[i] - '0'; else c = b[i] - '0';
			if(a[i] == '?' and b[i] == '?') c = 0;
			A = A * 10 + ((a[i] == '?') ? c : (a[i] - '0'));
		}
		A = A * 10 + dig_a;
		for(int i = pos; i < n; i++) {
			A = A * 10 + ((a[i] == '?') ? 9 : (a[i] - '0'));
		}
		for(int i = 0; i < pos - 1; i++) {
			int c = 0;
			if(a[i] != '?') c = a[i] - '0'; else c = b[i] - '0';
			if(a[i] == '?' and b[i] == '?') c = 0;
			B = B * 10 + ((b[i] == '?') ? c : (b[i] - '0'));
		}
		B = B * 10 + dig_b;
		for(int i = pos; i < n; i++) {
			B = B * 10 + ((b[i] == '?') ? 0 : (b[i] - '0'));
		}
	} else {
		for(int i = 0; i < pos - 1; i++) {
			int c = 0;
			if(a[i] != '?') c = a[i] - '0'; else c = b[i] - '0';
			if(a[i] == '?' and b[i] == '?') c = 0;
			A = A * 10 + ((a[i] == '?') ? c : (a[i] - '0'));
		}
		A = A * 10 + dig_a;
		for(int i = pos; i < n; i++) {
			A = A * 10 + ((a[i] == '?') ? 0 : (a[i] - '0'));
		}
		for(int i = 0; i < pos - 1; i++) {
			int c = 0;
			if(a[i] != '?') c = a[i] - '0'; else c = b[i] - '0';
			if(a[i] == '?' and b[i] == '?') c = 0;
			B = B * 10 + ((b[i] == '?') ? c : (b[i] - '0'));
		}
		B = B * 10 + dig_b;
		for(int i = pos; i < n; i++) {
			B = B * 10 + ((b[i] == '?') ? 9 : (b[i] - '0'));
		}
	}
	return make_pair(A, B);
}
void updateAnswer(pair <long long, long long> sol) {
	//printf("sol <%I64d, %I64d>\n", sol.first, sol.second);
	//printf("now <%I64d, %I64d>\n", ans.first, ans.second);
	long long ori_d = abs((long long)ans.first - ans.second);
	long long now_d = abs((long long)sol.first - sol.second);
	//printf("d(ori = %I64d, now = %I64d)\n", ori_d, now_d);
	if(ori_d < now_d) {
		return;
	} else if(ori_d == now_d) {
		if(ans.first > sol.first || (ans.first == sol.first && ans.second > sol.second)) ans = sol;
	} else {
		ans = sol;
	}
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.ou", "w", stdout);

	int T, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", a, b);
		n = strlen(a);
		ans = make_pair(INF, -INF);
		for(int i = 0; i < n; i++) {
			if(a[i] == '?' && b[i] == '?') {
				for(int u = 0; u < 10; u++) {
					for(int v = 0; v < 10; v++) {
						updateAnswer(getSolution(i, u, v));
					}
				}
			} else if(a[i] == '?') {
				for(int u = 0; u < 10; u++) {
					updateAnswer(getSolution(i, u, b[i] - '0'));
				}
			} else if(b[i] == '?') {
				for(int v = 0; v < 10; v++) {
					updateAnswer(getSolution(i, a[i] - '0', v));
				}
			} else if(a[i] != b[i]) {
				updateAnswer(getSolution(i, a[i] - '0', b[i] - '0'));
				break;
			} else {
				continue;
			}
		}
		long long t = ans.first, idx = n - 1;
		memset(p1, '0', sizeof(p1));
		p1[idx + 1] = 0;
		while(t > 0 && idx >= 0) {
			p1[idx--] = '0' + t % 10;
			t /= 10;
		}
		t = ans.second, idx = n - 1;
		memset(p2, '0', sizeof(p2));
		p2[idx + 1] = 0;
		while(t > 0 && idx >= 0) {
			p2[idx--] = '0' + t % 10;
			t /= 10;
		}
		printf("Case #%d: %s %s\n", ++cases, p1, p2);
	}
	return 0;
}
