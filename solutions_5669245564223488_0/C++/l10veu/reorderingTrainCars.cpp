#include <cstdio>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct InitCarSet;

int n;
bool used[100];
std::vector<InitCarSet> inits;
int cnt;

struct InitCarSet
{
	InitCarSet()
		: set(0), first(0), last(0)
	{

	}

	InitCarSet(int set, char first, char last)
		: set(set), first(first), last(last)
	{

	}

	int set;
	char first;
	char last;
};

struct CarSet
{
	CarSet()
		: set(0), last(0)
	{

	}

	CarSet(int set, char last)
		: set(set), last(last)
	{

	}
	
	int set;
	char last;
};

InitCarSet makeInitCarSet(const std::string& str)
{
	char first = str.front() - 'a';
	char last = str.back() - 'a';
	int set = 0;
	for (auto c : str)
	{
		set |= 1 << (c - 'a');
	}

	return InitCarSet(set, first, last);
}

bool checkStr(const std::string& str)
{
	bool found[26];
	std::fill(found, found+26, false);

	char prev = str.front();
	found[prev-'a'] = true;
	for (int i=1; i<str.size(); ++i)
	{
		char c = str[i];
		if (found[c-'a'] == true && prev != c)
			return false;

		found[c-'a'] = true;
	}
	
	return true;
}

void solve2(int d, CarSet carSet)
{
	if (d==n)
	{
		++cnt;
	}

	for (int i=0; i<n; ++i)
	{
		if (used[i])
			continue;

		int intersect = carSet.set & inits[i].set;
		int cnt = 0;
		for (int j=0; j<26; ++j)
		{
			if ((intersect & (1<<j)) != 0)
				++cnt;
		}
		
		if (cnt == 0 || (cnt == 1 && carSet.last == inits[i].first))
		{
			used[i] = true;
			solve2(d + 1, CarSet(carSet.set | inits[i].set, inits[i].last));
			used[i] = false;
		}
	}
}

int solve()
{
	scanf("%d", &n);	
	std::fill(used, used+100, false);
	inits.clear();
	cnt = 0;
	
	for (int i=0; i<n; ++i)
	{
		char cs[101];
		scanf("%s", cs);

		InitCarSet carSet = makeInitCarSet(cs);
		inits.push_back(carSet);
	}
	
	for (int i=0; i<n; ++i)
	{
		used[i] = true;
		solve2(1, CarSet(inits[i].set, inits[i].last));
		used[i] = false;
	}

	return cnt;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; ++i)
	{
		printf("Case #%d: %d\n", i, solve());
	}
	
	return 0;
}