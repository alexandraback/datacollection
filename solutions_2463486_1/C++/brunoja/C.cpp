#include <cstdio>
#include <gmpxx.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long

string lim;
mpz_class n;
LL dp[100][3][3];
int d, e;

LL solve(int p, int a, int b)
{
	if (p == d)
	{
		if (e)
		{
			if (a == 2) return 1;
			int res = 1, val = lim[p]-'0';
			
			if (a == 0) res += 2;
			else if (b != 2) // && a == 1
			{
				++res;// 0
				res += val >= 1;// 1
			}
			else
			{
				res += val > 0;
				res += val > 1;
			}
			
			return res;
		}
		return a == 0 || (a == 1 && b < 2);
	}
	
	LL& res = dp[p][a][b];
	if (res != -1) return res;
	res = 3;
	
	int nb, na, val;
	
	// 0
	val = lim[lim.size()-p-1]-'0';
	if (b == 0) nb = val == 0;
	else if (b == 1) nb = val == 0;
	else nb = val == 0 ? 2 : 0;
	val = lim[p]-'0';
	if (a == 0) na = 0;
	else if (a == 1) na = val == 0 ? 1 : 0;
	else na = 2;
	res += solve(p+1, na, nb);
	// 1
	val = lim[lim.size()-p-1]-'0';
	if (val == 0) nb = 2;
	else if (val == 1) nb = b <= 1 ? 1 : 2;
	else nb = 0;
	val = lim[p]-'0';
	if (val == 0) na = a == 0 ? 0 : 2;
	else if (val == 1) na = a;
	else na = a <= 1 ? 0 : 2;
	res += solve(p+1, na, nb);
	
	return res;
}

LL brute()
{
	LL res = 0; int z = 0, g = 1;
	mpz_class t = 10, u = 10;
	while (g)
	{
		mpz_class m = 2*t+2;
		g = 0;
		//cout << m << ' ' << n << endl;
		if (m <= n) ++res, g = 1;
		if (z&1)
		{
			m += u;
			if (m <= n) ++res;
			u *= 10;
			g = 1;
		}
		++z;
		t *= 10;
	}
	return res;
}

string mnt;

mpz_class getit()
{
	stringstream str;
	str << mnt;
	string aux = mnt;
	reverse(aux.begin(), aux.end());
	str << "2";
	str << aux;
	mpz_class num;
	str >> num;
	return num;
}

LL second(int o)
{
	if (o > 1) return 0;
	mpz_class num = getit();
	if (num > n) return 0;
	LL res = 1;
	mnt += "0"; res += second(o); mnt.resize(mnt.size()-1);
	mnt += "1"; res += second(o+1); mnt.resize(mnt.size()-1);
	return res;
}

LL solvefor()
{
	n = sqrt(n);
	stringstream str;
	str << n;
	str >> lim;
	d = lim.size()/2;
	e = lim.size()%2;
	if (d == 0)
	{
		int res = 0;
		if (n >= 1) ++res;
		if (n >= 2) ++res;
		if (n >= 3) ++res;
		return res;
	}
	int b = 0, val = lim[lim.size()-1]-'0';
	// one
	memset(dp, -1, sizeof dp);
	if (val == 1) b = 1;
	else if (val > 1) b = 0;
	else b = 2;
	LL res = 3+solve(1, lim[0] == '1', b);
	// one-two
	mnt = "1";
	res += second(0);
	// two
	res += brute();
	return res;
}

int main()
{
	int t;
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	for (int q = 1; q <= t; ++q)
	{
		mpz_class a, b;
		cin >> a;
		--a;
		n = a;
		LL ra = solvefor();
		cin >> b;
		n = b;
		LL rb = solvefor();
		cout << "Case #" << q << ": " << rb-ra << endl;
	}
}

