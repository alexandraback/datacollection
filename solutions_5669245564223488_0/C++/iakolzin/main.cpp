#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

pair <string, string> strans(string s)
{
	int n = s.length();
	if (n == 1)
		return make_pair(s + s, "");
	if (n == 2)
		return make_pair(s, "");
	char prev = s[0];
	string rem = "";
	string res = string(s.begin(), s.begin() + 1) + string(s.end() - 1, s.end());
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] != prev)
		{
			if (count)
				rem.push_back(prev);
			count++;
			prev = s[i];
		}
	}
	return make_pair(res, rem);
}

int solve(vector <string> barr)
{
	int n = barr.size();
	vector <string> arr;
	map <char, int> rem;
	for (int i = 0; i < n; i++)
	{
		pair <string, string> a = strans(barr[i]);
		arr.push_back(a.first);
		if (a.first[0] == a.first[1] && a.second != "")
			return 0;
		for (int j = 0; j < a.second.length(); j++)
		{
			rem[a.second[j]]++;
			if (rem[a.second[j]] > 1)
				return 0;
		}
	}
	for (int i = 0; i < n; i++)
		if (rem.count(arr[i][0]) || rem.count(arr[i][1]))
			return 0;
	vector <int> perm(n);
	for (int i = 0; i < n; i++)
		perm[i] = i;
	int ans = 0;
	do
	{
		int mask = 0;
		char prev = 0;
		bool ok = true;
		for (int i = 0; i < n && ok; i++)	
		{
			string& cur = arr[perm[i]];
			for (int j = 0; j < cur.length() && ok; j++)
			{
				if (prev != 0 && cur[j] != prev)
				{
					if (mask & (1 << (prev - 'a')))
						ok = false;
					mask |= (1 << (prev - 'a'));
				}
				prev = cur[j];
			}
		}
		if (mask & (1 << (prev - 'a')))
			ok = false;
		if (ok)
			ans++;
	} while (next_permutation(perm.begin(), perm.end()));

	return ans;
}

int solve_stupid(vector <string> arr)
{
	int n = arr.size();
	vector <int> perm(n);
	for (int i = 0; i < n; i++)
		perm[i] = i;
	int ans = 0;
	do
	{
		char prev = 0;
		int mask = 0;
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			string& cur = arr[perm[i]];
			for (int j = 0; j < cur.length(); j++)
			{
				if (prev != 0 && cur[j] != prev)
				{
					if (mask & (1 << (prev - 'a')))
						ok = false;
					mask |= 1 << (prev - 'a');
				}
				prev = cur[j];
			}
		}
		if (mask & (1 << (prev - 'a')))
			ok = false;
		if (ok)
			ans++;
	} while (next_permutation(perm.begin(), perm.end()));

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n;
		cin >> n;
		vector <string> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = solve(arr);
/*		int test = solve_stupid(arr);
		if (ans != test) 
		{
			cout << "ALERT! ans = " << ans << " test = " << test << endl;
		}*/
		printf("Case #%d: %d\n", t + 1, solve(arr));
	}
	
}