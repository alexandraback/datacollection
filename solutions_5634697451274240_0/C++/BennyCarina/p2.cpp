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
	string read;
	cin >> read;
	vector<int> buf;
	for (int i = read.length() - 1; i >= 0; i--)
	{
		buf.push_back(read[i] == '+' ? 1 : 0);
	}
	int acc = 0;
	for (int i = 0; i < buf.size(); i++)
	{
		if (acc % 2 == buf[i]) acc++;
	}
	cout << acc << endl;
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