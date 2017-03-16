#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Event
{
	Event(int t, int s, int l, int r)
		: time(t)
		, str(s)
		, left(min(l, r))
		, right(max(l, r))
	{
	}

	int time;
	int left;
	int right;
	int str;

	bool operator<(const Event & that) const
	{
		return time < that.time;
	}
};


struct Seg
{
	Seg(int ll, int rr, int hh) : l(ll), r(rr), h(hh) {}

	int l;
	int r;
	int h;

	bool operator<(const Seg & that) const
	{
		if(l < that.l)
			return true;

		if(l > that.l)
			return false;

		return r < that.r;
	}
};


struct Segs
{
	vector<Seg> list;

	bool test(int l, int r, int h)
	{
		for(int i = 0; i < (int)list.size(); i++)
		{
			Seg & s = list[i];
			if(s.h < h)
				continue;

			if(s.l > l)
				return false;

			if(s.r >= r)
				return true;

			l = max(l, s.r);
		}

		return false;
	}

	void update(int l, int r, int h)
	{
		list.push_back(Seg(l, r, h));
		sort(list.begin(), list.end());
	}
};


void solve()
{
	vector<Event> evs;

	{
		int total;
		cin >> total;

		for(int i = 0; i < total; i++)
		{
			int d, n, w, e, s, dd, dp, ds;
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;

			for(int j = 0; j < n; j++)
				evs.push_back(Event(d + dd * j, s + ds * j, w + dp * j, e + dp * j));
		}
	}

	sort(evs.begin(), evs.end());

	Segs s;
	int res = 0;

	for(int l = 0; l < (int)evs.size(); )
	{
		int r = l;
		while(r < (int)evs.size() && evs[r].time == evs[l].time)
			r++;

		for(int i = l; i < r; i++)
			if(!s.test(evs[i].left, evs[i].right, evs[i].str))
				res++;

		for(int i = l; i < r; i++)
			s.update(evs[i].left, evs[i].right, evs[i].str);

		l = r;
	}

	cout << res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t;
	scanf("%i\n", &t);

	for(int ti = 1; ti <= t; ti++)
	{
		cout << "Case #" << ti << ": ";
		solve();
		cout << "\n";
	}

	return 0;
}
