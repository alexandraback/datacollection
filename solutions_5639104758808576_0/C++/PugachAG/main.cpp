#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <map>
#include <cctype>

using namespace std;

bool check(vector<int> &a)
{
	int s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (s < i)
			return false;
		s += a[i];
	}
	return true;
}

int test_case(string str)
{
	vector<int> a;
	for (char ch : str)
		a.push_back(ch - '0');
	for (int res = 0;; res++)
	{
		if (check(a))
			return res;
		a[0]++;
	}
}

int main()
{
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> n >> str;
		int res = test_case(str);
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
}