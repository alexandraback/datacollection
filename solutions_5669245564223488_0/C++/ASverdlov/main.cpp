#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define db(v) cout << #v << " = " << (v) << endl;
#define ST 0
#define MID 1
#define EN 2
#define INS 3
typedef long long ll;

const int modulo = 1e9 + 7;

int T;
vector<string> s;
char used[31];

int charToInt(char c)
{
	return int(c - 'a');
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		s.clear();
		printf("Case #%d: ", t + 1);
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
		{
			string e;
			cin >> e;
			s.push_back(e);
		}
		vector<int> vec;
		for (int i = 0; i < N; ++i) vec.push_back(i);

		int ans = 0;

		do
		{
			bool good = true;
			memset(used, 0, sizeof(used));
			int prev = -1;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < s[vec[i]].length(); ++j)
				{
					int cur = charToInt(s[vec[i]][j]);
					if (cur != prev)
					{
						if (used[cur]) good = false;
						used[cur] = true;
					}
					prev = cur;
				}
			}
			if (good) ++ans;
		}
		while (next_permutation(vec.begin(), vec.end()));
		printf("%d\n", ans);
	}

	return 0;
}
