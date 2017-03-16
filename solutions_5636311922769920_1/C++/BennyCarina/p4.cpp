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

void solve()
{
	LL k;
	int c, s;
	cin >> k >> c >> s;
	if ((k + c - 1) / c > s)
	{
		printf(" IMPOSSIBLE\n");
		return;
	}
	LL start, end, ans, t;
	start = 1;
	while (start <= k)
	{
		end = start + c - 1;
		if (end > k) end = k;
		ans = end;
		t = 1;
		for (LL i = end - 1; i >= start; i--)
		{
			t *= k;
			ans += (i - 1) * t;
		}
		cout << " " << ans;
		start = end + 1;
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T_case;
	cin >> T_case;
	for (int i_case = 1; i_case <= T_case; i_case++) {
		printf("Case #%d:", i_case);
		solve();
	}
	return 0;
}