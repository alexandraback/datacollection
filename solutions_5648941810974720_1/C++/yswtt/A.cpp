#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int cnt[30];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		string s;
		vector<int> v;
		cin >> s;
		for (int i = 0; i < 28; ++i)
			cnt[i] = 0;
		for (int i = 0; i < s.length(); ++i)
			cnt[s[i] - 'A']++;
		
		// 0 ZERO
		while (cnt['Z'-'A'])
		{
			v.push_back(0);
			cnt['Z'-'A']--;
			cnt['E'-'A']--;
			cnt['R'-'A']--;
			cnt['O'-'A']--;
		}
		// 8 RIGHT
		while (cnt['G'-'A'])
		{
			v.push_back(8);
			cnt['E'-'A']--;
			cnt['I'-'A']--;
			cnt['G'-'A']--;
			cnt['H'-'A']--;
			cnt['T'-'A']--;
		}
		// 6 SIX
		while (cnt['X'-'A'])
		{
			v.push_back(6);
			cnt['S'-'A']--;
			cnt['I'-'A']--;
			cnt['X'-'A']--;
		}
		// 7 SEVEN
		while (cnt['S'-'A'])
		{
			v.push_back(7);
			cnt['S'-'A']--;
			cnt['E'-'A']--;
			cnt['V'-'A']--;
			cnt['E'-'A']--;
			cnt['N'-'A']--;
		}
		// 5 FIVE
		while (cnt['V'-'A'])
		{
			v.push_back(5);
			cnt['F'-'A']--;
			cnt['I'-'A']--;
			cnt['V'-'A']--;
			cnt['E'-'A']--;
		}
		// 4 FOUR
		while (cnt['U'-'A'])
		{
			v.push_back(4);
			cnt['F'-'A']--;
			cnt['O'-'A']--;
			cnt['U'-'A']--;
			cnt['R'-'A']--;
		}
		// 3 THREE
		while (cnt['R'-'A'])
		{
			v.push_back(3);
			cnt['T'-'A']--;
			cnt['H'-'A']--;
			cnt['R'-'A']--;
			cnt['E'-'A']--;
			cnt['E'-'A']--;
		}
		// 2 TWO
		while (cnt['T'-'A'])
		{
			v.push_back(2);
			cnt['T'-'A']--;
			cnt['W'-'A']--;
			cnt['O'-'A']--;
		}
		// 1 ONE
		while (cnt['O'-'A'])
		{
			v.push_back(1);
			cnt['O'-'A']--;
			cnt['N'-'A']--;
			cnt['E'-'A']--;
		}
		// 9 NINE
		while (cnt['I'-'A'])
		{
			v.push_back(9);
			cnt['N'-'A']--;
			cnt['I'-'A']--;
			cnt['N'-'A']--;
			cnt['E'-'A']--;
		}
		
		
		cout << "Case #" << t << ": ";
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
			cout << v[i];
		cout << endl;
	}

    return 0;
}
