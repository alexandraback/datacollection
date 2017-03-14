#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

class Point {
private:
	int gcd(int a,int b) const { if(b==0) return a; return gcd(b,a%b); }
public:
	int x, y;
	Point(int x, int y): x(x),y(y) {}
	Point reflectX(int X) const { return Point(2*X-x, y); }
	Point reflectY(int Y) const { return Point(x, 2*Y-y); }
	Point reduce() const {
		if(x==0 || y==0) return Point(0,0);
		int g =abs(gcd(x,y));
		return Point(x/g,y/g);
	}
	int length2() const { return x*x+y*y; }
	bool operator< (const Point& e) const {
		if(x==e.x) return y<e.y;
		return x<e.x;
	}
	bool operator== (const Point& e) const {
		return x==e.x && y==e.y;
	}
	Point operator- (const Point& e) const {
		return Point(x-e.x, y-e.y);
	}
	double ang() const {
		return atan2(y,x);
	}
	
};
ostream& operator<< (ostream& os, const Point& pt) {
	return os << "(" << pt.x << "," << pt.y << ")";
}
class Map {
private:
	inline int sqr(int x) { return x*x; }
public:
	int w, h;
	Point cent;
	Map(int w, int h, const Point& cent): w(w), h(h), cent(cent) {}
	int solve(int lim) {
		lim *= 2;
		int res;
		int x0=2, x1=2*(w-1);
		int y0=2, y1=2*(h-1);
		queue<Point> q;
		q.push(cent);
		map<Point, int> hash, has;
		int flag=1;
		int cnt=0;
		while(q.size()) {
			Point pt = q.front();
			q.pop();

			has[pt]=1;
			hash[(pt-cent).reduce()]=1;
			
			
			Point s=pt.reflectX(x0), t=s-cent;
			if(flag) {
				q.push(s); 
				if((s-cent).length2() <= sqr(lim)) cnt++;
			}
			else if(t.length2() <= sqr(lim) && !has[s]) q.push(s), has[s]=1;
				
			s=pt.reflectX(x1), t=s-cent;
			if(flag) {
				q.push(s);
				if((s-cent).length2() <= sqr(lim)) cnt++;
			}
			else if(t.length2() <= sqr(lim) && !has[s]) q.push(s), has[s]=1;
			
			s=pt.reflectY(y0), t=s-cent;
			if(flag) {
				q.push(s);
				if((s-cent).length2() <= sqr(lim)) cnt++;
			}
			else if(t.length2() <= sqr(lim) && !has[s]) q.push(s), has[s]=1;
				
			s=pt.reflectY(y1), t=s-cent;
			if(flag) {
				q.push(s);
				if((s-cent).length2() <= sqr(lim)) cnt++;
			}
			else if(t.length2() <= sqr(lim) && !has[s]) q.push(s), has[s]=1;
			flag=0;
		}
		return hash.size()+cnt-1;
	}
};
int main() {
	int T, cas;
	cin >> T;
	for(int cas=1; cas<=T; ++cas) {
		Point cent(0,0);
		int h,w,lim;
		cin>>h>>w>>lim;
		for(int i=0; i<h; ++i) {
			string ln;
			cin >> ln;
			for(int j=0; j<w; ++j) {
				if(ln[j] == 'X') {
					cent = Point(2*j+1, 2*i+1);
				}
			}
		}
		Map* gam = new Map(w,h,cent);
		cout << "Case #" << cas << ": " << gam->solve(lim) << endl;
		delete gam;
	}
	return 0;
}

