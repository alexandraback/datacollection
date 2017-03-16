#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

vector <string> Numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector <string> Order = {};
vector <char> uniqueLetter = {};

int getNumber(string s)
{
	for (int i = 0; i < (int)Numbers.size(); i++)
	{
		if (Numbers[i] == s)
			return i;
	}
	assert(1 == 0);
}

void precalc()
{
	vector <int> used = vector <int>((int)Numbers.size(), 0);
	while (Order.size() < Numbers.size())
	{
		bool ok = false;
		for (int i = 0; i < (int)Numbers.size() && !ok; i++)
		{
			if (used[i])
				continue;
			for (char c : Numbers[i])
			{
				int cntIn = 0;
				for (int s = 0; s < (int)Numbers.size(); s++)
				{
					if (used[s])
						continue;
					bool contain = false;
					for (char cur : Numbers[s])
						if (cur == c)
							contain = true;
					if (contain)
						cntIn++;
				}
				if (cntIn == 1)
				{
					ok = true;
					Order.push_back(Numbers[i]);
					uniqueLetter.push_back(c);
					used[i] = 1;
					break;
				}
			}
		}
		assert(ok);
	}
}

const int A = 100;
int cnt[A];

void solve(string str)
{
	memset(cnt, 0, sizeof(cnt));
	for (char c : str)
		cnt[c - 'A']++;

	string number = "";
	for (int i = 0; i < (int)Order.size(); i++)
	{
		string cur = Order[i];
		char c = uniqueLetter[i];
		int value = getNumber(cur);
		while (cnt[c - 'A'] > 0)
		{
			number.push_back(value + '0');	
			for (char t : cur)
				cnt[t - 'A']--;
		}
	}
	sort(number.begin(), number.end());
	printf("%s\n", number.c_str());
}

int main()
{
	precalc();

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;
		printf("Case #%d: ", i + 1);
		solve(str);
	}
	return 0;
}
