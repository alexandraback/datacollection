//By myf
//#pragma comment(linker, "/STACK:16777216")  //C++
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <complex>
#include <list>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, l, r) for(int i = (l) ; i < (r); i++)
#define MP make_pair
#define PB push_back
#define Cls(x) memset(x,0,sizeof x)
#define Print(n,x) for(int i=0;i<(n);i++) cout<<x<<" ";cout<<endl;
#define foreach(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++) //G++
#define F first
#define S second
#define X real()
#define Y imag()
#define Sqr(x) (x)*(x)
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef long long LL;
typedef complex<double> Point;
typedef Point Vec;
typedef pair<Point, Point> Line;
//typedef complex<double> Comp;

const int N = 1000000;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-6;

int n, m, r;
char v[55][55];

void print(){
	rep(i, n){
		rep(j, m){
			putchar(v[i][j]);
		}
		puts("");
	}
}

bool work(){
	rep(i, n){
		rep(j, m){
			v[i][j] = '*';
		}
	}
	if (r == 0) return false;
	if (n == 1){
		rep(i, r) v[0][i] = '.';
		v[0][0] = 'c';
		return true;
	}
	if (m == 1){
		rep(i, r) v[i][0] = '.';
		v[0][0] = 'c';
		return true;
	}
	if (r == 1){
		v[0][0] = 'c';
		return true;
	}
	if (n == 2){
		if (r <= 3 || (r & 1)) return false;
		rep(i, r / 2) v[0][i] = v[1][i] = '.';
		v[0][0] = 'c';
		return true;
	}
	if (m == 2){
		if (r <= 3 || (r & 1)) return false;
		rep(i, r / 2) v[i][0] = v[i][1] = '.';
		v[0][0] = 'c';
		return true;
	}
	if (r <= 3 || r == 5 || r == 7) return false;
	if (r <= 2 * m + 1){
		if (r & 1){
			v[2][0] = v[2][1] = v[2][2] = '.';
			rep(i, (r - 3) / 2) v[0][i] = v[1][i] = '.';
			v[0][0] = 'c';
		}
		else{
			rep(i, r / 2) v[0][i] = v[1][i] = '.';
			v[0][0] = 'c';
		}
		return true;
	}
	/*
	if (r == 3 * m + 1){
		rep(i, m) v[0][i] = v[1][i] = '.';
		rep(i, m - 1) v[2][i] = '.';
		rep(i, 2) v[3][i] = '.';
		v[0][0] = 'c';
		return true;
	}
	*/
	if (r % m == 1){
		int top = r / m + 1;
		rep(i, top - 2){
			rep(j, m){
				v[i][j] = '.';
			}
		}
		rep(i, m - 1) v[top - 2][i] = '.';
		rep(i, 2) v[top - 1][i] = '.';
		v[0][0] = 'c';
		return true;
	}
	rep(i, n){
		rep(j, m){
			if (r == 0) continue;
			r--;
			v[i][j] = '.';
		}
	}
	v[0][0] = 'c';
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	rep(cas, T){
		scanf("%d%d%d", &n, &m, &r);
		r = n * m - r;
		printf("Case #%d:\n", cas + 1);
		if (work()) print();
		else puts("Impossible");
	}
	return 0;
}
