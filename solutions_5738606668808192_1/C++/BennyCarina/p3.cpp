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

void solve() {
	int N, J;
	scanf("%d%d", &N, &J);
	int m = N / 2;
	for (int c = 0; c < J; c++)
	{
		string ans = string(m, '1');
		int t = c;
		for (int i = 1; i < m && t > 0; i++)
		{
			if (t & 1)
			{
				ans[i] = '0';
			}
			t >>= 1;
		}
		string ans_tail = ans;
		reverse(ans_tail.begin(), ans_tail.end());
		ans = ans + ans_tail;
		cout << ans;
		for (int i = 2; i <= 10; i++)
		{
			printf(" %d", i + 1);
		}
		cout << endl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T_case;
	cin >> T_case;
	for (int i_case = 1; i_case <= T_case; i_case++) {
		printf("Case #%d:\n", i_case);
		solve();
	}

	return 0;
}