//Andrew Yang
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
map<char, int> m;
int main(void)
{
	freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);
	int sets;
	cin >> sets;
	FOR(set, 1, sets + 1)
	{
		string s;
		cin >> s;
		FOR(i, 0, s.length())
		{
			m[s[i]]++;
		}
		vector<int> ans;
		while (m['Z'] > 0) // zero z
		{
			m['Z']--;
			m['E']--;
			m['R']--;
			m['O']--;
			ans.push_back(0);
		}
		while (m['X'] > 0) // six x
		{
			m['S']--;
			m['I']--;
			m['X']--;
			ans.push_back(6);
		}
		while (m['S'] > 0) // seven s
		{
			m['S']--;
			m['E']--;
			m['V']--;
			m['E']--;
			m['N']--;
			ans.push_back(7);
		}
		while (m['V'] > 0) // five v
		{
			m['F']--;
			m['I']--;
			m['V']--;
			m['E']--;
			ans.push_back(5);
		}
		while (m['F'] > 0) // four f
		{
			m['F']--;
			m['O']--;
			m['U']--;
			m['R']--;
			ans.push_back(4);
		}
		while (m['G'] > 0) // eight g
		{
			m['E']--;
			m['I']--;
			m['G']--;
			m['H']--;
			m['T']--;
			ans.push_back(8);
		}
		while (m['R'] > 0) // three r
		{
			m['T']--;
			m['H']--;
			m['R']--;
			m['E']--;
			m['E']--;
			ans.push_back(3);
		}
		while (m['W'] > 0) // two w
		{
			m['T']--;
			m['W']--;
			m['O']--;
			ans.push_back(2);
		}
		while (m['O'] > 0) // one o
		{
			m['O']--;
			m['N']--;
			m['E']--;
			ans.push_back(1);
		}
		while (m['N'] > 0) // nine n
		{
			m['N']--;
			m['I']--;
			m['N']--;
			m['E']--;
			ans.push_back(9);
		}
		FOR(i, 0, 26)
		{
			if (m['A' + i] > 0)
			{
				cout << "BAD" << endl;
				break;
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << set << ": ";
		for (int i : ans)
		{
			cout << i;
		}
		cout << endl;
	}
}