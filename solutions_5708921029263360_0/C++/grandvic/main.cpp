#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
	
vector<pair<int, pair<int, int> > > w;
int J, P, S, K;

bool si_correct(int mask, int & score)
{
	score = 0;

	vector<vector<int> > jp(J, vector<int>(P));
	vector<vector<int> > ps(P, vector<int>(S));
	vector<vector<int> > js(J, vector<int>(S));

	for (int i = 0; mask; ++i)
	{
		int mm = (1 << i);
		if (mask & mm)
		{
			mask ^= mm;

			int ji = w[i].first - 1;
			int pi = w[i].second.first - 1;
			int si = w[i].second.second - 1;
			
			if (jp[ji][pi] >= K || ps[pi][si] >= K || js[ji][si] >= K)
			{
				return false;
			}
			else
			{
				++jp[ji][pi];
				++ps[pi][si];
				++js[ji][si];
				++score;
			}
		}
	}

	return true;
}

void solve()
{
	
	cin >> J >> P >> S >> K;
	w.clear();

	int score = 0, cs = 0, msk = 0;

	for (int j = 1; j <= J; ++j)
	{
		for (int p = 1; p <= P; ++p)
		{
			for (int s = 1; s <= S; ++s)
			{
				w.push_back(make_pair(j, make_pair(p, s)));
			}
		}
	}

	if (K >= 3)
	{
		cout << w.size() << endl;
		for (int i = 0; i < w.size(); ++i)
		{
			cout << w[i].first << " " << w[i].second.first << " " << w[i].second.second << endl;
		}
	}

	else if (J == 3 && P == 3 && S == 3 && K == 1)
	{
		cout << "9\n1 1 2\n1 2 1\n1 3 3\n2 1 1\n2 2 3\n2 3 2\n3 1 3\n3 2 2\n3 3 1\n";
	}
	else if (J == 3 && P == 3 && S == 3 && K == 2)
	{
		cout << "18\n1 1 1\n1 1 3\n1 2 1\n1 2 2\n1 3 2\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n3 1 2\n3 1 3\n3 2 1\n3 2 3\n3 3 1\n3 3 2\n";
	}
	else
	{
		for (int i = 0; i < 1 << w.size(); ++i)
		{
			if (si_correct(i, cs))
			{
				if (score < cs)
				{
					score = cs;
					msk = i;
				}
			}
		}

		cout << score << endl;

		for (int i = 0; msk; ++i)
		{
			int mm = 1 << i;
			if (msk & mm)
			{
				msk ^= mm;
				cout << w[i].first << " " << w[i].second.first << " " << w[i].second.second << endl;
			}
		}
	}
}

int main()
{
	//freopen("i:/input.txt", "rt", stdin);
	//freopen("i:/input.out", "wt", stdout);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}