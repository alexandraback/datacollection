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

vector <int> duo(int x)
{
	vector <int> ans;
	while (x > 0)
	{
		ans.push_back(x % 2);
		x /= 2;
	}
	return ans;
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
		int n;
		cin >> n;
		
		vector <string> f1(n), s1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> f1[i] >> s1[i];
		}
		int maxans = 0;
		for (int seed = 65536; seed < 131072;seed++)
		{
			vector <int> x = duo(seed);

			map <string, int> first, second;
			for (int i = 0; i < n; i++)
			{
				if (x[i] == 1)
				{
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
			}
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (x[i] == 0)
				{

					if ((first[f1[i]]>0) && (second[s1[i]] > 0))
					{
						ans++;
					}
				}
			}
			
			if (ans > maxans)
				maxans = ans;
		}
			
		
		cout << maxans << endl;
	}






	return 0;
}