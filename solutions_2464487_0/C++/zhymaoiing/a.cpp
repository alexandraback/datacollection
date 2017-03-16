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

double Cal(double d)
{
	return d * R * 2.0 + d * (2.0 * d - 1.0);
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tCase = 1; tCase <= T; ++tCase)
	{
		cin >> R >> X;

		ULL s = 0, t = 1LL << 60;

		while (s + 1 < t)
		{
			ULL d = (s + t) / 2;
			//cout << d << "=>" <<Cal(d)<<endl;
			if (Cal(d) > X + 1e-9) t = d;
			else s = d;
		}

		printf("Case #%d: ", tCase);
		cout << s << endl;
	}

	return 0;
}
