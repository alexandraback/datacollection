#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <cstdio>
#include <cassert>
#include <stack>
#include <unordered_set>

#define mp make_pair
#define mt(x,y,z) mp((x), mp((y), (z)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// globals starts here

int freq[256];

string names[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void subnum(int num, int count)
{
	for (int j = 0; j < names[num].size(); ++j)
	{
		freq[names[num][j]] -= count;
	}
}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#elif defined(CONTEST)
	freopen(CONTEST ".in", "r", stdin);
	freopen(CONTEST ".out", "w", stdout);
#endif

	cin.sync_with_stdio(false);
	int tests;
	cin >> tests;

	for (int tc = 1; tc <= tests; ++tc)
	{
		string s;
		cin >> s;
		ZERO(freq);

		for (int i = 0; i < s.size(); ++i)
		{
			freq[s[i]]++;
		}

		vector<int> ans(10, 0);
		
		ans[0] = freq['Z'];
		subnum(0, ans[0]);
		ans[2] = freq['W'];
		subnum(2, ans[2]);
		ans[4] = freq['U'];
		subnum(4, ans[4]);
		ans[6] = freq['X'];
		subnum(6, ans[6]);
		ans[8] = freq['G'];
		subnum(8, ans[8]);
		ans[1] = freq['O'];
		subnum(1, ans[1]);
		ans[3] = freq['H'];
		subnum(3, ans[3]);
		ans[5] = freq['F'];
		subnum(5, ans[5]);
		ans[7] = freq['S'];
		subnum(7, ans[7]);
		ans[9] = freq['I'];
		subnum(9, ans[9]);
			
		for (int i = 0; i < 256; ++i)
		{
			assert(freq[i] == 0);
		}

		cout << "Case #" << tc << ": ";
		for (int i = 0; i < ans.size(); ++i)
		{
			for (int j = 0; j < ans[i]; ++j)
			{
				cout << i;
			}
		}
		cout << endl;
	}

	return 0;
}