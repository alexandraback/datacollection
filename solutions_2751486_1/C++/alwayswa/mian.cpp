#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000005
#define LL long long
int len;
int f[N];
string vowel = "aeiou";
string st;
int n;
int judge(char a)
{
	for (int i = 0; i < vowel.size(); i++)
		if (a == vowel[i])
			return 0;
	return 1;
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int t;
	LL ret;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		cin >> st;
		cin >> n;
		len = st.size();
		if (n > len)
		{
			cout << 0 << endl;
			continue;
		}
		int temp = -1;
		if (judge(st[0]))
			f[0] = 1;
		else
			f[0] = 0;
		int i = 1;
		while (i < len && f[i - 1] < n)
		{
			if (judge(st[i]))
				f[i] = f[i - 1] + 1;
			else
				f[i] = 0;
			i++;
		}
		if (f[i - 1] < n)
			ret = 0;
		else
		{
			temp = i - n;
			ret = temp + 1;
			for (; i < len; i++)
			{
				if (judge(st[i]))
					f[i] = f[i - 1] + 1;
				else
					f[i] = 0;
				if (f[i] >= n)
					temp = i - n + 1;
				ret += temp + 1;
			}
		}
		cout << ret << endl;
	}
	return 0;
}
