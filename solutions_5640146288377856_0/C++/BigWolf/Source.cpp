#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <functional>
#include <memory>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cctype>
#include <limits.h>
using namespace std;
#define ll long long
#define ull unsigned ll
const int INF = 1e9 + 7;
const double Pi = 2 * acos(0.);
const double EPS = 1e-13;
template<class T> inline T sqr(const T& x){ return x*x; }
struct point{
	double x, y;
	point(double a = 0, double b = 0) :x(a), y(b){}
};
inline point lineFunc(const point& a, const point& b){
	point result;
	result.x = (b.y - a.y) / (b.x - a.x);
	result.y = a.y - a.x*result.x;
	return result;
}
template<class T>
inline void in(const T& start, const T& end){
	for (T it = start; it != end; ++it){
		cin >> *it;
	}
}
template<class T>
inline void out(const T& start, const T& end){
	for (T it = start; it != end; ++it){
		cout << *it << " ";
	}
}
inline double dist(const point& a, const point& b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline double vectorLenth(const point& a){
	return sqrt(sqr(a.x) + sqr(a.y));
}
void run();
int main(){
	ios_base::sync_with_stdio(0);
#ifdef TRAINING
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cout.precision(13);
	cout.setf(cout.fixed);
	run();
	return 0;
}


void run(){
	int t, r, c, w;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cin >> r >> c >> w;
		cout << "Case #" << i << ": " << r * (c / w) + w - !(c%w) << endl;
	}
}