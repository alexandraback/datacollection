#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

bool is_cons(char c)
{
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 0;
	cin >> t; getchar();
	string s;
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		getline(cin, s, ' ');
		int n;
		cin >> n; getchar();
		int prev_l = -1; int prev_k = -1;
		__int64 ans = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (is_cons(s[i]))
			{
				int cur = i + 1;
				while (cur < s.length() && is_cons(s[cur]))
					++cur;
				int cnt = cur - i;
				if (cnt >= n)
				{
					if (prev_l != -1)
						ans += __int64(n + i - (prev_l + prev_k + 1)) * (s.length() - i - n + 1);
					else
						ans += __int64(i) * (s.length() - i - n + 1);
					for (int j = i; j <= i + cnt - n; ++j)
						if (s.length() >= (j + n - 1))
							ans += s.length() - j - n + 1;
					prev_l = i;
					prev_k = cnt;
				}
				i = cur - 1;

			}
		}
		cout << ans << endl;
	}
}