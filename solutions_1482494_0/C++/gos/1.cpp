#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Lev1
{
	int a, b;
} level[10000];
int N, T, Tidx = 1, flag[10000], ans, stars, rest;
bool comp(Lev1 s1, Lev1 s2)
{
	if(s1.b < s2.b)
		return true;
	else if(s1.a > s2.a && s1.b == s2.b)
		return true;
	return false;
}
int main()
{
	freopen("e:\\B-small-attempt2.in", "r", stdin);
	freopen("e:\\B-small-attempt2.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> level[i].a >> level[i].b;
		sort(level, level + N, comp);
		memset(flag, 0, sizeof(flag));
		bool getout = false;
		ans = stars = 0;
		rest = N;
		for(int i = 0; i < N; i++)
		{
			if(stars >= level[i].b)
			{
				ans++;
				if(flag[i] == 0)
					stars += 2;
				else
					stars++;
				flag[i] = 2;
			}
			else
			{
				int j = N - 1;
				while(stars < level[i].b && j >= i)
				{
					if(level[j].a <= stars && flag[j] == 0)
					{
						ans++;
						flag[j] = 1;
						stars++;
					}
					j--;
				}
				if(stars < level[i].b)
				{
					getout = true;
					break;
				}
				else
				{
					ans++;
					if(flag[i] == 0)
						stars += 2;
					else
						stars++;
					flag[i] = 2;
				}
			}
		}
		cout << "Case #" << Tidx++ << ": ";
		if(getout)
			cout << "Too Bad" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}