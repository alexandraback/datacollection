#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define INF 1000000000000000001ll
#define PA pair<lld, lld>
#define PA3 pair<PA, lld>
#define PAA(x,y,z) PA3(PA(x, y), z)

typedef long long lld;

#define MAXN 1005
#define abs(x) (((x)>0)?(x):(-x))

using namespace std;

lld ans, dp[30][3];
lld opt[30][3][2];
int n;
char in[2][30], tmp[30];

int main() {
    int tt;
    cin >> tt;
    for (int t = 0 ; t < tt ; t ++) {
	scanf("%s %s", in[0], in[1]);
	n = strlen(in[0]);
	ans = INF;
	for (int i = 0 ; i <= n ; i ++) dp[i][0] = dp[i][1] = dp[i][2] = INF;
	dp[0][0] = 0;
	opt[0][0][0] = opt[0][0][1] = 0;
	for (int i = 0 ; i < n ; i ++) {
	    for (int j = 0 ; j < 3 ; j ++) {
		if (dp[i][j] == INF) continue;
		int from1 = 0, to1 = 9, from2 = 0, to2 = 9;
		if (in[0][i] != '?') from1 = to1 = in[0][i] - '0';
		if (in[1][i] != '?') from2 = to2 = in[1][i] - '0';
		//printf("YYYYYY %d %d %d %d %d\n", i, from1, to1, from2 ,to2);
		for (int k = from1 ; k <= to1 ; k ++) {
		    for (int l = from2 ; l <= to2 ; l ++) {
			int jj = j;
			if (jj == 0) {
			    if (k < l) jj = 1;
			    else if (k > l) jj = 2;
			}
			//printf("LLLL %d | %lld %lld\n", jj, opt[i][j][0], opt[i][j][1]);
			int added = 0;
			if (jj == 1) added = l - k;
			else added = k - l;
			lld newopt0 = opt[i][j][0] * 10 + k, newopt1 = opt[i][j][1] * 10 + l;
			if (PAA(dp[i + 1][jj], opt[i + 1][jj][0], opt[i + 1][jj][1]) >
			    PAA(dp[i][j] * 10 + added, newopt0, newopt1)) {
			    dp[i + 1][jj] = dp[i][j] * 10 + added;
			    opt[i + 1][jj][0] = newopt0;
			    opt[i + 1][jj][1] = newopt1;
			}
		    }
		}
	    }
	}
	//printf("XXXXXX %lld %lld %lld\n", dp[n][0], dp[n][1], dp[n][2]);
	cout << "Case #" << t + 1 << ":";
	int ind;
	PA3 tmp0 = PAA(dp[n][0], opt[n][0][0], opt[n][0][1]);
	PA3 tmp1 = PAA(dp[n][1], opt[n][1][0], opt[n][1][1]);
	PA3 tmp2 = PAA(dp[n][2], opt[n][2][0], opt[n][2][1]);
	if (tmp0 <= tmp1 && tmp0 <= tmp2) ind = 0;
	else if (tmp1 <= tmp2) ind = 1;
	else ind = 2;
	for (int i = 0 ; i < 2 ; i ++) {
	    for (int j = 0 ; j < n ; j ++) {
		tmp[n - 1 - j] = '0' + opt[n][ind][i] % 10;
		opt[n][ind][i] /= 10;
	    }
	    tmp[n] = '\0';
	    printf(" %s", tmp);
	}
	cout << endl;
    }
    return 0;
}
