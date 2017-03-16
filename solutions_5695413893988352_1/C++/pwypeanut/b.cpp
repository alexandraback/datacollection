#include <bits/stdc++.h>
using namespace std;

int T;

long long conv(string S) {
	long long ans = 0;
	for (int i = 0; i < S.length(); i++) {
		ans *= 10;
		ans += S[i] - '0';
	}
	return ans;
}
		

pair< long long, pair<string, string> > attempt(string newA, string newB, int b, int v) {
	// make A lower.
	//bool detect = 0;
	//if (newA == "?07" && newB == "23?" && b == 1) detect = 1;
	for (int i = b; i < newA.length(); i++) {
				if (newA[i] == '?') newA[i] = '9';
				if (newB[i] == '?') newB[i] = '0';
			}
			
			bool flag = false;
			if (v) flag = true;
			
			for (int i = b - 1; i >= 0; i--) {
				if (flag) {
					if (newA[i] == '?' && newB[i] == '?') {
						newA[i] = newB[i] = '0';
					} else if (newA[i] != '?' && newB[i] != '?') continue;
					else if (newA[i] == '?') newA[i] = newB[i];
					else newB[i] = newA[i];
				}
				else {
					if (newA[i] == newB[i] && newA[i] == '?') {
						newA[i] = '0';
						newB[i] = '1';
						flag = 1;
					} else if (newA[i] != '?' && newB[i] != '?') continue;
					else if (newA[i] == '?') {
						if (newB[i] == '0') {
							newA[i] = '0';
						} else {
							newA[i] = newB[i] - 1;
							flag = 1;
						}
					} else {
						if (newA[i] == '9') {
							newB[i] = '9';
						} else {
							newB[i] = newA[i] + 1;
							flag = 1;
						}
					}
				}
			}
	
	//if (detect) printf("%s %s\n", newA.c_str(), newB.c_str());
	long long a = conv(newA), b1 = conv(newB);
	long long diff = abs(a - b1);
	return make_pair(diff, make_pair(newA, newB));
}

pair< long long, pair<string, string> > max_ans(pair< long long, pair<string, string> > a, pair< long long, pair<string, string> > b) {
	if (a.first != b.first) {
		if (a.first > b.first) return b;
		else return a;
	} else if (conv(a.second.first) != conv(b.second.first)) {
		if (conv(a.second.first) > conv(b.second.first)) return b;
		else return a;
	} else {
		if (conv(a.second.second) > conv(b.second.second)) return b;
		else return a;
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		string A, B;
		cin >> A >> B;
		int breakpos = -1;
		for (int i = 0; i < A.length(); i++) {
			if (A[i] != '?' && B[i] != '?') {
				if (A[i] != B[i]) {
					breakpos = i;
					break;
				}
			}
		}
		if (breakpos == -1) {
			for (int i = 0; i < A.length(); i++) {
				if (A[i] == '?' && B[i] == '?') {
					A[i] = B[i] = '0';
				} else if (A[i] != '?' && B[i] != '?') continue;
				else if (A[i] == '?') A[i] = B[i];
				else B[i] = A[i];
			}
			printf("Case #%d: %s %s\n", tc, A.c_str(), A.c_str());
			continue;
		}
		pair< long long, pair<string, string> > ans = make_pair(1000000000000000000ll, make_pair("", ""));
		for (int b = 0; b <= breakpos; b++) {
			// first make A lower.
			
			pair< long long, pair<string, string> > ans1 = attempt(A, B, b, 0);
			pair< long long, pair<string, string> > ans2 = attempt(B, A, b, 0);
			pair< long long, pair<string, string> > ans3 = attempt(A, B, b, 1);
			pair< long long, pair<string, string> > ans4 = attempt(B, A, b, 1);
			swap(ans2.second.first, ans2.second.second);
			swap(ans4.second.first, ans4.second.second);
			
			if (ans.second.first == "") ans = ans1;
			ans = max_ans(ans, ans1);
			ans = max_ans(ans, ans2);
			ans = max_ans(ans, ans3);
			ans = max_ans(ans, ans4);
		}
		printf("Case #%d: %s %s\n", tc, ans.second.first.c_str(), ans.second.second.c_str());
	}
}
				
