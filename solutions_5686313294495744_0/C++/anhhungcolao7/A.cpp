
#include <bits/stdc++.h>
#define fi "a.inp"
#define fo "a.out"
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define All(x) x.begin(),x.end()
#define st first
#define nd second
#define It interator
#define sl_int(x) __builtin_popcount(x)
#define el endl
#define in cin
#define out cout
#define sz size()
#define in_vt(x) For(i,0,(int) x.sz - 1) printf("%d ",x[i]);puts("");
using namespace std;

typedef pair<int,int> II;
typedef pair<int,II> III;
typedef long long ll;
typedef pair<ll,ll> LL;
typedef map<int,int> mii;
typedef map<ll,int> mli;
typedef map<ll,ll> mll;
typedef vector <int> vti;
typedef vector <ll> vtl;
typedef queue <int> qi;
typedef deque <int> dqi;
typedef set <int> si;
typedef multiset <int> msi;
typedef queue <ll> ql;
typedef deque <ll> dql;
typedef set <ll> sl;
typedef multiset <ll> msl;

struct Point 
{
	int x,y;
	bool operator <(const Point &T) const {
			if (x==T.x) return (y<T.y);
			return (x<T.x);
	}
};
struct Matrix{
	ll d[4][4];
	int mod;
	Matrix operator *(const Matrix &A) const{
		Matrix ans;
		ans.mod = mod;
		For(i,0,3) For(j,0,3) ans.d[i][j] = 0;
		For(i,0,3) {
			For(j,0,3) {
				For(k,0,3) {
					ans.d[i][j] += (A.d[i][k] * d[k][j]);
					ans.d[i][j]%=mod;
				}
			}
		}
		return ans;
	}
	Matrix operator ^(const int n) const{
		Matrix ans;
		ans.mod = mod;
		For(i,0,3) For(j,0,3) ans.d[i][j] = d[i][j];
		if (n==1) return ans;
		Matrix t = ans ^ (n/2);
		if (n%2==0) return (t*t);
		return (t*t*ans);
	}
};

double INF = 1e100;
double EPS = 1e-7;
struct PT {
    double x, y;
    PT (){}
    PT (double x, double y) : x(x), y(y){}
    PT (const PT &p) : x(p.x), y(p.y){}
    PT operator - (const PT &p){ return PT(x - p.x, y - p.y);}
    PT operator + (const PT &p){ return PT(x + p.x, y + p.y);}
    PT operator * (double c){ return PT(x * c, y * c); }
    PT operator / (double c){ return PT(x/c, y/c); }
    bool operator == (const PT &p) {return x == p.x && y == p.y; }
    bool operator != (const PT &p) {return x != p.x || y != p.y; }
};
double dot(PT p, PT q){ return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q){ return dot(p-q,p-q); }
double cross(PT p, PT q){ return p.x*q.y-p.y*q.x; }
ostream &operator<< (ostream &os, const PT &p){
os << "("<< p.x << ","<< p.y << ")";
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p){ return PT(-p.y,p.x); } //+90
PT RotateCW90(PT p){ return PT(p.y, -p.x); } // -90
PT RotateCCW(PT p, double t){
    return PT(p.x * cos(t) - p.y * sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCCW90(PT origin, PT pt){
    pt = pt - origin; pt = RotateCCW90(pt);
    pt = pt + origin; return pt;
}
bool isSquare(PT pt1, PT pt2, PT pt3, PT pt4){
    PT center = pt1 + pt2 + pt3 + pt4;
    center = center * 0.25;
    if(center == pt1) return false;
    PT pt = RotateCCW90(center, pt1); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    pt = RotateCCW90(center, pt); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    pt = RotateCCW90(center, pt); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    return true;
}
bool isRectangle(PT pt1, PT pt2, PT pt3, PT pt4){
    PT center = pt1 + pt2 + pt3 + pt4;
    center = center * 0.25;
    if(center == pt1) return false;
    if(pt1 + pt2 == (center * 2.0) && pt3 + pt4 == (center * 2.0) && dist2(pt1, pt2) == dist2(pt3, pt4)) return true;
    if(pt1 + pt3 == (center * 2.0) && pt2 + pt4 == (center * 2.0) && dist2(pt1, pt3) == dist2(pt2, pt4)) return true;
    if(pt1 + pt4 == (center * 2.0) && pt2 + pt3 == (center * 2.0) && dist2(pt1, pt4) == dist2(pt3, pt2)) return true;
    return false;
}
double area(PT a, PT b, PT c){
    PT ab = b - a, ac = c - a;
    return 0.5 * (abs(cross(ab, ac)));
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c){
    return a + (b-a) * dot(c-a,b-a)/dot(b-a,b-a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c){
    double r = dot(b-a,b-a);
    if(fabs(r) < EPS) return a;
    r = dot(c-a,b-a)/r;
    if(r < 0) return a;
    if(r > 1) return b;
    return a + (b-a)*r;
}
// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d){
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
// determine if two lines are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d){
    return fabs(cross(b-a,c-d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d){
    return LinesParallel(a,b,c,d) && fabs(cross(a-c,d-c)) < EPS;
}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d){
    if(cross(d-a,b-a) * cross(c-a,b-a) > 0) return false;
    if(cross(a-c,d-c) * cross(b-c,d-c) > 0) return false;
    return true;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists
PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
    b=b-a; d=c-d; c=c-a;
    if(dot(b,b) < EPS) return a;
    if(dot(d,d) < EPS) return c;
    return a + b*cross(c,d)/cross(b,d);
}
// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c){
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection (b,b + RotateCW90(a-b), c, c + RotateCW90(a-c));
}
// determine if point is in a possibly non-convex polygon
// (by William Randolph Franklin); returns 1 for strictly
// interior points, 0 for strictly exterior points, and
// 0 or 1 for the remaining points
// note that it is possible to convert this into an *exact*
// test using integer arithmetic by taking care of the
// division appropriately (making sure to deal with signs
// properly) and then by writing exact tests for checking
// point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q){
    bool c = 0;
    for(int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    if((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
       q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
    }
    return c;
}
// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q){
    for(int i = 0; i < p.size(); i++)
    if(dist2(ProjectPointSegment (p[i], p[(i+1)%p.size()], q), q) < EPS)    return true;
    return false;
}
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection (PT a, PT b, PT c, double r){
    vector<PT> ret;
    PT d = b-a;
    double D = cross(a-c,b-c);
    double e = r*r*dot(d,d)-D*D;
    if(e < 0) return    ret;
    e = sqrt(e);
    ret.push_back (c+PT(D*d.y+(d.y>=0?1:-1)*d.x*e,-D*d.x+fabs(d.y)*e)/dot(d,d));
    if(e > 0)
    ret.push_back (c+PT(D*d.y-(d.y>=0?1:-1)*d.x*e,-D*d.x-fabs(d.y)*e)/dot(d,d));
    return ret;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
// Khong xet truong hop a == b && r == R
vector<PT> CircleCircleIntersection (PT a, PT b, double r, double R){
    vector<PT> ret;
    double d = sqrt(dist2(a,b));
    if(d > r+R || d+min(r,R) < max(r,R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back (a+v*x + RotateCCW90(v)*y);
    if(y > 0)
    ret.push_back (a+v*x - RotateCCW90(v)*y);
    return ret;
}
double dist(double xa, double ya, double xb, double yb) {
	xa -= xb; ya -= yb;
	return sqrt(xa * xa + ya * ya);
}
double angle(double ox, double oy, double ax, double ay, double bx, double by){ // goc AOB
    double a, b, c, alpha;
		a = dist(ax, ay, bx, by);
		b = dist(ox, oy, ax, ay);
		c = dist(ox, oy, bx, by);
		alpha = acos((a * a - b * b - c * c) / (-2.0 * b * c));
    return alpha;
}
int getbit(int n,int k) {
	return (n>>(k-1))&1;
}
set <string> m,m1;
string s[20],s1[20];
int test,n;
int main()
{
	freopen (fi, "r", stdin);
	freopen (fo, "w", stdout);
	scanf("%d", &test);
	For(Test,1,test) {
		scanf("%d", &n);
		For(i,1,n) {
			cin>>s[i];cin>>s1[i];
		}
		int ans = 0;
		For(i,0,(1<<n)-1) {
			m.clear();
			m1.clear();
			For(j,1,n) 
				if (getbit(i,j)) {
					m.insert(s[j]);
					m1.insert(s1[j]);
				}
			bool ok = 1;
			int sl = 0;
			For(j,1,n) if (!getbit(i,j)) {
				if (m.find(s[j])!=m.end()&&m1.find(s1[j])!=m1.end()) {
					sl++;
				} else {
					ok = 0; break;
				}
			}
			if (ok) ans = max(ans,sl);
		}
		printf("Case #%d: ",Test);
		cout<<ans<<endl;
	}
	return 0;
}
