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

LL  N;
bool sig[20];
void refreshSig(LL cur)
{
	while (cur > 0)
	{
		sig[cur % 10] = true;
		cur /= 10;
	}
}
bool yes()
{
	for (int i = 0; i < 10; i++)
	{
		if (!sig[i]) return false;
	}
	return true;
}
void solve()
{
	cin >> N;
	memset(sig, 0, sizeof(sig));
	LL idx = 1;
	if (N <= 0)
	{
		printf("INSOMNIA\n");
		return;
	}
	LL M = N;

	while (true)
	{
		refreshSig(M);
		if (yes())
		{
			break;
		}
		M = N * (++idx);
	}
	cout << M << endl;
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