#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int case_all , case_count = 1;
	scanf("%d", &case_all);
	for (case_count = 1; case_count <= case_all; ++case_count)
	{
		int n, m, fg, a, b;
		__int64 res = 0;
		scanf("%d %d", &n, &m);
		for (int i = n; i <= m; ++i)
		{
			char temp[11];
			sprintf(temp, "%d", i);
			string s(temp);
			sprintf(temp, "%d", n);
			a = strlen(temp);
			sprintf(temp, "%d", m);
			b = strlen(temp);
			if (a == -1 && a < s.size() && b > s.size())
			{
				string ss(s);
				sort(ss.begin(), ss.end());
				if (ss[0] == ss[ss.size() - 1])
				{
					continue;
				}
				for (int j = 0; j < s.size(); ++j)
				{
					if (s[j] != '0')
					{
						++res;
					}
				}
				--res;
				continue;
			}
			do
			{
				s = s[s.size() - 1] + s;
				s.resize(s.size() - 1);
				sscanf(s.c_str(), "%d", &fg);
				if (s[0] != '0' && fg >= n && fg <= m)
				{
					++res;
				}
			} while (fg != i);
			--res;
		}
		printf("Case #%d: %I64d\n", case_count, (res >> 1));
	}
	return 0;
}
