#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

pair<long long, int> toys[120], boxes[120];
int n, m;
long long totaln, totalm;

bool cmp(pair<long long, int> a, pair<long long, int> b)
{
	return a.first < b.first;
}

long long fAns(long long rem, long long remB, int type, int box)
{
	if (type >= n || box >= m)
		return 0;
	long long ans = -1;
	if (toys[type].second == boxes[box].second)
	{
		if (rem > remB)
		{
			ans = max(ans, remB + fAns(rem - remB, boxes[box + 1].first, type, box + 1));
		}
		else if (remB > rem)
		{
			ans = max(ans, rem + fAns(toys[type + 1].first, remB - rem, type + 1, box));
		}
		else
		{
			ans = max(ans, rem + fAns(toys[type + 1].first, boxes[box + 1].first, type + 1, box + 1));
		}
	}
	else
	{
		ans = max(ans, fAns(toys[type + 1].first, remB, type + 1, box));
		ans = max(ans, fAns(rem, boxes[box + 1].first, type, box + 1));
	}
	return ans;
}

int main()
{
	ifstream in("box.in");
	ofstream out("box.out");

	int T;
	in >> T;

	for (int c = 1; c <= T; c++)
	{
		in >> n >> m;
		totaln = totalm = 0;
		for (int i = 0; i < n; i++)
		{
			in >> toys[i].first >> toys[i].second;
		}
		for (int i = 0; i < m; i++)
		{
			in >> boxes[i].first >> boxes[i].second;
		}
		long long rem = toys[0].first;
		out << "Case #" << c << ": " << fAns(rem, boxes[0].first, 0, 0) << '\n';
	}
	return 0;
}

