#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int T, zzz = 0;
	scanf("%d", &T);
	while (T --)
	{
		string s, ans;
		cin >> s;
		for (int i = 0; i < (int) s.length(); ++ i)
		{
			if (s[i] + ans < ans + s[i])
			{
				ans = ans + s[i];
			}
			else
			{
				ans = s[i] + ans;
			}
		}
		cout << "Case #" << ++ zzz << ": " << ans << endl;
	}
}

