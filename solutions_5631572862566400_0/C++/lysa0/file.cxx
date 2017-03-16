#include <bits/stdc++.h>

#define rep(i, n) for (long long i=0; i<n; i++)
#define eps 1e-9

using namespace std;

typedef long long ll;


double sqr(double a){
	return a*a;
}
bool doubleEqual(double a, double b){
	return fabs(a-b)<1e-9;
}
bool doubleLessOrEqual(double a, double b){
	return a<b || doubleEqual(a, b);
}
bool doubleLess(double a, double b){
	return a<b && !doubleEqual(a, b);
}
bool doubleGreaterOrEqual(double a, double b){
	return a>b || doubleEqual(a, b);
}
bool doubleGreater(double a, double b){
	return a>b && !doubleEqual(a, b);
}
double mySqrt(double a){
	if (doubleLess(a,0)) throw "sqrt(-1)";
	if (a<0) return 0;
	return sqrt(a);
}

struct Point{
	double x, y;
	Point(): x(0), y(0) {}
	Point(double x, double y): x(x), y(y) {}
	void scan(){
		scanf("%lf %lf", &x, &y);
	}
	void print() const{
		printf("%.10lf %.10lf\n", x, y);
	}
	Point operator+(const Point &p) const {
		return Point(x+p.x, y+p.y);
	}
	Point operator-(const Point &p) const {
		return Point(x-p.x, y-p.y);
	}
	Point operator-() const {
		return Point(-x, -y);
	}
	Point operator*(double k) const {
		return Point(x*k, y*k);
	}
	Point operator/(double k) const {
		return Point(x/k, y/k);
	}
	double operator%(const Point &p) const {
		return x*p.x+y*p.y;
	}
	double operator*(const Point &p) const {
		return x*p.y-y*p.x;
	}
	double length() const {
		return mySqrt(*this % *this);
	}
	double distTo(const Point &p) const {
		return (*this -p).length();
	}
	double distTo(const Point &A, const Point &B) const {
		double d=A.distTo(B);
		if (doubleEqual(d,0)){
			throw "A = B";
		}
		double s = (*this - A) * (*this - B);
		return fabs(s)/d;
	}
	Point normalize(double k=1) const {
		double len = length();
		if(doubleEqual(len, 0)) {
			if (doubleEqual(k, 0)){
				return Point();

			}
			throw "zero-size vector";
		}
		return *this*(k/len);
	}
	Point getH(const Point &A, const Point&B) const {
		Point C = *this;
		Point v = B - A;
		Point u = C - A;
		double k=v%u/v.length();
		v=v.normalize(k);
		Point H=A+v;
		return H;
	}
	Point rotate() const {
		return Point(-y, x);
	}
	Point rotate(double alpha) const {
		return rotate(cos(alpha), sin(alpha));
	}
	Point rotate(double cosa, double sina) const {
		Point v = *this;
		Point u = v.rotate();
		Point w = v*cosa + u*sina;
		return w;
	}
	bool isZero() const{
		return doubleEqual(x, 0) && doubleEqual(y, 0);
	}
	bool isOnline(const Point &A, const Point &B) const {
		return doubleEqual((A-*this)*(B-*this), 0);
	}
	bool isInSegment(const Point &A, const Point &B) const {
		return doubleLessOrEqual((A-*this)%(B-*this), 0);
	}
	bool isInSegmentStricly(const Point &A, const Point &B) const {
		return doubleLess((A-*this)%(B-*this), 0);
	}
	double getAngle() const {
		return atan2(y, x);
	}
	double getAngle(Point u) const {
		return atan2(*this*u, *this%u);
	}
};

int getIntersection(const Point &A, const Point &B, const Point &C, const Point &D, Point &O) {
	Point v = B-A;
	double s1 = (C-A)*(D-A);
	double s2 = (D-B)*(C-B);
	double s = s1+s2;
	if (doubleEqual(s, 0)){
		if (!A.isOnline(C,D))
			return 0;
		return 2;
	}
	v = v/s;
	v = v*s1;
	O = A+v;
	return 1;
}

int getIntersection(const Point &A, double rA, const Point &B, double rB, Point &M, Point &N){
	double d=A.distTo(B);
	if (doubleLess(rA+rB, d) || doubleLess(d, fabs(rA-rB))){
		return 0;
	}
	double a = (sqr(rA)-sqr(rB) + sqr(d))/2/d;
	double h=mySqrt(sqr(rA)-sqr(a));
	Point v = B-A;
	Point u = v.rotate();
	v = v.normalize(a);
	u = u.normalize(h);
	Point H=A+v;
	M=H+u;
	N=H-u;
	if (u.isZero())
		return 1;
	return 2;
}

int getIntersection(const Point &A, const Point &B, const Point &O, double r, Point &M, Point &N){
	double h = O.distTo(A,B);
	if (doubleLess(r, h)){
		return 0;
	}
	Point H=O.getH(A,B);
	Point v=B-A;
	double k=mySqrt(sqr(r)-sqr(h));
	v=v.normalize(k);
	M=H+v;
	N=H-v;
	if(v.isZero())
		return 1;
	return 2;
}

struct cmp{
    bool operator()(const string &a, const string &b){
        return a+b<b+a;
    }
};

ll GCD(ll a, ll b){
    return (!b?a:GCD(b, a%b));
}

ll POW(ll a, ll b){
    return (!b?1:b==1?a:b%2?POW(a,b>>2)*POW(a,b>>2)*a:POW(a,b>>2)*POW(a,b>>2));
}

bool usd[10000] {};
ll pmax1;
map<ll,set<ll>> mmapf;
void dfs(ll startvert, ll vert, set<ll> verts, ll pmax, ll prevvert){
	cout << startvert << " : " << vert << " : " << pmax1 << endl;
	pmax++;
	bool flag=false;
	for (auto&we:mmapf[vert])
		if (verts.find(we)==verts.end()){
			verts.insert(we);
			flag=true;
			dfs(startvert, we, verts, pmax, vert);
			verts.erase(we);
		}
	if (!flag){
		pmax1=pmax;
		pmax1--;
		if ((mmapf[prevvert].find(vert)!=mmapf[prevvert].end()) || (mmapf[startvert].find(vert)!=mmapf[startvert].end()))
			pmax1++;
	}
}


int main(){
	ifstream fin("file.in");
	ofstream fout("file.out");
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	ll n, m, a, b, c, d, e, f, x, y, z;
	char ch, c1, c2;

	string s, s1, s2, s3;
	fin >> n;
	rep(i, n) {
		pmax1=0;
		memset(usd, 1, sizeof(bool)*10000);
		mmapf.clear();
		fout << "Case #" << i+1 << ": ";
		map<ll,ll> mapps;
		fin >> m;
		rep(j, m){
			fin >> a;
			mmapf[j+1].insert(a);
			mmapf[a].insert(j+1);
		}
		ll maxx=0;
		rep(j, m){
			set<ll>verts;
			pmax1=0;
			verts.insert(j+1);
			dfs(j+1, j+1, verts, 0, 0);
			verts.erase(j+1);
			if (pmax1>maxx)
				maxx=pmax1;
		}

		fout << maxx;


		fout << endl;



	
 
	}
	fin.close();
	fout.close();
  return 0;
}















