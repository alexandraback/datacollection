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
		string s;
		cin >> s;
		s.push_back('+');
		int ans = 0;
		for (int i = 1; i < s.size(); i++)
			if (s[i] != s[i - 1]) ans++;
		printf("Case #%d: %d\n", w + 1, ans);
	}

	return 0;
}