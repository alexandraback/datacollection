#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void redirectIO()
{
	string fileName;
	cin >> fileName;
	string input = fileName + ".in";
	string output = fileName + ".out";

	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
}

typedef long long LL;

bool IsFair(LL n)
{
	int d[32] = {0};
	int c = 0;

	while (n > 0)
	{
		d[c++] = n % 10;
		n /= 10;
	}

	for (int i = 0, j = c - 1; i < j; ++i, --j)
		if (d[i] != d[j])
			return false;
	return true;
}

LL GetSquaret(LL n)
{
	LL sn = (LL)sqrt(n * 1.0);
	for (LL d = max(sn - 5, 0LL); d <= sn + 5; ++d)
		if (d * d == n)
			return d;
	return -1;
}

vector<LL> res;

LL Cal(LL n)
{
	//LL countFair = 0, countFairSqr = 0;

	//for (int i = 1; i <= n; ++i)
	//	if (IsFair(i))
	//	{
	//		++countFair;
	//	
	//		LL si = GetSquaret(i);
	//		if (-1 != si && IsFair(si))
	//		{
	//			cout << i << " => " << si << endl;
	//			++countFairSqr;
	//		}
	//	}

	//cout << "Fair = " << countFair << endl;
	//cout << "FairSqr = " << countFairSqr << endl;

	//return n;

	int s = -1, t = res.size();
	while (s + 1 < t)
	{
		int d = (s + t) / 2;
		LL v = res[d] * res[d];
		if (v <= n) s = d;
		else t = d;
	}

	//cout << "Query " << n << ":" << s + 1 << endl;

	return s + 1;
}

int main()
{
	res.push_back(1);
	res.push_back(2);
	res.push_back(3);

	for (int i = 2; i <= 10; ++i)
	{
		int d = (i + 1) / 2;
		int way = 1;
		for (int j = 0; j < d; ++j)
			way *= 3;
		for (int j = 0; j < way; ++j)
		{
			int v = j;
			int sq = 0;
			LL p = 0;
			for (int k = 0; k < d && sq < 10; ++k)
			{
				int x = v % 3;
				
				if (k == 0 && x == 0)
				{
					sq = 10;
					break;
				}

				p = p * 10 + x;
				v /= 3;
				sq += x * x;
			}

			if (sq >= 10) continue;

			LL q = i % 2 == 0 ? p : p / 10;
			for (int k = i % 2; k < d && sq < 10; ++k)
			{
				int x = q % 10;
				p = p * 10 + x;
				q /= 10;
				sq += x * x;
			}

			if (sq < 10)
			{
				res.push_back(p);
			}
		}
	}

	sort(res.begin(), res.end());

	//for (int i = 0; i < res.size(); ++i) cout << res[i] << " "; cout << endl;

	redirectIO();

	int T;
	scanf("%d", &T);
	for (int ct = 1; ct <= T; ++ct)
	{
		LL A, B;
		cin >> A >> B;
		printf("Case #%d: ", ct);
		cout << Cal(B) - Cal(A - 1) << endl;
	}
}