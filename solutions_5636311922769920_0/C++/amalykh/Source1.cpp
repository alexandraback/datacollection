#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <ctime>

typedef long long ll;

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ZERO(x) memset((x), 0, sizeof(x))

using namespace std;

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int w = 0; w < t; w++)
	{
		ll k, c, s;
		cin >> k >> c >> s;
		ll t = 1;
		for (int i = 0; i < c - 1; i++)
			t *= k;
		printf("Case #%d: ", w + 1);
		for (int i = 0; i < s; i++)
		{
			cout << i + 1 << ' ';
		}
		cout << endl;
	}

	return 0;
}