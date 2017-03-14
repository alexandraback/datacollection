
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
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
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

///////////////////////////////////////////////////////

const int maxn=40;

int w,h,D,D2;
int a[maxn][maxn];

struct Vec {
  int x,y;
  Vec () {}
  Vec (int a, int b):x(a),y(b){}
  Vec operator +(const Vec &o) const {return Vec(x+o.x, y+o.y);}
  Vec & operator +=(const Vec &o) {x+=o.x; y+=o.y; return *this;}
  Vec operator -(const Vec &o) const {return Vec(x-o.x, y-o.y);}
  Vec & operator -=(const Vec &o) {x-=o.x; y-=o.y; return *this;}
  Vec operator *(int s) const {return Vec(x*s,y*s);}
  Vec & operator *=(int s) {x*=s; y*=s; return *this;}
  int cross(const Vec &o) const {return x*o.y-y*o.x;}
  int dot(const Vec &o) const {return x*o.x+y*o.y;}

  int len2() const {return x*x+y*y;}
  bool operator == (const Vec &o) const {
	return x==o.x && y==o.y;
  }
  friend ostream & operator << (ostream &os, const Vec &v) {
	return os<<"("<<v.x<<","<<v.y<<")";
  }
};

Vec cen;


inline bool mirror(Vec p) {
  return p.x>=0 && p.x<w && p.y>=0 && p.y<h && a[p.x][p.y];
}

struct Ray {
  Vec from;//, to;

  Vec dir;
  Vec offs;
  Vec dirs;
  Ray(Vec a, Vec b) {
	from=a; //to=b;
	dir=b-a;
	offs=Vec(0,0);

	if (dir.x<0) dirs.x=-1;
	if (dir.x==0) dirs.x=0;
	if (dir.x>0) dirs.x=1;

	if (dir.y<0) dirs.y=-1;
	if (dir.y==0) dirs.y=0;
	if (dir.y>0) dirs.y=1;
  }

  void reflectx() {
	//x=from.x + offs.x + dirs.x/2

	//from.x = x+x-from.x
	//from.x = dirs.x + 2*offs.x + from.x

	from.x += 2*offs.x + dirs.x;
	offs.x *= -1;
	dir.x *= -1;	
	dirs.x *= -1;
  }
  void reflecty() {
	from.y += 2*offs.y + dirs.y;
	offs.y *= -1;
	dir.y *= -1;
	dirs.y *= -1;
  }

  bool trace() {
	int len2=dir.len2();
	while (offs.len2()<len2) {
	  if (dir.x==0) {
		if (mirror(from+offs+dirs))
		  reflecty();
		offs+=dirs;
	  } else if (dir.y==0) {
		if (mirror(from+offs+dirs))
		  reflectx();
		offs+=dirs;
	  } else {
		//see which wall it hits first, push offs accordingly
		int u=dir.y*(2*offs.x+dirs.x)*dirs.x*dirs.y;
		int v=dir.x*(2*offs.y+dirs.y)*dirs.x*dirs.y;
		if (u==v) { //corner shit
		  bool m01=mirror(from+offs+Vec(0,dirs.y));
		  bool m10=mirror(from+offs+Vec(dirs.x,0));
		  bool m11=mirror(from+offs+Vec(dirs.x,dirs.y));
		  if (!m11) {
			//clear, just go
		  }
		  else if (m01 && !m10) {
			reflecty();
		  }
		  else if (!m01 && m10) {
			reflectx();
		  }
		  else if (m01 && m10 && m11) {
			reflectx();
			reflecty();
		  } else if (!m01 && !m10 && m11) {
			return false;
		  }
		  offs+=dirs;
		
		} else if (u<v){ //hit x wall first
		  if (mirror(from+offs+Vec(dirs.x,0)))
			reflectx();
		  offs.x+=dirs.x;
		} else if (u>v) {
		  if (mirror(from+offs+Vec(0,dirs.y)))
			reflecty();
		  offs.y+=dirs.y;
		}
	  }
	}
	return offs.len2()==len2 && from+offs==cen;
  }
};

vector <Vec> found;

void clear() {
  zer(a);
  found.clear();
}

bool checkfound(Vec dir) {
  FORIT(it, found)
	if (it->cross(dir)==0 && it->dot(dir)>0) return 1;
  return 0;
}
  
void solve(int cnum) {
  cin>>h>>w;
  cin>>D;

  D2=D*D;

  FOR (i,h) FOR (j,w) {
	char c;
	cin>>c;
	if (c=='#') a[j][i]=1;
	if (c=='X') cen=Vec(j,i);
  }

  for (int x=cen.x-D;x<=cen.x+D;x++)
	for (int y=cen.y-D;y<=cen.y+D;y++) {
	  if (x==cen.x && y==cen.y) continue;
	  Ray ray(cen, Vec(x,y));
	  if (ray.dir.len2()>D2) continue;
	  Vec launchdir=ray.dir;
	  if (checkfound(launchdir)) continue;
	  if (ray.trace()) found.pb(launchdir);
	}

  cout<<"Case #"<<cnum<<": "<<found.size()<<endl;

}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
