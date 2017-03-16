/*
User:JeffCsoul
Time:
No.:
Everything will be better.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;i++)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();i++)
#define PII pair
#define m_p make_pair
using namespace std;

LL a[30];
int b[30];
int T;
LL n;

inline int Len(LL x)
{
	int ret = 0;
	while (x) ret++, x /= 10;
	return ret;
}

inline LL Calc(LL n, int x, int y)
{
	for (int i = 1; i <= x; i++) b[x + 1 - i] = n % 10, n /= 10;
	LL ret1 = 0, ret2 = 0;
	for (int i = y; i > 0; i--) ret1 = ret1 * 10 + b[i];
	for (int i = y + 1; i <= x; i++) ret2 = ret2 * 10 + b[i];
	return ret1+ret2;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("aout-big.txt", "w", stdout);
	cin>>T;
	for (int i = 1; i <= 14; i++) a[i] = a[i - 1] * 10 + 9;
	for (int nT= 1; nT<= T; nT++)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin>>n;
		printf("Case #%d: ", nT);
		int len = Len(n);
		LL now = 1, ans = 0;
		for (int i=2; i<=len;i++)
		{
			ans += a[(i - 1) / 2] + a[i / 2] + 1;
			now *= 10;
		}
		LL mn=n-now;
		if (mn!=0)
		{
			if (n % 10 == 0) ans++, mn--, n--;
			for (int i = 1; i < len; i++)
			{
				LL ls = Calc(n, len, i);
				mn = min(mn, ls);
			}
		}
		if (n<10) ans++;
		cout<<ans+mn<<endl;
	}
	return 0;
}
