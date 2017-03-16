#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;		scanf("%d", &tc);
	for (int T = 1; T <= tc; T++)
	{
		int a, n;	scanf("%d%d", &a, &n);
		int ans = 0;
		multiset<int> s;
		for (int i = 0; i < n; i++)
		{
			int tem;	scanf("%d", &tem);	s.insert(tem);
		}
		
		while (1)
		{
			if (s.empty())	break;
			if (a > *s.begin())
			{
				a += *s.begin();
				s.erase(s.begin());
			}
			else
			{
				int cnt, mxcnt = s.size(), tema;
				for (cnt = 1; cnt < mxcnt; cnt++)
				{
					tema = a;
					for (int i = 0; i < cnt; i++)	tema = 2 * tema - 1;
					int i = 0;
					for (multiset<int>::iterator p = s.begin(); p != s.end(); p++)
					{
						if (tema > *p)
						{
							tema += *p;	i++;	
							if (i == cnt)	break;
						}
						else
						{
							break;
						}
					}
					if (i == cnt)
						break;
				}
				if (cnt == mxcnt)	{ans += mxcnt;break;}
				else
				{
					a = tema;	ans += cnt;
					for (int i = 0; i < cnt; i++)	s.erase(s.begin());
				}
			}
		}
		printf("Case #%d: %d\n", T, ans);
	}
}