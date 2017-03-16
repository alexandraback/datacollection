#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)

template<class T>
struct vec2_t
{
	T x, y;
	vec2_t(T x=T(), T y=T()) : x(x), y(y) {}
	bool operator < (const vec2_t& b) const { return b.x<x || (x==b.x && y<b.y); }
	bool operator == (const vec2_t& b) const { return b.x == x && b.y == y; }
	bool operator != (const vec2_t& b) const { return !(*this == b); }
};

typedef vec2_t<int> vec2;

struct isect
{
	vec2 p1,p2;
	bool flipX;

	bool operator < (const isect& b) const
	{
		if(p1 == b.p1) return flipX;
		else return p1.x + p1.y < b.p1.x + b.p1.y;
	}
};

int T,D,H,W;
vec2 Init,Orig;
char M[70][70];
bool flipX, flipY;

int gcd(int a,int b)
{
	if(b == 0) return a;
	else return gcd(b,a%b);
}

void flip(bool x, const vec2& on)
{
	if(x) { Orig.x = 2*on.x - Orig.x; flipX = !flipX; }
	else { Orig.y = 2*on.y - Orig.y; flipY = !flipY; }
}

vec2 transf(const vec2& p)
{
	return vec2((p.x - Orig.x) * (flipX ? -1 : 1) - flipX, (p.y - Orig.y) * (flipY ? -1 : 1)-flipY);
}

vec2 transfo(const vec2& p)
{
	return vec2((p.x - Orig.x) * (flipX ? -1 : 1), (p.y - Orig.y) * (flipY ? -1 : 1));
}

int main()
{
	cin>>T;
	REP(t,T)
	{
		int res = 0;

		cin>>H>>W>>D;
		REP(y,H)
		{
			string row;
			cin>>row;
			REP(x,W)
			{
				if(row[x] == 'X')
				{
					row[x] = '.';
					Init.x = 2*x+1, Init.y = 2*y+1;
				}

				M[y*2+0][x*2+0] = row[x];
				M[y*2+1][x*2+1] = row[x];
				M[y*2+1][x*2+0] = row[x];
				M[y*2+0][x*2+1] = row[x];				
			}
		}

		FOR(hy,-D,D+1) FOR(hx,-D,D+1)
		{
			int ex = hx, ey = hy;			
			//int ex = 1, ey = 3;			

			if( ex == 0 && ey == 0 ) continue;
			
			flipX = flipY = false;
			Orig = vec2(0,0);		

			if(ex < 0) { ex = -ex; flip(true,Init); }
			if(ey < 0) { ey = -ey; flip(false,Init); }

			if(gcd(ex,ey)>1)
				continue;	

			vector<isect> is;
			if(ey != 0)
			{
				for(int dy=1; dy<=2*D; ++dy)
				{
					isect h;
					h.p1.y = h.p2.y = dy + Init.y;
					h.p1.x = (ex * dy) / ey + Init.x;
					h.p2.x = (ex * dy - 1) / ey + Init.x;
					h.flipX = false;

					if(h.p1.x - Init.x <= 2*D && h.p2.x - Init.x <= 2*D)
						is.pb(h);
				}
			}

			if(ex != 0)
			{
				for(int dx=1; dx<=2*D; ++dx)
				{
					isect h;
					h.p1.x = h.p2.x = dx + Init.x;
					h.p1.y = (ey * dx) / ex + Init.y;
					h.p2.y = (ey * dx - 1) / ex + Init.y;
					h.flipX = true;

					if(h.p1.y - Init.y <= 2*D && h.p2.y - Init.y <= 2*D)
						is.pb(h);
				}
			}

			sort(all(is));

			bool hit = false;
			REP(i,sz(is))
			{
				vec2 p1 = is[i].p1;
				vec2 t1 = transf(p1);
				vec2 to1 = transfo(p1);
				vec2 t2 = transf(is[i].p2);

				if(t1 != t2 && to1 == Init)
				{
					if((p1.x - Init.x) * (p1.x - Init.x) + (p1.y - Init.y)*(p1.y - Init.y) <= 4*D*D)
						hit = true;
					break;
				}

				if(M[t1.y][t1.x] != '#')
					continue;
				else if(M[t2.y][t2.x] == '#')
					flip(is[i].flipX,is[i].p1);
				else if(!is[i].flipX)
					break;
			}

			if(hit) ++res;
		}

		cout << "Case #" << t+1 << ": " << res << endl;
	}
	return 0;
}