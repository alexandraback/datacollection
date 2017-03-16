#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)
#define foreach(itr, c) forl(itr, (c).begin(), (c).end())
#define rforeach(itr, c) forl(itr, (c).rbegin(), (c).rend())

template<typename T> inline void step(T& i, T& t) { if(i < t) i++; else i--;}
template<typename T> inline int towards(T i, T t) { if(i < t) return ++i; else if(i > t) return --i; else return i;}
template<typename T> inline int away(T i, T t) { if(i < t) return --i; else if(i > t) return ++i; else return i;}
#define sforl(i, s, t) for(__typeof(s) i = s; i != t; step(i,t))

#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl

#define gcase int T; cin >> T; for(int gtest = 1; gtest <= T; gtest++)
#define gstate() cerr << "Case: " << gtest << '/' << T << endl
#define gout cout << "Case #" << gtest << ": "

int gcd(int a, int b) { if(b == 0) return a; return gcd(b, a % b); }

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int main() {
	gcase {
		gstate();
		int A, B;
		cin >> A >> B;
		vector<double> p(A), ps(A);
		forl(a, 0, A) {
			cin >> p[a];
			if(a>0) ps[a] = ps[a-1] * p[a];
			else ps[a] = p[a];
		}
		double retry = 2+B;
		//double cont = (B-A+1)*ps[A-1]+(2*B-A+2)*(1-ps[A-1]);
		//cerr << (B-A+1)*ps[A-1] << ',' << (2*B-A+2)*(1-ps[A-1]) << endl;
		//cerr << retry << ',' << cont << endl;
		//min(retry,cont);
		double ans = retry;
		//cerr << "r:" << retry << endl;
		forl(a, 0, A) {
			double back = (B-A+1+2*a)*ps[A-a-1] + (2*B-A+2+2*a)*(1-ps[A-a-1]);
			//cerr << setprecision(10) << a << ':' << back  << ',' << ps[A-a-1] << ';' << (B-A+1+2*a)*ps[A-a-1] << '+' << (2*B-A+2+2*a)*(1-ps[A-a-1]) << endl;
			ans = min(ans, back);
		}
		gout << setprecision(12) << ans << endl;
	}
}
