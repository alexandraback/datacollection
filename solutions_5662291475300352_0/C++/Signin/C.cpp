#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define USEFILE

typedef long long ll;

struct group{

	ll s, p, t;
	group(ll s_, ll p_, ll t_)
	{
		s = s_;
		p = p_;
		t = t_;
	}

	group(){};

};

struct person{

	ll s;
	double v;	// start, velocity(speed)
};



int main(void)
{
#ifdef USEFILE
	FILE* inf = freopen("C.in", "r", stdin);
	FILE* outf = freopen("C_out.txt.", "w", stdout);
#endif

	int tc;
	cin >> tc;

	for(int testNum = 1; testNum <= tc; testNum++)
	{
		ll n;
		cin >> n;

		group groups[2];

		for(int i = 0; i < n; i++)
		{
			ll s, p, t; //startPos, peopleNum, time of 1 rev(fastest person)
			cin >> s >> p >> t;

			groups[i] = group(s, p, t);
		}

		if(n == 1 && groups[0].p == 1)
		{
			cout << "Case #" << testNum << ": " << 0 << endl;
			continue;
		}

		person slow, fast;
		if(n == 1)
		{	
			slow.s = groups[0].s;
			slow.v = 360 / (double)(groups[0].t + 1);

			fast.s = groups[0].s;
			fast.v = 360 / (double)groups[0].t;
		}
		else
		{
			slow.s = groups[0].s;
			slow.v = 360 / (double)groups[0].t;

			fast.s = groups[1].s;
			fast.v = 360 / (double)groups[1].t;

			if(slow.v > fast.v)
				swap(slow, fast);
		}

		if(slow.s == fast.s)
		{
			double t1 = (360 - slow.s) / slow.v;
			double t2 = (720 - fast.s) / fast.v;

			if(t1 < t2)
				cout << "Case #" << testNum << ": " << 0 << endl;
			else
				cout << "Case #" << testNum << ": " << 1 << endl;
		}
		else if(slow.s < fast.s)
		{
			double t1 = (360 - slow.s) / slow.v;
			double t2 = (720 - fast.s) / fast.v;

			if(t1 < t2)
				cout << "Case #" << testNum << ": " << 0 << endl;
			else
				cout << "Case #" << testNum << ": " << 1 << endl;
		}
		else
		{
			double t1 = (360 - slow.s) / slow.v;
			double t2 = (720 - fast.s) / fast.v;

			if(t1 < t2)
				cout << "Case #" << testNum << ": " << 0 << endl;
			else
				cout << "Case #" << testNum << ": " << 1 << endl;
		}
	}


#ifdef USEFILE
	fclose(inf);
	fclose(outf);
#endif

	return 0;
}