#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int toInt(string s)
{
	int m = 0;
			for(int i = 0; i < s.size(); i++)
			{
				if(s[i] == '0')
					m++;
				else
					break;
			}
			if(m > 0) s.erase(0, m);

			int x = atoi( s.c_str() );
	return x;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int o = 0; o < t; o++)
	{
		int mx = -1;
		int n;
		string s1[100], s2[100];
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> s1[i] >> s2[i];
		}
		int a[100];
		memset(a, 0, sizeof(a));
		while(a[n] == 0)
		{
			int one = 0;
			int c = 0;
			for(int i = 0; i < n; i++)
			{
				if(a[i] == 1)
				{
					one++;
					for(int j = 0; j < n; j++)
					{
						if(a[j] == 0)
						{
							if(s1[i] == s1[j])
							{
								c++;
								break;
							}
						}
					}
					for(int j = 0; j < n; j++)
					{
						if(a[j] == 0)
						{
							if(s2[i] == s2[j])
							{
								c++;
								break;
							}
						}
					}
				}
			}
			if(one == c/2)
			{
				mx = max(mx, one);
			}

			a[0]++;
			for(int i = 0; i < n; i++)
			{
				if(a[i] > 1)
				{
					a[i] = 0;
					a[i+1]++;
				}
			}
		}
		cout  << "Case #" << o+1 << ": ";
		cout << mx << endl;
	}
	return 0;
}