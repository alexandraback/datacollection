#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#define ln printf("\n")
#define rep(a,b) for(int a = 0; a < b; a++)
#define EPS 1e-8
using namespace std;

int comp(double a, double b){
	if(a < b - EPS) return -1;
	if(b < a - EPS) return 1;
	return 0;
}

struct point{
	double x, y;
	
	int flag;
	
	point (double x = 0, double y = 0, int flag = 0): x(x), y(y), flag(flag) { }
	
	point operator + (point & b){
		return point(x+b.x, y+b.y);
	}
	
	point operator - (point & b){
		return point(x-b.x, y-b.y);
	}	
	
	double norm(){
		return sqrt(x*x + y*y);
	}
	
	double dist(point & b){
		return sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y));
	}
	
	void print(){
		printf("%.3lf %.3lf\n", x, y);
	}
};

struct line{
	double a, b, c;
	point p, q;
	bool seg;	
	
	line() {}
	
	line(point & p, point & q, bool seg = false){
		this->p = p;
		this->q = q;
		this->seg = seg;		
		equation();
	}
	
	void equation(){
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a*p.x -b*p.y;	
	}
	
	point toPoint(){
		return p-q;
	}
	
	double norm(){
		return toPoint().norm();
	}
};

double dot(point a, point b){
	return a.x*b.x + a.y*b.y;
}

double dot(point & a, point & b, point & c){
	return dot(b-a, c-a);	
}

double cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

double cross(point & a, point & b, point & c){
	return cross(b-a, c-a);
}

double lineDist(point & p, line & l){
	double dist = cross(l.p, l.q, p)/l.norm();

	if(l.seg){		
		if(dot(p-l.p, l.p-l.q) > 0) return p.dist(l.p);
		if(dot(p-l.q, l.q-l.p) > 0) return p.dist(l.q);		
	}

	if(dist < 0.0) return -dist;
	return dist;
}	
	
point intersect(line & r, line & s){
	double det = s.a*r.b - r.a*s.b;
	
	if(comp(det, 0) == 0) return point(0, 0, 1);
	point p = point((s.b*r.c - r.b*s.c)/det, (r.a*s.c - s.a*r.c)/det);
	if (lineDist(p, r) > EPS) return point(0, 0, 2);
	if (lineDist(p, s) > EPS) return point(0, 0, 2);
	
	return p;	
}

double segDist(line & r, line & s){
	if(intersect(r,s).flag == 0) return 0;
	
	double dist = min(lineDist(r.p, s), lineDist(r.q, s));
	dist = min(dist, lineDist(s.p, r));
	dist = min(dist, lineDist(s.q, r));
	return dist; 
}

double p[55];
double s[55];
int n;
char buf[10];

bool read(){
	scanf("%d", &n);
	
	rep(i,n){
		scanf("%s%lf%lf", buf, &s[i], &p[i]);
	}
}

struct car{
	line a, b;
} c[55];

int cn = 1;

void process(){
	printf("Case #%d: ", cn++);
	double hi = 100000000;
	rep(i,n){
		point a = point(p[i], 0);
		point b = point(p[i]+s[i], 1);
		c[i].a = line(a, b, false);
		a = point(p[i]+5, 0);
		b = point(p[i]+5+s[i], 1);
		c[i].b = line(a, b, false);
	}
	
	double res = -1;
	
	rep(i,n){
		rep(j,n){
			if(i == j) continue;
			vector<point> po;
			
			point x = intersect(c[i].a, c[j].a);
			if(x.flag == 0) po.push_back(x);
			x = intersect(c[i].a, c[j].b);
			if(x.flag == 0) po.push_back(x);
			x = intersect(c[i].b, c[j].a);
			if(x.flag == 0) po.push_back(x);
			x = intersect(c[i].b, c[j].b);
			if(x.flag == 0) po.push_back(x);
			
			//if(po.size() != 0 && po.size() != 4) printf("something went wrong as there is %d collision points\n", po.size());
			
			if(po.size() == 4){
				//printf("Car %d intersected with car %d\n", i, j);
				//rep(k,4) po[k].print();
				vector<line> li;
				rep(k, 4){
					for(int q = 0; q < 4; q++){ 
						if(q == k) continue;
						line l = line(po[k], po[q], true);
						li.push_back(l);
					}
				}
				
				rep(k,n){
					if(k == i || k == j) continue;
					rep(q, li.size()){
						x = intersect(li[q], c[k].a);
						if(x.flag == 0 && x.y > 0){
							//printf("%lf\n", x.y);
							if(res < -0.5) res = x.y;
							else if(x.y < res) res = x.y;
						}
						
						x = intersect(li[q], c[k].b);
						if(x.flag == 0 && x.y > 0){
						//	printf("%lf\n", x.y);
							if(res < -0.5) res = x.y;
							else if(x.y < res) res = x.y;
						}
					}					
				}
			}
		}
	}
	
	if(res < -0.5) printf("Possible\n");
	else printf("%lf\n", res);
}

int main(){
	freopen("a.txt", "r", stdin);

	
	freopen("out.txt", "w", stdout);
	int t = -1;
	scanf("%d", &t);
	while(t-- && read()) process();
	
//	while(1);
	return 0;
}
