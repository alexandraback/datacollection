#pragma comment(linker, "/STACK:16777216")
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime>
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

#define bublic public:
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define y0 y32479
#define y1 y95874

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-9;
const int N = (int)1e5+5;
const int INF = (int)1e9+10;

class point {
public:
	int x, y;
	point() {}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

int n, X, Y, kolmaxi = 0, kolgood = 0;

inline int get_level(int cc) {
	if (cc <= 6) return 1;
	if (cc <= 15) return 2;
	return 3;
}

inline bool is_here(vector <point> & p, point P) {
	for (int i= 0; i < p.size(); i++)
		if (p[i].x == P.x && p[i].y == P.y)
			return true;
	return false;
}

void gen(vector< point> & p, int curn) {
	if (curn == n) {
		kolmaxi++;
		for (int i = 0; i < p.size(); i++)
			if (p[i].x == X && p[i].y == Y) {
				kolgood++;
				break;
			}
		return;
	}
	vector<point> P;
	bool f = 0;
	for (int i = 0; i < p.size(); i++) {
		if (f) break;
		for (int j = i + 1; j < p.size(); j++)
			if (abs(p[i].x - p[j].x) == 2 && p[i].y == p[j].y && !is_here(p, point((p[i].x + p[j].x) / 2, p[i].y + 1))) {
				P.pb(point((p[i].x + p[j].x) / 2, p[i].y + 1));
				f = 1;
			}
	}
	int kol = 0;
	if (f) {
		for (int i = 0; i < P.size(); i++) {
			p.pb(P[i]);
			gen(p, curn + 1);
		p.pop_back();
		}
	}
	int lev = get_level(curn + 1);
	f = 0;
	point Pp;
	if (!is_here(p, point(2 * lev, 0))) {
		Pp = point(2 * lev, 0);
		f = 1;
	}
	if (f) {
		p.pb(Pp);
		gen(p, curn + 1);
		p.pop_back();
	}
	f = 0;
		if (!is_here(p, point(-2 * lev, 0))) {
			f = 1;
			Pp = point(-2 * lev, 0);
		} 
	if (f) {
		p.pb(Pp);
		gen(p, curn + 1);
		p.pop_back();
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cout.flags(ios::fixed);
    cout.precision(9);
	
	int t;
	cin >> t;
	for (int yy = 1; yy <= t; yy++) {
		cin >> n >> X >> Y;
		
		cout << "Case #" << yy << ": ";
		if (!(abs(X) + Y <= 6))
			cout << "0.0\n";
		else if (n >= 6 && abs(X) + Y <= 2)
			cout << "1.0\n";
		else
			if (n >= 15 && abs(X) + Y <= 4)
				cout << "1.0\n";
		else {
			vector<point> p;
			p.pb(point(0, 0));
			kolmaxi = 0;
			kolgood = 0;
			gen(p, 1);
			//cout << kolgood << ' ' << kolmaxi << "    ";
			cout << (ld)(kolgood) / (ld)(kolmaxi) << '\n';
		}
	}
    return 0;
}



