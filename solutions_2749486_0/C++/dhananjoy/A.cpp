#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef deque<int> VI;
typedef deque<VI> VVI;
typedef pair<int,int> PI;
typedef deque<PI> VPI;
typedef deque<VPI> VVPI;
typedef pair<ll,ll> PL;
typedef deque<ll> VL;
typedef deque<VL> VVL;

int T, X, Y, _X, _Y, cx, cy, dX, dY;
VPI v;

int sign( int x )
{
	if(x < 0)
		return -1;
	if( x > 0)
		return 1;
	return 0;
}

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		v.clear();
		cin >> _X >> _Y;
		cout << "Case #" << cs << ": ";
		cx = 0, cy = 0;
		X = abs(_X), Y = abs(_Y);
		dX = sign(_X), dY = sign(_Y);
		for (int i = 1; ; i += 1)
		{
			//cout << cx << ' ' << cy << '\n';
			if (cx + i <= X)
			{
				cx += i;
				v.pb(mp(dX,0));
				continue;
			}
			if (cy + i <= Y)
			{
				cy += i;
				v.pb(mp(0,dY));
				continue;
			}
			if(cx != X)
			{
				cx -= i;
				v.pb(mp(-dX,0));
				continue;
			}
			if(cy != Y)
			{
				cy -= i;
				v.pb(mp(0,-dY));
				continue;
			}
			break;
		}
		for (int i = 0; i < sz(v); i += 1)
		{
			if (v[i] == mp(1,0))
			{
				cout << 'E';
			}
			if (v[i] == mp(0,1))
			{
				cout << 'N';
			}
			if (v[i] == mp(-1,0))
			{
				cout << 'W';
			}
			if (v[i] == mp(0,-1))
			{
				cout << 'S';
			}
		}
		cout << '\n';
	}
	
	return 0;
}














