#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int INF = 1e9;

int TC;
int dp[110][2];
string s;

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);
	char in[110];
	scanf("%s", in);
	s = in;

	bool f = s[0] == '+';
	int la = s[0];
	int cnt = 1;

	for (int i = 1; i < s.size(); ++i) {
	    if (s[i] != la) {
		la = s[i];
		++cnt;
	    }
	}

	dp[1][1] = 0;
	dp[1][0] = 1;

	for (int i = 2; i <= s.size(); ++i) {
	    dp[i][0] = dp[i][1] = INF;

	    rep(j, 2) {
		if (i > 1) {
		    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ 1] + 1);
		}
	    }

	    if (dp[i][1] < dp[i][0]) {
		dp[i][0] = dp[i][1] + 1;
	    } else {
		dp[i][1] = min(dp[i][1], dp[i][0] + 1);
	    }
	}
	cout << dp[cnt][f] << endl;
    }

    return 0;
}
