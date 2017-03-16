#include <bits/stdc++.h>

using namespace std;

//long long dp[20];

//long long work(long long n) {
//    long long m = 1;
//    int k = 0;
//    while(n > m) {
//	m *= 10;
//	k ++;
//    }
//    m /= 10;
//    long long ans = dp[k];
//    ans += (n % m == 0) ? (n/m - 1) : (n/m);
//    return dp[k];
//}

int dp[1000005];

struct XX {
    int a, b;
    XX(int aa, int bb) {
	a = aa, b = bb;
    }
};

int reverse(int y) {
    stack <int> s;
    bool trim = true;
    while(y > 0) {
	if(trim) {
	    if(y % 10 == 0) {
		y /= 10;
	    } else {
		trim = false;
		s.push(y % 10);
		y /= 10;
	    }
	} else {
	    s.push(y % 10);
	    y /= 10;
	}
    }
    int m = 1;
    int ret = 0;
    while(!s.empty()) {
	ret += s.top() * m;
	m *= 10;
	s.pop();
    }
    return ret;
}

void bfs(long long n) {
    int cur = dp[n] + 1;
    if(dp[n+1] == 0 || cur < dp[n+1]) dp[n+1] = cur;
    if(dp[reverse(n)] == 0 || cur < dp[reverse(n)] && reverse(n) > n) dp[reverse(n)] = cur;    
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    cin >> t;
    memset(dp, 0, sizeof(dp));
    for(int i = 0;  i <= 1000000; i++) {
	bfs(i);
    }
    for(int cas = 1; cas <= t; cas ++) {
	long long n;
	cin >> n;
	cout << "Case #" << cas << ": " << dp[n] << endl;	
    }
    return 0;
}
