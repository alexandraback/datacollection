#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

//////////////////// Defines ////////////////////

#pragma comment(linker, "/STACK:67108864")

#define inf      2147483647
#define inf64    9223372036854775807
#define eps      1e-9
#define pi      3.14159265358
#define sqr(a) (a)*(a)
#define rall(a) a.rbegin(),a.rend()
#define all(a) a.begin(),a.end()
#define sz(a) (a).size()
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back 
typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define ContinueIf(x) if ((x)) continue
#define ContinueUnless(x) if(!(x)) continue

#define BreakIf(x) if ((x)) break
#define BreakUnless(x) if(!(x)) break

#define ReturnUnless(x) if (!(x)) return
#define ReturnIf(x) if ((x)) return

#define ReturnUnless2(x, ret) if (!(x)) return ret
#define ReturnIf2(x, ret) if ((x)) return ret

//////////////////// Problem Code ////////////////////

int dp[1 << 20];

int main()
{
	int k, T;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &T);
	for(k = 1 ; k <= T ; ++k)
	{
		memset(dp, 0, sizeof(dp));
		int N;
		scanf("%d", &N);
		vector<int> scores(N);

		for (int i = 0; i < N; ++i) {
			scanf("%d", &scores[i]);
		}

		int s1 = 0, s2 = 0;
		int m = 1 << (int)scores.size();
		for (int i = 1; i < m; ++i) {
			int s = 0;
			for (int j = 0; j < (int)scores.size(); ++j) {
				if (i & (1 << j)) {
					s += scores[j];
				}
			}

			if (dp[s]) {
				s1 = dp[s];
				s2 = i;
				break;
			}

			dp[s] = i;
		}

		printf("Case #%d:\n", k);

		if (!s1) {
			printf(" Impossible\n");
		} else {
			for (int j = 0; j < (int)scores.size(); ++j) {
				if (s1 & (1 << j)) {
					printf(" %d", scores[j]);
				}
			}
			printf("\n");

			for (int j = 0; j < (int)scores.size(); ++j) {
				if (s2 & (1 << j)) {
					printf(" %d", scores[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

