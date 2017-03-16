#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef unsigned long long ULL;

ULL R, X;

ULL Cal(ULL d)
{
	return d * R * 2 + d * (2 * d - 1);
}

bool Check(ULL d)
{
	if (X / R < d * 2) return true;
	return d * R * 2 + d * (2 * d - 1) > X;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large2.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tCase = 1; tCase <= T; ++tCase)
	{
		cin >> R >> X;

		ULL s = 0, t = 1LL << 32;

		while (s + 1 < t)
		{
			ULL d = (s + t) / 2;
			//cout << d << "=>" <<Cal(d)<<endl;
			if (Check(d)) t = d;
			else s = d;
		}

		printf("Case #%d: ", tCase);
		cout << s << endl;
	}

	return 0;
}
