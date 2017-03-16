#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);

	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	vector<string> variants = { "ZERO", "TWO", "EIGHT", "SIX", "FOUR", "FIVE", "SEVEN", "ONE", "NINE", "THREE" };
	vector<int> digits = { 0, 2, 8, 6, 4, 5, 7, 1, 9, 3 };

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		string s;
		cin >> s;
		map<char, int> counts;
		
		map<int, int> ans;
		for (int i = 0; i < 10; i++)
		{
			ans[i] = 0;
		}

		for (char c = 'A'; c <= 'Z'; c++)
		{
			counts[c] = 0;
		}
		
		for (int i = 0; i < s.length(); i++)
		{
			counts[s[i]]++;
		}

		for (int i = 0; i < variants.size(); i++)
		{
			int c = counts[variants[i][0]];
			for (int j = 0; j < variants[i].length(); j++)
			{
				c = min(c, counts[variants[i][j]]);
			}
			ans[digits[i]] = c;

			for (int j = 0; j < variants[i].length(); j++)
			{
				counts[variants[i][j]] -= c;
			}
		}

		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < 10; i++)
		{
			int count = ans[i];
			for (int j = 0; j < count; j++)
			{
				cout << char('0' + i);
			}
		}
		cout << endl;
	}
	return 0;
}