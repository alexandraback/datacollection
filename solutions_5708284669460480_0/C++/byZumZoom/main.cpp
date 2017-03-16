#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

string alph, word;
vector <int> words;
int n;

void rec(string cur)
{
	if(cur.length() == n)
	{
		int cur_pos = cur.find(word);
		int res = 0;
		while(cur_pos != string::npos)
		{
			res++;
			cur_pos = cur.find(word, cur_pos + 1);
		}
		words.push_back(res);
		return;
	}

	for(int i = 0; i < alph.length(); ++i)
	{
		rec(cur + alph[i]);
	}
}

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		int k, l;
		cin >> k >> l >> n;

		cin >> alph;
		cin >> word;
		words.clear();

		rec("");

		int bananas = 0;
		int expected = 0;
		for(int i = 0; i < words.size(); ++i)
		{
			bananas = max(words[i], bananas);
			expected += words[i];
		}

		double exp = 1.0 * expected / words.size();
		double res = bananas - exp;

		printf("Case #%d: %.6lf\n", test, res);
	}

	return 0;
}
