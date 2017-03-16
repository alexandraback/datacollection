#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
//#pragma comment(linker, "/STACK:36777216") //if stack overflow
using namespace std;

#define LarN 100000
typedef long long LL;
const double d_pi = 57.2957795;

template<class T> inline void ReMin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void ReMax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }

int A, B, C, K;
int types[2000][2];
bool sig[2000];
int buf[2000];
int ans[2000][3], len;

void output()
{
	printf("%d\n", len);
	for (int i = 1; i <= len; i++)
	{
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
}

void solve()
{
	scanf("%d%d%d%d", &A, &B, &C, &K);
	int idx = 0;
	for (int i = 1; i <= A; i++) for (int j = 1; j <= B; j++)
	{
		types[++idx][0] = i;
		types[idx][1] = j;
	}
	memset(sig, 0, sizeof(sig));
	memset(buf, 0, sizeof(buf));
	len = 0;

	for (int i = 1; i <= C; i++)
	{
		memset(sig, 0, sizeof(sig));
		for (int j = 1; j <= idx; j++)
		{
			int a = types[j][0], b = types[j][1];
			int acc = 0;
			for (int k = 1; k <= idx; k++)
			{
				if (sig[k] && (types[k][0] == a || types[k][1] == b))
				{
					acc++;
				}
			}
			if (acc >= K || buf[j] >= K) continue;

			sig[j] = true;
			buf[j] ++;

			ans[++len][0] = a;
			ans[len][1] = b;
			ans[len][2] = i;			
		}
	}
	output();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T_case;
	cin >> T_case;
	for (int i_case = 1; i_case <= T_case; i_case++) {
		printf("Case #%d: ", i_case);
		solve();
	}
	return 0;
}