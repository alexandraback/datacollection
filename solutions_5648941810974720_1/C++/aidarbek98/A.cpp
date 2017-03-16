#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
string s1[100] = {
	"ZERO",
	"EIGHT",
	"TWO",
	"SIX",
	"SEVEN",
	"FIVE",
	"FOUR",
	"ONE",
	"NINE",
	"THREE"
	};
int process(string s)
{
	if(s == "ZERO")
		return 0;
	if(s == "ONE")
		return 1;
	if(s == "TWO")
		return 2;
	if(s == "THREE")
		return 3;
	if(s == "FOUR")
		return 4;
	if(s == "FIVE")
		return 5;
	if(s == "SIX")
		return 6;
	if(s == "SEVEN")
		return 7;
	if(s == "EIGHT")
		return 8;
	if(s == "NINE")
		return 9;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int o = 0; o < t; o++)
	{
		vector<int> v;
		string s;
		cin >> s;
		map<char, int> m1;
		for(int i = 0; i < s.size(); i++)
			m1[s[i]]++;
		for(int i = 0 ; i < 10; i++)
		{
			bool flag = 0;
			while(!flag)
			{
				int c = 0;
				for(int j = 0; j < s1[i].size(); j++)
				{
					if(m1[s1[i][j]] > 0)
					{
						c++;
					}
				}
				if(c == s1[i].size())
				{
					v.push_back(process(s1[i]));
					for(int j = 0; j < s1[i].size(); j++)
					{
						m1[s1[i][j]]--;
					}
				}
				else
					flag = 1;
			}
		}
		sort(v.begin(), v.end());
		cout << "Case #"<< o+1 << ": ";
		for(int i = 0 ; i < v.size(); i++)
			cout << v[i];
		cout << endl;
	}
	return 0;
}