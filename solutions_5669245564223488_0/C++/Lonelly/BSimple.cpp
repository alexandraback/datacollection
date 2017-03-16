#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

bool check(vector<string> &s, int* a)
{
	/*string s0;
	for (int i = 0; i < s.size(); ++i)
	{
		s0 += s[a[i]];
	}
	vector<int> p(26, -1);
	for (int i = 0; i < s0.size(); ++i)
	{
		if (p[s0[i] - 'a'] != -1 && (p[s0[i] - 'a'] != i - 1))
		{
			return false;
		}
		p[s0[i] - 'a'] = i;
	}*/
	vector<int> p(26, -1);
	int i = 0;
	for (int j = 0; j < s.size(); ++j)
	{
		for (int k = 0; k < s[a[j]].size(); ++k)
		{
			if (p[s[a[j]][k] - 'a'] != -1 && (p[s[a[j]][k] - 'a'] != i - 1))
			{
				return false;
			}
			p[s[a[j]][k] - 'a'] = i;
			++i;
		}
	}
	return true;
}

int count(vector<string>& s)
{
	int result = 0;
	int a[1000];
	for (int i = 0; i < s.size(); ++i)
	{
		a[i] = i;
	}
	do {
		if (check(s, a))
		{
			++result;
		}
	} while (next_permutation(a, a + s.size()));
	return result;
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
	cout << count(s);
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