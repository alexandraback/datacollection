#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

const int M = 1e9 + 7;

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

long long fact(int x)
{
	long long ans = 1;
	for (long long i = 1; i <= x; i++)
		ans = (ans * i) % M;
	return ans;
}

int solve_clever(vector <string> barr)
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
	
	long long ans = 1;
	map <string, int> same;
	vector <string> diff;
	for (int i = 0; i < n; i++)
		if (arr[i][0] == arr[i][1])
			same[arr[i]]++;
		else
			diff.push_back(arr[i]);
	for (auto it = same.begin(); it != same.end(); it++)
	{
		ans = (ans * fact(it->second)) % M;
		bool need = true;
		for (int i = 0; i < diff.size(); i++)
			if (diff[i][0] == it->first[0] || diff[i][1] == it->first[0])
				need = false;
		if (need)
			diff.push_back(it->first);
	}
	int mask = 0;
	for (int i = 0; i < diff.size(); i++)
	{
		if (diff[i][0] == diff[i][1])
			continue;
		int idx = diff[i][0] - 'a';
		if (mask & (1 << idx))
			return 0;
		mask |= (1 << idx);
	}

	mask = 0;
	for (int i = 0; i < diff.size(); i++)
	{
		if (diff[i][0] == diff[i][1])
			continue;
		int idx = diff[i][1] - 'a';
		if (mask & (1 << idx))
			return 0;
		mask |= (1 << idx);
	}

	bool n_iter = true;
	vector <bool> con(diff.size(), 0);
	while (n_iter)
	{
		n_iter = false;
		vector <string> curr;
		vector <bool> ncon;
		for (int i = 0; i < diff.size() && !n_iter; i++)
			for (int j = 0; j < diff.size() && !n_iter; j++)
				if (i != j && diff[i][1] == diff[j][0])
				{
					n_iter = true;
					curr.push_back(string(diff[i].begin(), diff[i].begin() + 1) + string(diff[j].end() - 1, diff[j].end()));
					ncon.push_back(true);
					for (int k = 0; k < diff.size(); k++)
						if (k != i && k != j)
						{
							curr.push_back(diff[k]);
							ncon.push_back(con[k]);
						}
					diff = curr;
					con = ncon;
				}
	}

	for (int i = 0; i < diff.size(); i++)
		if (diff[i][0] == diff[i].back() && con[i])
			return 0;

	ans = (ans * fact(diff.size())) % M;

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
//		int ans = solve(arr);
		int test = solve_clever(arr);
//		if (ans != test) 
//		{
//			throw(0);
//		}
		printf("Case #%d: %d\n", t + 1, test);
	}
	
}