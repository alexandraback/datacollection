#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <stdint.h>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

#define forl(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int64_t hackx, hacky;

#define zabs(a) ((a)>0)?(a):(-1*(a))

int shittydist(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2) + abs(y1-y2);//zabs(x1 + y1 -x2 -y2);
}

struct shittystate
{
	int64_t x;
	int64_t y;
	string path;
	shittystate(int64_t _x, int64_t _y, string _path) { x = _x; y = _y; path = _path; }
	bool operator>(const shittystate& other) const
	{
		return ((shittydist(x,y,hackx, hacky) ) > (shittydist(other.x, other.y, hackx, hacky) ));//^((path.length()&1)&other.path.length()&1);
	}
};

string solve(int64_t cx, int64_t cy, int64_t dx, int64_t dy)
{
	hackx = dx;
	hacky = dy;
	priority_queue<shittystate,vector<shittystate>,greater<shittystate> > myqueue;
	myqueue.push(shittystate(cx,cy,""));
	string dir = "";

	while (!myqueue.empty())
	{
		shittystate st = myqueue.top();
		myqueue.pop();

		if (st.x == dx && st.y == dy) return st.path;

		//cerr << "Investigating \"" << st.path << "\" at (" << st.x << ", " << st.y << ")\n";

		int64_t d = st.path.length()+1;
		//int64_t d = (p * (p+1))/2;
		//cerr << "p = " << p << ", d = " << d << endl;

		myqueue.push(shittystate(st.x, st.y+d, st.path + "N"));
		myqueue.push(shittystate(st.x, st.y-d, st.path + "S"));
		myqueue.push(shittystate(st.x-d, st.y, st.path + "W"));
		myqueue.push(shittystate(st.x+d, st.y, st.path + "E"));
		//myqueue.push(shittystate(st.x+1, st.y, st.path + "EW"));
		//myqueue.push(shittystate(st.x-1, st.y, st.path + "WE"));
		//myqueue.push(shittystate(st.x, st.y+1, st.path + "NS"));
		//myqueue.push(shittystate(st.x, st.y-1, st.path + "SN"));
	}

	return "ERROR!";

}

string hacksolve(int64_t cx, int64_t cy, int64_t dx, int64_t dy)
{
	string outs = "";
	if (dx < cx)
	{
		while (dx < cx)
		{
			outs += "EW";
			dx++;
		}
	}
	else
	{
		while (dx > cx)
		{
			outs += "WE";
			dx --;
		}
	}

	if (dy < cy)
	{
		while (dy < cy)
		{
			outs += "NS";
			dy++;
		}
	}
	else
	{
		while (dy > cy)
		{
			outs += "SN";
			dy --;
		}
	}
	return outs;
}


int main(int argc, char **argv)
{
	int numCases = 0;
	cin >> numCases;
	forl(testCase,1,numCases+1)
	{
		int64_t x, y;
		cin >> x >> y;
		cout << "Case #" << testCase << ": " << " My A* implementation looks fucked!\n"; ;// << solve(0,0,x,y) << endl;

	}

	return 0;
}
