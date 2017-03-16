/** 
 * Murilo Adriano Vasconcelos <murilo@clever-lang.org>
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <deque>
#include <ctime>
#include <cfloat>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <climits>
#include <sstream>
#include <queue>
#include <utility>
#include <cmath>
#include <tr1/unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ti(x) typeof(x.begin())
#define all(x) x.begin(), x.end()
#define fill(x, y) memset(x, y, sizeof(x)) 
#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)
#define forx(a, x) for (int a = 0; a < x; ++a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

template <typename T> T abs(const T& a) { if (a >= 0) return a; return -a; }

double dist(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

bool lessthan(double a, double b, double epsilon = EPS)
{
    return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool leq(double a, double b)
{
	if (lessthan(a, b) || (!lessthan(a, b) && !lessthan(b, a))) return true;
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		cin >> n;
		
		vector<int> v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}
		
		double need = 2 * sum / double(n);
		
		int qtd = 0;
		vector<bool> p(n, false);
		double yy = 2 * sum;
		for (int i = 0; i < n; ++i) {
			if (leq(v[i], need)) {
				qtd++;
			}
			else {
				p[i] = true;
				yy -= v[i];
			}
		}
		
		if (qtd != n) {
			need = yy / double(qtd);
		}
		
		cout << "Case #" << tt << ":";
		
		for (int i = 0; i < n; ++i) {
			if (!p[i]) {
				cout << ' ' << fixed << setprecision(7) << ((need - v[i]) / sum) * 100.0;
			}
			else {
				cout << " 0.000000";
			}
		}
		cout << '\n';
	}
	
	return 0;
}




















