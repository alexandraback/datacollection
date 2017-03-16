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
    return (!b?1:b==1?a:b%2?POW(a,b/2)*POW(a,b/2)*a:POW(a,b/2)*POW(a,b/2));
}

double rest(double a, double b){
	if (a<b)
		return a;
	return rest(a-b*pow(10, (ll)(log(a)/log(10)-1)), b);
}

double dGCD(double a, double b){
	if (fabs(a) < 1e-6-1e-7)
		return 0;
    return (b<1e-6-1e-7?a:dGCD(b, rest(a,b)));
}
struct cmpLess{
    bool operator()(const ll &a, const ll &b){
        return a<b;
    }
};

struct cmpGr{
    bool operator()(const ll &a, const ll &b){
        return a>b;
    }
};

/*bool prime[(ll)1e8] {};
void Erat(const ll N){
	ll sim=2;
	ll i=0;
	while(true){
		i=2;
		if(!prime[sim])
		while(true){
			if (i*sim>=N)
				break;
			prime[i*sim]=true;
			i++;
		}
		sim++;
		if (sim>=N)
			break;
	}
}*/
string nextStr(string ss){
	ll pos=0;
	string tss=ss;
	rep(i, tss.length()){
		if (ss[i]=='0')
			pos=i;
	}
	ss=ss.substr(0, pos)+'1';
	rep(i,tss.length()-pos-1)
		ss+='0';
	return ss;
}
ll toSS(string ss, ll sss){
	ll res=0;
	rep(i, ss.length())
		res=res*sss+ss[i]-'0';
	return res;
}

ll getDiv(ll num){
	ll sQrt = sqrt(num);
	ll diV=-1;
	for (int i=2; i<sQrt; i++){
		if (num%i==0){
			diV=i;
			break;
		}
	}
	return diV;
}

int main(){

  fstream fin("file.in");
  ofstream fout("file.out");
  ll n, m, t;
  string s;
  //Erat((ll)1e7);
  fin >> n;
  rep(i, n) {
  	fin >> m >> t;
  	string num;
  	num="1";
  	rep(j, m-2){
  		num+="0";
  	}
  	if (m>1) 
  		num+="1";
  	/*rep(j, 15){
	  	cout << num << ' ' << toSS(num, 2) << ' ' << toSS(num, 3) << ' ' << toSS(num, 10) <<  endl;
	  	num=nextStr(num);
	 }*/
	ll res=0;
	fout << "Case #" << i+1 << ":"<< '\n';
	while(true){
		list<ll> listt;
		for(ll j=2; j<11; j++){
			ll ch=toSS(num, j);
			/*if (!prime[ch])
				break;*/
			ll DiV=getDiv(ch);
			if (DiV==-1)
				break;
			listt.push_back(DiV);
			if (j==10){
				fout << num << ' ';
				for (auto&lll:listt)
					fout << lll << ' ';
				res++;
				fout << '\n';
			}
		}
		num=nextStr(num);
		if (num[num.length()-1]=='0')
			num=nextStr(num);
		if (res>=t)
			break;
	}	  
  }
  return 0;
}
