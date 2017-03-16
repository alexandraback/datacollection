#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define LL long long

int a, b, k;
LL dp[32][2][2][2];

LL f(int bit, int sa, int sb, int sk)
{
	if (bit == 31)
		return (sa == 0 && sb == 0 && sk == 0) ? 1 : 0;
	else if (dp[bit][sa][sb][sk] != -1)
		return dp[bit][sa][sb][sk];
	LL ret = 0;
	int bitk = k&(1<<bit);
	int bita = a&(1<<bit);
	int bitb = b&(1<<bit);
	if (bitk != 0)
	{
		ret += 1*f(bit+1, sa|(bita==0), sb|(bitb==0), sk);
		ret += 1*f(bit+1, bita!=0 ? 0 : sa, bitb!=0 ? 0 : sb, bitk!=0 ? 0 : sk);
		ret += 1*f(bit+1, bita!=0 ? 0 : sa, sb|(bitb==0), bitk!=0 ? 0 : sk);
		ret += 1*f(bit+1, sa|(bita==0), bitb!=0 ? 0 : sb, bitk!=0 ? 0 : sk);
	}
	else
	{
		ret += 1*f(bit+1, sa|(bita==0), sb|(bitb==0), 1);
		ret += 1*f(bit+1, bita!=0 ? 0 : sa, bitb!=0 ? 0 : sb, sk);
		ret += 1*f(bit+1, bita!=0 ? 0 : sa, sb|(bitb==0), sk);
		ret += 1*f(bit+1, sa|(bita==0), bitb!=0 ? 0 : sb, sk);
	}
	return dp[bit][sa][sb][sk] = ret;
}

int main()
{
	int t;
	cin >> t;
	for (int x = 1; x <= t; ++x)
	{
		memset(dp, -1, sizeof(dp));
		cin >> a >> b >> k; a--; b--; k--;
		cout << "Case #" << x << ": " << f(0, 0, 0, 0) << "\n";
	}
	return 0;
}
