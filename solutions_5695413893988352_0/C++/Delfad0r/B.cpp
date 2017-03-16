#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;

ll Abs(ll x) {
	return (x > 0) ? (x) : (-x);
}

llll best(llll a, llll b) {
	ll x = abs(a.first - a.second), y = abs(b.first - b.second);
	if(x < y) return a;
	if(x > y) return b;
	return min(a, b);
}

string tos(ll x, unsigned c) {
	string ans;
	while(x) {
		ans.push_back((x % 10) + '0');
		x /= 10;
	}
	while(ans.length() < c) ans.push_back('0');
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve(int t) {
	string A, B;
	cin >> A >> B;
	llll ans(1000000000000000000LL, 0);
	for(unsigned k = 0; k < A.length(); ++k) {
		for(int a = 0; a < 10; ++a)
			for(int b = 0; b < 10; ++b) {
				if(a == b) continue;
				if(A[k] != a + '0' && A[k] != '?') continue;
				if(B[k] != b + '0' && B[k] != '?') continue;
				string A1 = A, B1 = B;
				A1[k] = a + '0';
				B1[k] = b + '0';
				for(unsigned j = k + 1; j < A.length(); ++j) {
					if(a > b) swap(A1, B1);
					if(A1[j] == '?') A1[j] = '9';
					if(B1[j] == '?') B1[j] = '0';
					if(a > b) swap(A1, B1);
				}
				ans = best(ans, llll(stoll(A1), stoll(B1)));
			}
		if(A[k] == '?') {
			if(B[k] == '?')
				A[k] = B[k] = '0';
			else
				A[k] = B[k];
		} else {
			if(B[k] == '?')
				B[k] = A[k];
			else if(A[k] != B[k])
				break;
		}
	}
	if(A == B)
		ans = best(ans, llll(stoll(A), stoll(B)));
	printf("Case #%d: %s %s\n", t, tos(ans.first, A.length()).c_str(), tos(ans.second, A.length()).c_str());
}

int main() {	
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
		solve(t);
}
