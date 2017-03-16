#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
string names[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int order[] = { 0, 2, 4, 1, 3, 5, 6, 7, 8, 9 };
bool used[17];
int cnt[257];
bool have(string s)
{
	bool ok = true;
	for (int i = 0; i < (int)s.length(); i++)
	{
		cnt[s[i]]--;
		if (cnt[s[i]] < 0) ok = false;
	}
	for (int i = 0; i < (int)s.length(); i++)
	{
		cnt[s[i]]++;
	}
	return ok;
}
void del(string s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		cnt[s[i]]--;
	}
}
bool haveLetter(string s, char c)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == c) return true;
	}
	return false;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	/*vector<int>perm;
	for (int i = 0; i <= 9; i++)
	{
		perm.push_back(i);
	}
	while (1)
	{
		for (int j = 0; j <= 9; j++)
		{
			used[j] = false;
		}
		bool ok = true;
		for (int i = 0; i <= 9; i++)
		{
			used[perm[i]] = true;
			bool have = false;
			for (int j = 0; j < (int)names[perm[i]].length(); j++)
			{
				bool curok = true;
				char cur = names[perm[i]][j];
				for (int k = 0; k <= 9; k++)
				{
					if (!used[k] && haveLetter(names[k], cur)) curok = false;
				}
				if (curok)
				{
					have = true;
					break;
				}
			}
			if (!have)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			for (int i = 0; i <= 9; i++)
			{
				printf("%d, ", perm[i]);
			}
			return 0;
		}
		assert(next_permutation(perm.begin(), perm.end()));
	} */
	for (int tt = 1; tt <= t; tt++)
	{
		string s;
		cin >> s;
		vector<pair<int, int>>haveh;
		for (int i = 0; i <= 9; i++)
		{
			haveh.push_back(make_pair(names[i].length(), i));
		}
		sort(haveh.rbegin(), haveh.rend());
		for (int i = 0; i < 257; i++)
		{
			cnt[i] = 0;
		}
		for (int i = 0; i < (int)s.length(); i++)
		{
			cnt[s[i]]++;
		}
		string res;
		for (int i = 0; i <= 9; i++)
		{
			while (have(names[order[i]]))
			{
				del(names[order[i]]);
				res = res + (char)(order[i] + '0');
			}
		}
		for (int i = 0; i < 257; i++)
		{
			assert(cnt[i] == 0);
		}
		sort(res.begin(), res.end());
		cout << "Case #" << tt << ": " <<  res << '\n';
	}
}
