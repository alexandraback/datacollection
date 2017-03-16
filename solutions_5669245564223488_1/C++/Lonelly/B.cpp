#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

int classify(string s, char c)
{
	int groups = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == c && (i == 0 || s[i - 1] != c))
		{
			++groups;
		}
	}
	if (groups > 1)
	{
		return -1;
	}
	if (groups == 0)
	{
		return 0;
	}
	if (groups == 1 && s[0] == c && s[s.size() - 1] == c)
	{
		return 1;
	}
	if (s[0] == c)
	{
		return 2;
	}
	return 3;
}

void paint(vector<int> &group, int g1, int g2)
{
	for (int i = 0; i < group.size(); ++i)
	{
		if (group[i] == g1)
		{
			group[i] = g2;
		}
	}
}

void solve(int index)
{
	cout << "Case #" << index + 1 << ": ";
	int N;
	cin >> N;
	unsigned long long result = 1;
	vector<string> s(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> s[i];
	}
	vector<set<int>> b(27), e(27);
	int groups = 0;
	int groupsCnt = 0;
	vector<int> group(N + 1, 0);
	vector<int> groupC(27, 0);
	for (char c = 'a'; c <= 'z'; ++c)
	{
		unsigned long long beg = 0, end = 0, all = 0;
		vector<int> used;
		set<int> bl, el;
		for (int i = 0; i < N; ++i)
		{
			int cl = classify(s[i], c);
			if (cl == -1)
			{
				cout << 0 << endl;
				return;
			}
			if (cl == 1)
			{
				++all;
				used.push_back(i);
			}
			if (cl == 2)
			{
				++beg;
				bl.insert(i);
				used.push_back(i);
			}
			if (cl == 3)
			{
				++end;
				el.insert(i);
				used.push_back(i);
			}
		}
		if (used.size())
		{
			++groups;
			++groupsCnt;
			++groupC[groups];
			b[groups].insert(bl.begin(), bl.end());
			e[groups].insert(el.begin(), el.end());
			for (int i = 0; i < used.size(); ++i)
			{
				if (group[used[i]] != 0 && group[used[i]] != groups)
				{
					if (beg == 1 && end == 1)
					{
						if (b[group[used[i]]].find(*(el.begin())) != b[group[used[i]]].end() &&
							e[group[used[i]]].find(*(bl.begin())) != e[group[used[i]]].end())
						{
							cout << 0 << endl;
							return;
						}
					}
					b[groups].insert(b[group[used[i]]].begin(), b[group[used[i]]].end());
					e[groups].insert(e[group[used[i]]].begin(), e[group[used[i]]].end());
					groupC[groups] += groupC[group[used[i]]];
					paint(group, group[used[i]], groups);
					--groupsCnt;
				}
				group[used[i]] = groups;
			}
			int be = 0;
			for (int i = 0; i < N; ++i)
			{
				if (b[groups].find(i) != b[groups].end() && e[groups].find(i) != e[groups].end())
				{
					++be;
				}
			}
			if (be == groupC[groups])
			{
				cout << 0 << endl;
				return;
			}
		}
		if (beg > 1 || end > 1)
		{
			cout << 0 << endl;
			return;
		}
		for (int i = 1; i <= all; ++i)
		{
			result *= i;
			result = result % 1000000007;
		}
	}
	for (int i = 1; i <= groupsCnt; ++i)
	{
		result *= i;
		result = result % 1000000007;
	}
	/*if ((b.size() == 1 && e.size() == 1 && b[0] == e[0]))
	{
		cout << 0 << endl;
		return;
	}*/
 	cout << result;
	cout << endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && string(argv[1]) == "-d")
	{
		cout << "Sleep for 15 seconds" << endl;
		Sleep(10 * 1000);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}