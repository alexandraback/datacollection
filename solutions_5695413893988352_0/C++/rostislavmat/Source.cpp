#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <fstream>
using namespace std;


/*ring to_string(int x)
{
	string res = "";
	while (x > 0)
	{
		res += '0' + x % 10;
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}*/

bool check(int x, string a)
{
	string h = to_string(x);
	int l = a.length();
	int need = l - h.length();
	if (need < 0)
		return false;
	string cmp = "";
	for (int i = 0; i < need; i++)
		cmp += '0';
	cmp += h;
	for (int i = 0; i < l; i++)
	{
		if (a[i] != '?')
		{
			if (a[i] != cmp[i])
				return false;
		}
	}
	return true;
}

string to_srt(int x, int l)
{
	string h = to_string(x);
	int need = l - h.length();
	string cmp = "";
	for (int i = 0; i < need; i++)
		cmp += '0';
	cmp += h;
	return cmp;
}


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");


	int qq;
	cin >> qq;
	for (int qqq = 0; qqq < qq; qqq++)
	{
		cout << "Case #" << qqq + 1 << ": ";
		string a, b;
		cin >> a >> b;
		int ans = 9999999;
		int t1 = 9999999;
		int t2 = 99999999;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				if ((check(i, a)) && (check(j, b)))
				{
					int cur = abs(i - j);
					if (cur < ans)
					{
						ans = cur;
						t1 = i;
						t2 = j;
					}
					if (cur == ans)
					{
						if (i < t1)
						{
							t1 = i;
							t2 = j;
						}
						if (t1 == i)
							t2 = min(t2, j);
					}
				}
			}
		}
		cout << to_srt(t1, a.length()) << " " << to_srt(t2, a.length()) << endl;


		/*int n;
		cin >> n;
		map <string, int> first, second;
		vector <string> f1(n), s1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> f1[i] >> s1[i];
			if (first.find(f1[i]) == first.end())
			{
				first[f1[i]] = 1;
			}
			else
			{
				first[f1[i]]++;
			}
			if (second.find(s1[i]) == second.end())
			{
				second[s1[i]] = 1;
			}
			else
			{
				second[s1[i]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if ((first[f1[i]]>1) && (second[s1[i]] > 1))
			{
				ans++;
				first[f1[i]]--;
				second[s1[i]]--;
			}
		}
		cout << ans << endl;
		*/
	}






	return 0;
}