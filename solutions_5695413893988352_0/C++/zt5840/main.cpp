#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

ULL base10[19];
ULL diff;
string ret_a, ret_b;
int N;

void dfs(int d, string a, string b, int p, int comp) {

	if(d == N) {
		for(int i = 0; i<N; i++) {
			if(a[i] =='?') {
				a[i] = '0';
			}
			if(b[i] == '?') {
				b[i] = '0';
			}
		}
		ULL ans;
		if(comp == 0){
			ans = 0;
		} else {
			// cout << a << " " << b << endl;
			ULL aa = stoull(a);
			ULL bb = stoull(b);
			if(comp == 1) {
				ans = aa - bb;
			} else {
				ans = bb - aa;
			}
		}
		if(ans <= diff && b < ret_b) {
			diff = ans;
			ret_a = a;
			ret_b = b;
		}
		return;
	}

	if (comp == 1) {
		if (a[d] == '?') {
			a[d] = '0';
		}
		if (b[d] == '?') {
			b[d] = '9';
		}
		dfs(d + 1, a, b, p, comp);
	} else if (comp == -1) {
		if (a[d] == '?') {
			a[d] = '9';
		}
		if (b[d] == '?') {
			b[d] = '0';
		}
		dfs(d + 1, a, b, p, comp);
	} else {
		if (a[d] == '?' && b[d] == '?') {
			dfs(d + 1, a, b, d, comp);
		} else if (a[d] == b[d]) {
			dfs(d + 1, a, b, d, comp);
		} else {
			if (a[d] != '?' && b[d] != '?') {
				if (a[d] > b[d]) {
					if (p != -1) {
						a[p] = '0';
						b[p] = '1';
						dfs(d + 1, a, b, p, -1);
						a[p] = '0';
						b[p] = '0';
						dfs(d + 1, a, b, p, 1);
					} else {
						dfs(d + 1, a, b, p, 1);
					}
				} else {
					if (p != -1) {
						a[p] = '1';
						b[p] = '0';
						dfs(d + 1, a, b, p, 1);
						a[p] = '0';
						b[p] = '0';
						dfs(d + 1, a, b, p, -1);
					} else {
						dfs(d + 1, a, b, p, -1);
					}
				}
			} else if (a[d] == '?') {
				a[d] = b[d];
				dfs(d + 1, a, b, p, 0);
				if (b[d] != '0') {
					a[d] = b[d] - 1;
					dfs(d + 1, a, b, p, -1);
				}
				if (b[d] != '9') {
					a[d] = b[d] + 1;
					dfs(d + 1, a, b, p, 1);
				}
			} else {
				b[d] = a[d];
				dfs(d + 1, a, b, p, 0);
				if (a[d] != '0') {
					b[d] = a[d] - 1;
					dfs(d + 1, a, b, p, 1);
				}
				if (a[d] != '9') {
					b[d] = a[d] + 1;
					dfs(d + 1, a, b, p, -1);
				}
			}
		}
	}

}

void brute_force(string &str1, string & str2) {
	for (int i = 0; i < 1000; ++i) {
		char str_tmp1[10], str_tmp2[10];
		for (int j = 0; j < 1000; ++j) {
			sprintf(str_tmp1, "%s", i);
		}
	}
}

void __main() {
	base10[0] = 1ULL;
	for (int i = 1; i <= 18; ++i) {
		base10[i] = base10[i] * 10;
	}
	string str1, str2;
	cin >> str1 >> str2;
	N = str1.size();
	ret_a = "9999999999999999999";
	ret_b = "9999999999999999999";
	diff = (1ULL << 63);
	dfs(0, str1, str2, -1, 0);
	cout << ret_a << " " << ret_b << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		__main();
	}
	return 0;
}
