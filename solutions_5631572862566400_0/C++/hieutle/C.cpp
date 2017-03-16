#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <vector>
// #define TEST

using namespace std;
const int MAX_N = 1005;
int n, bff[MAX_N];

int findLongest(int node, int avoid, vector<vector<int>> & aff)
{
	int res = 0;
	for (int a : aff[node]) {
		if (a != avoid)
			res = max(res, 1 + findLongest(a, 0, aff));
	}
	return res;
}

void solve(int testNumber)
{
	cin >> n;
	vector<vector<int>> aff;
	aff.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> bff[i];
		aff[bff[i]].push_back(i);
	}

	int res = 0;
	for (int start = 1; start <= n; start++)
	{
		unordered_set<int> seen;
		seen.insert(start);
		int length = 1;
		int next = bff[start];
		while (seen.find(next) == seen.end())
		{	
			seen.insert(next);
			length++;
			next = bff[next];
		}

		int cnt;
		if (bff[bff[next]] == next) {
			cnt = length;
			if (next != start) {
				cnt += findLongest(start, 0, aff);
				cnt += findLongest(bff[next], next, aff);
			} else {
				cnt += findLongest(start, bff[start], aff);
				cnt += findLongest(bff[start], start, aff);
			}
		} else {
			cnt = 1;
			int temp = next;
			next = bff[next];
			while (next != temp)
			{
				cnt++;
				next = bff[next];
			}
		}

		res = max(res, cnt);
	}
	cout << "Case #" << testNumber << ": " << res << endl;
}

int main()
{
	#ifndef TEST
	freopen("C-small-attempt5.in", "r", stdin);
	freopen("C-small-attempt5.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int test;
	cin >> test;
	for (int tt = 1; tt <= test; tt++)
	{
		solve(tt);
	}
}
