#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y;

inline string solve()
{
	scanf("%d%d", &x, &y);
	swap(x, y);
	string ans = "";
	for (int i = 0; i > x; --i)
		ans += "NS";
	for (int i = 0; i < x; ++i)
		ans += "SN";
	for (int i = 0; i > y; --i)
		ans += "EW";
	for (int i = 0; i < y; ++i)
		ans += "WE";
	return ans;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		printf("Case #%d: %s\n", t + 1, solve().c_str());
	return 0;
}
