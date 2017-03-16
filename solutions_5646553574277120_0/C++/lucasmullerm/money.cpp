#include <bits/stdc++.h>

using namespace std;

int mincoins = 50;
int T, c, d, v;
int den[100];
bool exists[31];

void add (set<int>& pos, int x) {
	//printf("----->coin = %d\n", x);
	vector<int> pos2;
	pos2.push_back(x);
	//printf("adding %d\n", x);
	for (set<int>::iterator it = pos.begin(); it != pos.end(); ++it)
	{
		int val = *it + x;
		if (val <= v) {
			pos2.push_back(val);
			//printf("adding %d\n", val);
		}
	}for (int i = 0; i < pos2.size(); ++i)
	{
		pos.insert(pos2[i]);
	}
}

int coin(int now, set<int> vals, int total) {
	int totalBase = total+1;
	if (totalBase >= mincoins)
		return 50;
	add(vals, now);
	if (vals.size() == v) {
		mincoins = totalBase;
		//printf("-now=%d, total=%d return=%d\n", now, total, totalBase);
		return totalBase;
	}
	int minTotal = 50;
	for (int i = now + 1; i <= v; ++i)
	{
		if (!exists[i]) {
			minTotal = min(minTotal,  coin(i, vals, totalBase));
		}
	}
	//printf("now=%d, total=%d return=%d\n", now, total, minTotal);
	return minTotal;
}


int main(int argc, char const *argv[])
{
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cin >> c >> d >> v;
		memset(exists, 0, sizeof(exists));
		for (int i = 0; i < d; ++i) {
			cin >> den[i];
			exists[i] = true;
		}
		set<int> pos;
		//printf("before\n");
		for (int i = 0; i < d; ++i)
		{
			add(pos, den[i]);
		}
		int res = 50;
		if (pos.size() == v)
			res = 0;
		else {
			for (int i = 1; i <= v; ++i)
			{
				if (!exists[i]) {
					coin(i, pos, 0);
				}
			}
		}
		if (mincoins < 50) {
			res = mincoins;
		}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}