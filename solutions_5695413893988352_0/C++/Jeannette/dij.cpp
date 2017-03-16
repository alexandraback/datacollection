#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <math.h>
using namespace std;

bool check (string s, int n)
{
	int l = s.length();
	bool b = true;
	for (int i = l - 1; i >= 0; --i)
	{
		if (s[i] != '?' && s[i] - '0' != n % 10)
			b = false;
		n /= 10;
	}
	return b;
}

void cintt (int i, int l)
{
	int k = l - 1;

	int tmp = i / 10;
	while (tmp > 0)
	{--k;
	tmp /= 10;
	}
	for (int i1 = 0; i1 < k; ++i1)
		cout<<'0';
	cout<<i;
}
		
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin>>t;
	for (int l = 0; l < t; ++l)
	{
		string s1, s2;
		cin>>s1>>s2;
		int len = s1.length();
		int max = 1;
		for (int i = 0; i < len; ++i)
			max *= 10;
		int i1, i2;
		int diff = 1000;
		for (int i = 0; i < max; ++i)
		{
			if (!check (s1, i))
				continue;
			for (int j = 0; j < max; ++j)
			{
				if (!check(s2, j))
					continue;
				if (abs(i - j) < diff)
				{
					i1 = i;
					i2 = j;
					diff = abs(i - j);
				}
				else if (abs(i - j) == diff)
				{
					if (i1 > i)
					{
						i1 = i;
						i2 = j;
					}
					else if (i1 == i && i2 > j)
					{
						i2 = j;
					}
				}
			}
		}


		cout<<"Case #"<<l+1<<": ";
		cintt(i1, len);
		cout<<' ';
		cintt(i2, len);
		cout<<endl;
	}
	return 0;
}