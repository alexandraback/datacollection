#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr), ios::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<string> numbers = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	//Six, Five, Two, seven, Zero, eiGht, Four, thRee, One, nIne 
	vector<pair<int, char> > trick = { {6, 'X'}, {2, 'W'},{0, 'Z'}, {7, 'S'}, {5, 'V'}, {8, 'G'}, {4, 'F'}, {3, 'R'}, {1, 'O'}, {9, 'I'} };
	int t;
	cin >> t;
	for (int cc = 0; cc < t; cc++)
	{
		string s;
		cin >> s;
		map<char, int> mp;
		for (auto ch : s)
			mp[ch]++;
		vector<int> ans(10);
		for (auto pr : trick)
		{
			ans[pr.first] = mp[pr.second];
			for (auto ch : numbers[pr.first])
				mp[ch] -= ans[pr.first];
		}
		cout << "Case #" << cc + 1 << ": ";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < ans[i]; j++)
				cout << i;
		}
		cout << endl;
	}
	return 0;
}