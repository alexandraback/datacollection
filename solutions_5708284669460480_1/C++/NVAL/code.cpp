#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")

#define mp make_pair
#define pb push_back 
#define ll long long
#define sz(x) (int)(x).size()

int cur[26];

int getdp[111][26];
double dp[111][111][111];

bool bestdp[111][111][111];

int get(string &s, int len, int nxt) {
	if(getdp[len][nxt] != -1) return getdp[len][nxt];
	string c = "";
	for(int i = (len == sz(s) ? 1 : 0), maxi = len; i < maxi; i++) c += s[i];
	c += (nxt + 'A');
	for(int start = 0, maxstart = sz(c); start < maxstart; start++) {
		bool ok = true;
		for(int i = 0, maxi = sz(s); i < maxi; i++) {
			int pos = start + i;
			if(pos >= maxstart) {
				//ok = false;
				break;
			}
			if(s[i] != c[pos]) {
				ok = false;
				break;
			}
		}
		if(ok) return getdp[len][nxt] = sz(c) - start;
	}
	return getdp[len][nxt] = 0;
}

int main()
{
	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //freopen("a.in","rt",stdin);
    //freopen("a.out","wt",stdout);
	
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int K, L, S;
		scanf("%d %d %d", &K, &L, &S);
		string alph;
		cin >> alph;
		for(int i = 0; i < 26; i++) cur[i] = 0;
		memset(getdp, -1, sizeof(getdp));
		memset(bestdp, 0, sizeof(bestdp));
		for(int i = 0; i < 111; i++)
			for(int j = 0; j < 111; j++)
				for(int k = 0; k < 111; k++)
					dp[i][j][k] = 0.0;
		for(int i = 0; i < K; i++) cur[alph[i]-'A']++;
		string sL;
		cin >> sL;
		dp[0][0][0] = 1.0;
		bestdp[0][0][0] = true;
		for(int i = 0; i < S; i++) {
			for(int j = 0, maxj = min(i, L); j <= maxj; j++) {
				for(int k = 0; k <= i; k++) {
					for(int nxt = 0; nxt < 26; nxt++) {
						if(cur[nxt] != 0) {
							int nxtstate = get(sL, j, nxt);
							if(nxtstate == L) {
								dp[i+1][nxtstate][k+1] += dp[i][j][k] * (double)(cur[nxt]) / (double)K;
								if(bestdp[i][j][k]) bestdp[i+1][nxtstate][k+1] = true;
							}
							else {
								dp[i+1][nxtstate][k] += dp[i][j][k] * (double)(cur[nxt]) / (double)K;
								if(bestdp[i][j][k]) bestdp[i+1][nxtstate][k] = true;
							}
						}
					}
				}
			}
		}

		double res = 0.0;
		int best = 0;
		for(int i = 0; i <= L; i++) {
			for(int j = 0; j <= S; j++) {
				res += dp[S][i][j] * (double)(j);
				if(bestdp[S][i][j]) best = max(best, j);
			}
		}
		bool bad = false;
		for(int i = 0; i < L; i++) {
			if(cur[sL[i]-'A'] == 0) {
				bad = true;
				break;
			}
		}

		res = (double)best - res;

		printf("Case #%d: %.9lf\n", t, res);
	}

    return 0;
}