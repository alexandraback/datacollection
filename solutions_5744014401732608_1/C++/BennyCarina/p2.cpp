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

LL mypow(LL x, LL p) {
	LL ret = 1;
	while (p > 0) {
		if (p & 1)ret = ret*x;
		p >>= 1;
		x = x*x;
	}
	return ret;
}

int buf[100][100];

void output(int B)
{
	for (int i = 1; i <= B; i++)
	{
		for (int j = 1; j <= B; j++)
		{
			printf("%d", buf[i][j]);
		}
		printf("\n");
	}
}

void solve()
{
	int B;
	LL M;
	cin >> B >> M;
	
	LL bnd = mypow(2, B - 2);
	if (bnd < M)
	{
		printf("IMPOSSIBLE\n");
		return;
	}

	printf("POSSIBLE\n");
	
	for (int i = 1; i <= B; i++)for (int j = 1; j <= B; j++)
	{
		buf[i][j] = j > i ? 1 : 0;
	}

	if (bnd == M)
	{
		output(B);
		return;
	}

	for (int i = 1; i <= B; i++)
	{
		buf[i][B] = 0;
	}

	int idx = 2;
	while (M > 0)
	{
		if (M % 2 == 1)
		{
			buf[idx][B] = 1;
		}
		idx++;
		M /= 2;
	}
	output(B);

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