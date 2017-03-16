#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include <fstream>
#include<functional>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> res;

void go(map<char, int> &mp, string digit, char c, int num)
{
	int cnt = mp[c];

	for (int i = 0; i < cnt; i++)
		res.push_back(num);

	for (int i = 0; i < digit.size(); i++)
	{
		mp[digit[i]] -= cnt;
	}
}

int main()
{
	freopen("C:\\Users\\ibismail\\Downloads\\A-small-attempt2.in", "r", stdin);
	freopen("C:\\Users\\ibismail\\Downloads\\codejam\\out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		res.clear();
		string s;
		cin >> s;
		

		map<char, int> mp;
		for (int i = 0; i < s.size(); i++)
			mp[tolower(s[i])]++;

		go(mp, "zero", 'z', 0);
		go(mp, "two", 'w', 2);
		go(mp, "six", 'x', 6);
		go(mp, "eight", 'g', 8);
		go(mp, "three", 't', 3);
		go(mp, "four", 'u', 4);
		go(mp, "five", 'f', 5);
		go(mp, "one", 'o', 1);
		go(mp, "seven", 's', 7);
		go(mp, "nine", 'i', 9);

		sort(res.begin(), res.end());

		for (auto p : mp)
		{
			if (p.second != 0)
			{
				cout << "what" << endl;
			}
		}

		cout << "Case #" << test << ": ";
		for (int i = 0; i < res.size(); i++)
			cout << res[i];
		cout << endl;
	}

	


	return 0;
}