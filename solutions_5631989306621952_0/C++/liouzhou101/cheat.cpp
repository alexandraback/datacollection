#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
	freopen("try.in", "r", stdin);
	freopen("try.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int TT=1; TT<=Test; ++TT)
	{
		printf("Case #%d: ", TT);
		string s;
		cin >> s;
		int n = s.size();
		string t = s.substr(0,1);
		for (int i=1; i<n; ++i)
			if (s[i]<t[0])
				t += s[i];
			else
				t = s[i] + t;
		cout << t << endl;
	}
	return 0;
}
