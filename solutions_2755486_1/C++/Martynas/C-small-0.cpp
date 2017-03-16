#include <cstdio>
#include <map>
#include <vector>
#define MAXDAYS 677777
#define INF 2000000000

using namespace std;

struct Attack
{
	int w, e, s;
	Attack(int _w, int _e, int _s):
		w(_w), e(_e), s(_s)
	{ }
};

bool success(map<int, int>& wall, Attack& attack)
{
	map<int, int>::iterator it = --(wall.upper_bound(attack.w));
	while (it->first < attack.e)
	{
		if (it->second < attack.s) return true;
		++it;
	}
	return false;
}

void update(map<int, int>& wall, Attack& attack)
{
	map<int, int>::iterator it = --(wall.upper_bound(attack.w));
	int last = it->second;
	if (attack.s > last)
	{
		if (it->first < attack.w)
		{
			it = wall.insert(it, make_pair(attack.w, attack.s));
		}
		else
		{
			it->second = attack.s;
		}
	}
	for (++it; it != wall.end() && it->first < attack.e;)
	{
		if (it->second <= attack.s)
		{
			if (last <= attack.s)
			{
				last = it->second;
				wall.erase(it++);
				continue;
			}
			else
			{
				last = it->second;
				it->second = attack.s;
			}
		}
		else
		{
			last = it->second;
		}
		++it;
	}
	if (it == wall.end())
	{
		wall.insert(it, make_pair(attack.e, 0));
	}
	else if (it->first > attack.e && last < attack.s)
	{
		wall.insert(it, make_pair(attack.e, last));
	}
}

int solve()
{
	vector<vector<Attack> > days(MAXDAYS);
    int ans = 0, N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int d, n, w, e, s, dd, dp, ds;
		scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
		for (int i = 0; i < n; ++i)
		{
			days[d].push_back(Attack(w, e, s));
			d += dd;
			w += dp;
			e += dp;
			s += ds;
		}
	}
	map<int, int> wall;
	wall.insert(make_pair(-INF, 0));
	for (int day = 0; day < MAXDAYS; ++day)
	{
		for (int i = 0; i < days[day].size(); ++i)
		{
			ans += success(wall, days[day][i]);
		}
		for (int i = 0; i < days[day].size(); ++i)
		{
			update(wall, days[day][i]);
		}
	}
    return ans;
}

int main()
{
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: %d\n", t, solve());
    }
}
