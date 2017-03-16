#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;	cin >> tc;
	for (int T = 1; T <= tc; T++)
	{
		string s;	cin >> s;
		int x;		cin >> x;
		long long ans = 0;
		int len = s.length();
		int curlen = 0, curst = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				curlen = 0;	continue;
			}
			else
			{
				curlen ++;
				if (curlen == x)
				{
					int st = i - x + 1;
					ans += (((long long)st) - curst + 1) * (len - i);
					curst = st + 1;	curlen --;
				}
			}
		}
		cout << "Case #" << T << ": " << ans << endl;
	}

}