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

int TC;
int N;
int num;
vi u[110];
int mat[110][110];
int dp[110];
int fr[110];
bool us[110];

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d:", tc);

	scanf("%d", &N);
	num = N * 2 - 1;

	int mi = 3000;
	rep(i, num) {
	    u[i].resize(N);
	    rep(j, N) {
		scanf("%d", &u[i][j]);
		mi = min(mi, u[i][j]);
	    }
	}

	sort(u, u + num);
	memset(dp, 0, sizeof(dp));
	memset(fr, -1, sizeof(fr));

	rep(i, num) {
	    dp[i] = 1;

	    rep(j, i) {
		bool f = 1;
		rep(k, N) if (u[j][k] >= u[i][k]) f = 0;
		if (f) {
		    if (dp[i] < dp[j] + 1) { 
			fr[i] = j;
			dp[i] = dp[j] + 1;
		    }
		}
	    }
	}

	int cnt = 0;
	int piv = -1;
	rep(i, num) {
	    if (dp[i] == N) {
		++cnt;
		piv = i;
	    }
	}
	
	vi vec;
	vec.pb(piv);

	rep(i, N - 1) {
	    piv = fr[piv];
	    vec.pb(piv);
	}

	rep(i, num) us[i] = 0;

	reverse(ALL(vec));

	rep(i, N) {
	    int id = vec[i];
	    us[id] = 1;
	    rep(j, N) mat[i][j] = u[id][j];
	}
/*
	rep(i, N) {
	    rep(j, N) cout << mat[i][j] << " ";
	    cout << endl;
	}
*/
	int now = 0;
	bool f = 0;

	rep(i, num) {
	    if (!us[i]) {
		if (u[i][0] == mat[0][now]) ++now;
		else {
		    rep(i, N) printf(" %d", mat[i][now]);
		    puts(" ");
		    f = 1;

		    break;
		}
	    }
	}

	if (!f) {
	    rep(i, N) printf(" %d", mat[i][N - 1]);
	    puts(" ");
	}
	
    }

    return 0;
}
