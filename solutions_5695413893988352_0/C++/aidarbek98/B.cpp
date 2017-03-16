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
		int mn = 999999;
		string ans1, ans2;
		int a[100];
		memset(a, 0, sizeof(a));
		string s,s1;
		cin >> s >> s1;
		int n = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i]=='?')
				n++;
			if(s1[i] == '?')
				n++;
		}
		//cerr << n <<endl;
		while(a[n] == 0)
		{
			int c = 0;
			string s2, s3;
			s2 = s;
			s3 = s1;
			for(int i = 0; i < s2.size(); i++)
			{
				if(s2[i] == '?')
				{
					s2[i] = char(a[c] + 48);
					c++;
				}
			}
			for(int i = 0; i < s3.size(); i++)
			{
				if(s3[i] == '?')
				{
					s3[i] = char(a[c] + 48);
					c++;
				}
			}
			//cerr << s2 << " " << s3 << endl;
			int m = 0;
			for(int i = 0; i < s2.size(); i++)
			{
				if(s2[i] == '0')
					m++;
				else
					break;
			}
			if(m > 0) s2.erase(0, m);
			m = 0;
			for(int i = 0; i < s3.size(); i++)
			{
				if(s3[i] == '0')
					m++;
				else
					break;
			}
			if(m > 0) s3.erase(0, m);

			int x = atoi( s2.c_str() );
			int y = atoi( s3.c_str() );
			if(abs(x - y) < mn)
			{
				mn = abs(x - y);
				ans1 = s2;
				ans2 = s3;
				/* code */
			}
			else if(abs(x-y) == mn)
			{
				if(x < toInt(ans1))
				{
					ans1 = s2;
					ans2 = s3;
				}
				else if(x == toInt(ans1))
				{
					if(y < toInt(ans2))
					{
						ans1 = s2;
						ans2 = s3;
					}
				}
			}
			a[0]++;
			for(int i = 0; i < n; i++)
			{
				if(a[i] > 9)
				{
					a[i] = 0;
					a[i+1]++;
				}
			}	
		}
		cout << "Case #"<<o+1 << ": ";
		for(int i = 0; i < s1.size() - ans1.size(); i++)
			cout << "0";
		cout << ans1; 
		cout << " ";
		for(int i = 0; i < s1.size() - ans2.size(); i++)
			cout << "0";
		cout << ans2 << endl;
	}
	return 0;
}