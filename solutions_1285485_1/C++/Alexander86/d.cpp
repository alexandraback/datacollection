
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)


int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct Q{
	ll num, den;
	Q(){
		num = 0;
		den = 1;
	}
	Q(ll n){
		num = n;
		den = 1;
	}
	Q(ll n, ll d){
		ll gc = gcd(abs(n),abs(d));
		n/=gc;
		d/=gc;
		if(d < 0){
			d = -d;
			n = -n;
		}
		num = n;
		den = d;
	}
	Q ceil(){
		if(num >= 0)return Q((num + den - 1) / den);
		return Q(num / den);
	}
	Q floor(){
		if(num <= 0)return Q((num + den - 1) / den);
		return Q(num / den);
	}
	void print(){
		cout << num << "/" << den;
	}
};
Q operator+(const Q&a,const Q&b){
	return Q(a.num*b.den+b.num*a.den,a.den*b.den);
}
Q operator-(const Q&a,const Q&b){
	return Q(a.num*b.den-b.num*a.den,a.den*b.den);
}
Q operator*(const Q&a,const Q&b){
	return Q(a.num*b.num,a.den*b.den);
}
Q operator/(const Q&a,const Q&b){
	return Q(a.num*b.den,a.den*b.num);
}
bool operator==(const Q&a, const Q&b){
	return a.num == b.num && a.den == b.den;
}
bool operator<(const Q&a, const Q&b){
	return a.num * b.den < b.num * a.den;
}
vector<pii > dirs;
int R,C,D;
string grid[110];

Q getNext(Q x, int d){
	Q x2 = x * Q(2);
	if(x2.den == 1){
		if(d > 0)return x + Q(1,2);
		else return x - Q(1,2);
	}
	if(d > 0) return x2.ceil() * Q(1,2);
	return x2.floor() * Q(1,2);
}

Q getFactor(Q r, Q c, int dr, int dc){
	Q nr = getNext(r,dr);
	Q nc = getNext(c,dc);
	Q fa1 = (nr - r) * Q(1,dr);
	Q fa2 = (nc - c) * Q(1,dc);
	if(fa1 < fa2)return fa1;
	return fa2;
}
bool check(int r, int c, int dr, int dc){
	if(dr == 0 || dc == 0){
		int ct = 0;
		while(grid[r][c] != '#'){
			++ct;
			r += dr;
			c += dc;
		}
		return ct * 2 - 1 <= D;
	}
	Q qr = Q(r)+Q(1,2), qc = Q(c) + Q(1,2), fa;
	Q qsr = qr, qsc = qc;
//	cout << endl;
	while(1){
		Q cfa = getFactor(qr,qc,dr,dc);
		qr = qr + cfa * Q(dr);
		qc = qc + cfa * Q(dc);
/*		qr.print();
		cout << " ";
		qc.print();
		cout << " ";
		cout << "(" << dr << " "<< dc << ")" << endl;*/
		fa = fa + cfa;
//		cout << "fa = ";
//		fa.print();
//		cout << endl;
//		cout << "VG: " << fa.num * fa.num * (dr * dr + dc * dc) <<" > " << D * D * fa.den * fa.den << endl;
		if(fa.num * fa.num * (dr * dr + dc * dc) > D * D * fa.den * fa.den)break;
		if(qr == qsr && qc == qsc)return true;
		int ro, rn, co, cn;
		ro = (qr.num - 1) / qr.den;
		rn = qr.num / qr.den;
		if(dr < 0)swap(ro, rn);
		co = (qc.num - 1) / qc.den;
		cn = qc.num / qc.den;
		if(dc < 0)swap(co, cn);
		if(grid[ro][co] == '#'){
			cout <<"FAIL\n";
			return false;
		}
		if(grid[rn][cn] =='#'){
			if(grid[ro][cn] == '#'){
				if(grid[rn][co] == '#'){
					dr = -dr;
					dc = -dc;
				} else dc = -dc;
			} else {
				if(grid[rn][co] == '#') dr = -dr;
				else return false;
			}
		}
	}
	return false;
}

int calc(){
	int res = 0;
	int r = 0,c=0;
	FOR(rr,0,R)FOR(cc,0,C)if(grid[rr][cc] =='X'){
		r = rr;
		c = cc;
	}
	FOR(i,0,sz(dirs)){
		int dr = dirs[i].first;
		int dc = dirs[i].second;
		if(dr*dr+dc*dc<=D*D)
			if(check(r,c,dr,dc))++res;
	}
	return res;
}
int main() {
	dirs.clear();
	FOR(i,-50,51)
		FOR(j,-50,51)
			if(gcd(abs(i),abs(j))==1 && i*i + j*j <= 50*50)
				dirs.pb(mp(i,j));

	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cin >> R >> C >> D;
		FOR(i,0,R)cin >> grid[i];
		cout <<"Case #" << tcc << ": " << calc() << endl;
	}
	return 0;
}
