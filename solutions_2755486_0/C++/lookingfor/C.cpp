#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, pair<int, int> > Attack; // day, strength, start, end
//typedef vector<pair<pair<int, int>, int> > Wall;
typedef map<int, pair<int, int> > Wall; // start, end, strength

bool isSuccess(Wall& wall, Attack& attack)
{
	int strength = attack.first.second, a = attack.second.first, b = attack.second.second;
	auto it = wall.lower_bound(a);
	if (it == wall.end() || it->first > a)
		return true;
	int coveredTill = a;
	while (it != wall.end())
	{
		if (it->second.second < strength)
			break;
		if (it->first > coveredTill)
			break;
		coveredTill = it->second.first;
		++it;
	}
	return coveredTill >= b;
}

void addToWall(Wall& wall, Attack& attack)
{
	int strength = attack.first.second, a = attack.second.first, b = attack.second.second;
	auto it = wall.lower_bound(a);
	vector<pair<pair<int, int>, int> > intervals;
	for (;it != wall.end() && it->first < b; ++it)
		intervals.push_back(make_pair(make_pair(it->first, it->second.first), it->second.second));
	if (intervals.size() == 0)
	{
		wall[a] = make_pair(b, strength);
	}
	else 
	{
		if (intervals[0].first.first > a) 
		{
			wall[a] = make_pair(intervals[0].first.first, strength);
			a = intervals[0].first.first;
		}
		for (int i = 0; i < intervals.size(); )
		{
			int from = i;
			while (i < intervals.size() && intervals[i].second < strength) ++i;
			if (i > from)
			{
				for (int j = from; j < i; ++j)
					wall.erase(intervals[j].first.first);
				wall[a] = make_pair(intervals[i-1].first.second, strength);
			}
			while (i < intervals.size() && intervals[i].second >= strength) ++i;
			a = intervals[i-1].first.second;
		}
		if (a < b)
			wall[a] = make_pair(b, strength);
	}
}

int main()
{
	int t;
	cin>>t;
	for (int z = 0, x, y; z < t; ++z)
	{
		cerr<<z<<endl;
		int N;
		cin>>N;

		vector<Attack> attacks;
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			int d, n, w, e, s, dd, dp, ds;
			cin>>d>>n>> w>> e>> s>> dd>> dp>> ds;
			for (int j = 0; j < n; ++j)
				attacks.push_back(make_pair(make_pair(d + j*dd, s + j*ds), make_pair(w + j*dp, e + j*dp)));
		}
		sort(attacks.begin(), attacks.end());

		Wall wall;

		for (int i = 0; i < attacks.size(); )
		{
			int to = i;
			int currentDay = attacks[i].first.first;
			while (to < attacks.size() && currentDay == attacks[to].first.first) ++to;

			for (int j = i; j < to; ++j)
				res += isSuccess(wall, attacks[j]);

			for (int j = i; j < to; ++j)
				addToWall(wall, attacks[j]);
			i = to;
		}
				
		cout<<"Case #"<<(z+1)<<": "<<res<<endl;
	}
	return 0;
}

