#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;

string s, ans;

string ans1, ans2;
int main()
{
	int test;
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		cin >> s;
		ans.clear();
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			ans1 = ans;
			ans2 = ans;
			ans1 = ans1 + s[i];
			ans2 = s[i] + ans2;
			if (ans1 > ans2)
				ans = ans1;
			else
				ans = ans2;
		}
		//scanf("%d %d %d\n", &k, &c, &s);
		printf("Case #%d: ", t);
		//case output goes here
		cout << ans << endl;
	}
	return 0;
}