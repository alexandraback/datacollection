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

int T;
double c, f, x;

int main(){
	scanf("%d", &T);
	rep(cas, T){
		scanf("%lf%lf%lf", &c, &f, &x);
		double ret = INF;
		int top = (int)x + 10;
		double now = 0, rate = 2.0, tim = 0;
		rep(i, top){
			ret = min(ret, tim + (x - now) / rate);
			if (sign(now - c) >= 0){
				now -= c;
				rate += f;
			}
			else{
				tim += (c - now) / rate;
				now = 0;
				rate += f;
			}
		}
		printf("Case #%d: %.12f\n", cas + 1, ret);
	}
	return 0;
}
