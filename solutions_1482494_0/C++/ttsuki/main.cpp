#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); i++)
#define REP2(i,s,n) for(int i=(s); i < (n); i++)

struct NODE {
	int game;
	int cost;
};

static inline  NODE node(int g, int c) { NODE n = { g, c, };  return n; }

bool aaa(const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }

int main()
{
	int TESTCASES; cin >> TESTCASES;
	for (int CASE = 1; CASE <= TESTCASES; CASE++)
	{
		int N; cin >> N;
		vector<pair<int, int> > need;
		REP(i,N) { int a, b; cin >> a >> b; need.push_back(make_pair(a, b)); }
		sort(need.begin(), need.end(), aaa);
		bool s1[1024] = { };
		bool s2[1024] = { };

		int r = 0;
		int s = 0;
		int m = 0;
		while(true)
		{
			REP(i, N)
			{
				if (!s1[i] && !s2[i] && need[i].second <= s)
				{
					s += 2;
					s1[i] = s2[i] = true;
					m = i;
					goto next;
				}
			}

			REP(i, N)
			{
				if (!s2[i] && need[i].second <= s)
				{
					s += 1;
					s1[i] = s2[i] = true;
					m = i;
					goto next;
				}
			}

			REP(i, N)
			{
				if (!s1[i] && need[i].first <= s)
				{
					s += 1;
					s1[i] = true;
					m = i;
					goto next;
				}
			}
			break;

next:
			r++;
		}

		bool ok = true;
		REP(i, N) ok &= s2[i];

		if (!ok)
			cout << "Case #" << CASE << ": " << "Too Bad"  << endl;
		else
			cout << "Case #" << CASE << ": " << r << endl;
	}

	return 0;
}