#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
ofstream ps("graphics.ps");
char tbl[30][30];
typedef long long ll;
ll h,w,D;
double scale=10;
double offsetx=0;
double offsety=0;
bool is_mirror(int i,int j){
	if (i<0 || i>=h || j<0 || j>=w)
		return false;
	return tbl[i][j]=='#';
}
ll gcd(ll a, ll b){
	if (a<0)
		return gcd(-a, b);
	if (b<0)
		return gcd(a, -b);
	return a==0?b:gcd(b%a,a);
}
struct rational{
	ll n,d;
	rational(){}
	rational(ll a):n(a), d(1){}
	rational(ll _n, ll _d):n(_n), d(_d){
		ll g = gcd(n,d);
		n/=g;
		d/=g;
		if (d < 0){
			d = -d;
			n = -n;
		}
	}
};
ostream& operator<<(ostream& out, const rational& r){
	if (r.d==1)
		return out<<r.n;
	else
		return out<<r.n<<'/'<<r.d;
}
rational operator+(const rational& a,const rational& b){
	return rational(a.n*b.d+a.d*b.n, a.d*b.d);
}
rational operator-(const rational& a,const rational& b){
	return rational(a.n*b.d-a.d*b.n, a.d*b.d);
}
rational operator-(const rational& a){
	return rational(-a.n, a.d);
}
rational operator*(const rational& a,const rational& b){
	return rational(a.n*b.n, a.d*b.d);
}
rational operator/(const rational& a,const rational& b){
	return rational(a.n*b.d, a.d*b.n);
}
bool operator<(const rational& a,const rational& b){
	return a.n*b.d<a.d*b.n;
}
bool operator>=(const rational& a,const rational& b){
	return !(a<b);
}
bool operator<=(const rational& a,const rational& b){
	return b>=a;
}
bool operator>(const rational& a,const rational& b){
	return b<a;
}
bool operator==(const rational& a,const rational& b){
	return a.n==b.n && a.d==b.d;
}
bool operator!=(const rational& a,const rational& b){
	return a.n!=b.n || a.d!=b.d;
}
int floor(const rational& r){
	int ret=r.n/r.d;
	if (r.n%r.d<0)
		--ret;
	return ret;
}
struct point{
	rational x[2];
	point(rational _x, rational _y){
		x[0]=_x;
		x[1]=_y;
	}
	point(){}
	rational& operator[](int t){return x[t];}
	rational operator[](int t) const{return x[t];}
};
bool operator<(const point& p,const point& q){
	if (p[0]!=q[0])
		return p[0]<q[0];
	return p[1]<q[1];
}
bool operator==(const point& p,const point& q){
	return p[0]==q[0] && p[1]==q[1];
}
bool operator!=(const point& p,const point& q){
	return p[0]!=q[0] || p[1]!=q[1];
}
ostream& operator<<(ostream& out, const point& p){
	return out<<'('<<p[0]<<','<<p[1]<<')';
}
rational dot(const point& p,const point& q){
	return p[0]*q[0]+p[1]*q[1];
}
point operator-(const point& p){
	return point(-p[0], -p[1]);
}
point operator-(const point& p,const point& q){
	return point(p[0]-q[0],p[1]-q[1]);
}
point operator+(const point& p,const point& q){
	return point(p[0]+q[0],p[1]+q[1]);
}
point operator*(const rational& t,const point& p){
	return point(t*p[0], t*p[1]);
}
point operator*(const point& p, const rational& t){
	return point(t*p[0], t*p[1]);
}
rational cross(const point& p,const point& q){
	return p[0]*q[1]-p[1]*q[0];
}
struct mirror{
	point p1, p2;
	mirror(){}
	mirror(const point& p1,const point& p2):p1(p1),p2(p2){}
};
ostream& operator<<(ostream& out,const mirror& m){
	return out<<m.p1<<"-"<<m.p2;
}
struct ray{
	point p, d;
	ray(){}
	ray(const point& p,const point& d):p(p), d(d){}
	bool hits(const mirror& m) const{
		if (cross(d, m.p1-p) < 0)
			return false;
		if (cross(m.p2-p, d) < 0)
			return false;
		if (cross(p-m.p1, m.p2-m.p1) < 0)
			return false;
		if (cross(d, m.p1-p) == 0)
			return dot(d, m.p2-m.p1) >= 0;
		if (cross(d, m.p2-p) == 0)
			return dot(d, m.p1-m.p2) >= 0;
		return true;
	}
	bool hits(const point& q) const{
		return cross(q-p, d)==0 && dot(q-p, d)>0;
	}
	rational hit_time(const point& q) const{
		return dot(q-p, d)/dot(d,d);
	}
	rational hit_time(const mirror& m) const{
		return cross(p-m.p1, m.p2-m.p1)/cross(m.p2-m.p1, d);
	}
	ray reflect(const mirror& m) const;
};
bool operator<(const ray& r1,const ray& r2){
	if (r1.p!=r2.p)
		return r1.p<r2.p;
	return r1.d<r2.d;
}
bool operator==(const ray& r1,const ray& r2){
	return r1.p==r2.p && r1.d==r2.d;
}
ostream& operator<<(ostream& out,const ray& r){
	return out<<r.p<<':'<<r.d;
}
ray ray::reflect(const mirror& m) const{
	rational t=hit_time(m);
	ray ret;
	ret.p=p+t*d;
	point md=m.p2-m.p1;
	point mn(-md[1], md[0]);
	point projection=(dot(d,mn)/dot(mn,mn))*mn;
	ret.d=d-2*projection;
	return ret;
}
pair<rational, vector<ray> > reflections(const ray& r){
	vector<mirror> ms;
	vector<ray> ret;
	for (int i=0;i<=h;++i){
		if (i!=1 && i!=h-1)
			continue;
		mirror m(point(0,i), point(w,i));
		if (r.hits(m)){
			point ref = r.p+r.d*r.hit_time(m);
			int ind=floor(ref[0]);
			for (int j=ind-1;j<=ind;++j)
				if (is_mirror(h-i-1,j))
					ms.push_back(mirror(point(j, i), point(j+1, i)));
		}
	}
	for (int i=0;i<=h;++i){
		if (i!=1 && i!=h-1)
			continue;
		mirror m(point(w,i), point(0,i));
		if (r.hits(m)){
			point ref = r.p+r.d*r.hit_time(m);
			int ind=floor(ref[0]);
			for (int j=ind-1;j<=ind;++j)
				if (is_mirror(h-i, j))
					ms.push_back(mirror(point(j+1, i), point(j, i)));
		}
	}
	for (int j=0;j<=w;++j){
		if (j!=1 && j!=w-1)
			continue;
		mirror m(point(j,0), point(j,h));
		if (r.hits(m)){
			point ref = r.p+r.d*r.hit_time(m);
			int ind=floor(ref[1]);
			for (int i=ind-1;i<=ind;++i)
				if (is_mirror(h-i-1, j-1))
					ms.push_back(mirror(point(j, i), point(j, i+1)));
		}
	}
	for (int j=0;j<=w;++j){
		if (j!=1 && j!=w-1)
			continue;
		mirror m(point(j,h), point(j,0));
		if (r.hits(m)){
			point ref = r.p+r.d*r.hit_time(m);
			int ind=floor(ref[1]);
			for (int i=ind-1;i<=ind;++i)
				if (is_mirror(h-i-1, j))
					ms.push_back(mirror(point(j, i+1), point(j, i)));
		}
	}
	rational mint=rational(1)/rational(0);
	for (int i=0;i<ms.size();++i){
		if (r.hits(ms[i])){
			mint=min(mint, r.hit_time(ms[i]));
		}
	}
	for (int i=0;i<ms.size();++i){
		if (r.hits(ms[i]) && r.hit_time(ms[i])==mint){
			ret.push_back(r.reflect(ms[i]));
		}
	}
	sort(ret.begin(), ret.end());
	ret.resize(unique(ret.begin(), ret.end())-ret.begin());
	return make_pair(mint, ret);
}
vector<pair<int, ray> > in_place(const ray& r, int lev=0){
	if (lev==3)
		return vector<pair<int, ray> >(0);
	pair<rational, vector<ray> > ans=reflections(r);
	if (ans.first != 0)
		return vector<pair<int, ray> >(1, make_pair(lev, r));
	vector<pair<int, ray> > ret;
	for (int i=0;i<ans.second.size();++i){
		vector<pair<int, ray> > t=in_place(ans.second[i], lev+1);
		for (int j=0;j<t.size();++j)
			ret.push_back(t[j]);
	}
	sort(ret.begin(), ret.end());
	ret.resize(unique(ret.begin(), ret.end())-ret.begin());
	if (ret.size()>0){
		for (int i=0;i<ret.size();++i)
			if (ret[i].first != ret[0].first){
				ret.resize(i);
				break;
			}
	}
	return ret;
}
pair<rational, vector<ray> > advance(ray r){
	pair<rational, vector<ray> > ans=reflections(r);
	r.p=r.p+r.d*ans.first;
	vector<pair<int, ray> > results = in_place(r);
	vector<ray> res;
	for (int i=0;i<results.size();++i)
		res.push_back(results[i].second);
	if (res.size() > 1)
		res.clear();
	return make_pair(ans.first, res);
}
double rnd(){
	return double(rand()%90)/100.0;
}
bool check(const ray& r, rational D, int print=0){
	rational t=0;
	ray cur=r;
	if (print){
		ps<<rnd()<<' '<<rnd()<<' '<<rnd();
		ps<<" setrgbcolor"<<endl;
		ps<<"newpath"<<endl;
		ps<<r.p[0]*scale+offsetx<<' '<<r.p[1]*scale+offsety<<" moveto"<<endl;
	}
	while(true){
		if (print){
			ps<<cur.p[0]*scale+offsetx<<' '<<cur.p[1]*scale+offsety<<" lineto"<<endl;
		}
		if (t*t*dot(r.d, r.d)>D*D)
			return false;
		pair<rational, vector<ray> > ans=advance(cur);
		if (cur.hits(r.p) && cur.hit_time(r.p)<ans.first){
			t = t+cur.hit_time(r.p);
			if (print){
				ps<<r.p[0]*scale+offsetx<<' '<<r.p[1]*scale+offsety<<" lineto"<<endl;
				ps<<"stroke"<<endl;
			}
			return t*t*dot(r.d, r.d)<=D*D;
		}
		if (ans.second.empty())
			return false;
		cur=ans.second[0];
		t=t+ans.first;
	}
}
int main(){
	ps<<"%!PS"<<endl;
	ps<<"0.1 setlinewidth"<<endl;
	int tnum;cin>>tnum;int tcou=0;
	while (tnum--){
		scale=40;
		int cx=tcou%4;
		int cy=tcou/4;
		offsetx=scale*32*cx;
		offsety=scale*32*cy;
		ps<<rnd()/2<<' '<<rnd()/2<<' '<<rnd()/2;
		ps<<" setrgbcolor"<<endl;
		cin>>h>>w>>D;
		point p;
		for (int i=0;i<h;++i)
			for (int j=0;j<w;++j){
				cin>>tbl[i][j];
				if (tbl[i][j]=='X')
					p=point(j+rational(1)/2,(h-i-1)+rational(1)/2);
				else if (tbl[i][j]=='#'){
					ps<<"newpath"<<endl;
					ps<<scale*j+offsetx<<" "<<scale*(h-i-1)+offsety<<" moveto"<<endl;
					ps<<scale*(j+1)+offsetx<<" "<<scale*(h-i-1)+offsety<<" lineto"<<endl;
					ps<<scale*(j+1)+offsetx<<" "<<scale*(h-i)+offsety<<" lineto"<<endl;
					ps<<scale*j+offsetx<<" "<<scale*(h-i)+offsety<<" lineto"<<endl;
					ps<<"fill"<<endl;
				}
			}
		int cnt=0;
		for (int i=-D;i<=D;++i)
			for (int j=-D;j<=D;++j){
				if (gcd(i,j)==1){
					if (check(ray(p, point(i,j)), D)){
						++cnt;
					}
				}
			}
		cout<<"Case #"<<++tcou<<": "<<cnt<<endl;
	}
	return 0;
}
