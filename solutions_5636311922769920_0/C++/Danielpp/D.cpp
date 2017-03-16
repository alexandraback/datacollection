#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll exp(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

// ONLY SOLVES THE SMALL K = S CASE!
void solve(int c, int K, int C, int S) {
	cout << "Case #" << c << ":";
	ll jump = (K == 1) ? 0 : (exp(K, C) - 1)/(K - 1);
	for (int i=1; i <= K; i++) cout << ' ' << (i - 1) * jump + 1;
	cout << endl;
}

int main() {
	int T, K, C, S;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> K >> C >> S;
		solve(c, K, C, S);
	}
}