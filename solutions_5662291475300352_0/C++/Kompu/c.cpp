#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

struct Hiker
{
	double pos, speed;
	Hiker(double p, double s)
	{
		pos = p;
		speed = s;
	}
	void Update(double time)
	{
		pos += speed * time;
		while(pos >= 360.0) pos -= 360.0;
	}
	double TimeToGo(double p)
	{
		double delta = p - pos;
		return delta / speed;
	}
};

double Meeting(Hiker a, Hiker b)
{
	if(a.speed == b.speed) return 0.0;
	if(a.speed > b.speed) swap(a, b);
	if(a.pos <= b.pos)
	{
		double t = b.TimeToGo(360.0);
		a.Update(t);
		b.pos = 0.0;
	}
	double t = (a.pos - b.pos) / (b.speed - a.speed);
	return a.pos + a.speed * t;
}

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int n, d, h, m, w = 0;
		cin >> n;
		vector<Hiker> hikers;
		REP(x, n)
		{
			cin >> d >> h >> m;
			REP(y, h)
			{
				hikers.PB(Hiker(d, 1.0 / m));
				m++;
			}
		}
		auto actual = hikers.begin();
		for(auto it = hikers.begin(); it != hikers.end(); it++)
		{
			if((*it).pos < (*actual).pos)
				actual = it;
		}
		if(SIZE(hikers) == 2)
		{
			double p = Meeting(hikers[0], hikers[1]);
			// cout << p << endl;
			if(p <= 360.0)
				w = 1;
		}
		cout << "Case #" << o << ": " << w << endl;
	}
	return 0;
}