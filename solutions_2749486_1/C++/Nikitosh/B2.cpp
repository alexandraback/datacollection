#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int T, x, y, m, l;
string s;

void foo (int x, int y, int ans)
{
	if (ans == 0)
		return;
	int m1 = abs(x - ans) + abs(y);
	int m2 = abs(x + ans) + abs(y);
	int m3 = abs(x) + abs(y - ans);
	int m4 = abs(x) + abs(y + ans);
	if (m1 <= m2 && m1 <= m3 && m1 <= m4)
	{
		s += 'N'; 
		foo (x - ans, y, ans - 1);
	}
	if (m2 < m1 && m2 <= m3 && m2 <= m4)
	{
		s += 'S'; 
		foo (x + ans, y, ans - 1);
	}
	if (m3 < m1 && m3 < m2 && m3 <= m4)
	{
		s += 'E'; 
		foo (x, y - ans, ans - 1);
	}
	if (m4 < m1 && m4 < m2 && m4 < m3)
	{
		s += 'W'; 
		foo (x, y + ans, ans - 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int g = 0; g < T; g++)
	{
		s = "";
		printf("Case #%d: ", g + 1);
		scanf("%d%d", &x, &y);
		m = abs(x) + abs(y);
		for (int i = 1; i < 10000; i++)
			if (i * (i + 1) / 2 >= m)
			{
				l = i;
				break;
			}
		if ((l * (l + 1) / 2) % 2 != m % 2)
			l++;
		foo(x, y, l);
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}
