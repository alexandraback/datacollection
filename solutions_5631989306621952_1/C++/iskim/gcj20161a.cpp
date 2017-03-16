#include <stdio.h>
#include <deque>
#include <string>
using namespace std;

char str[1005];

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\A-large.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\A-large.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		scanf("%s", str);

		deque<char> ans;

		ans.push_back(str[0]);

		for (int i = 1; str[i]; i++)
		{
			if (ans.front() <= str[i])
			{
				ans.push_front(str[i]);
			}
			else ans.push_back(str[i]);
		}

		string str(ans.begin(), ans.end());
		printf("Case #%d: %s\n", tt, str.c_str());
	}
}