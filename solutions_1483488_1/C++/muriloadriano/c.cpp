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
#include <tr1/unordered_set>

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

typedef set<int> int_set;

inline int ilog10(int x)
{
	int ans = 0;
	
	while ((x /= 10)) {
		ans++;
	}
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	int A, B;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> A >> B;
		
		int back, mod, pw, front, numb, ans = 0;
		for (int x = A; x <= B; ++x) {
			int_set s;
			int nd = ilog10(x);
			
			mod = 1;
			pw = 10;
			for (int i = 0; i < nd; ++i) mod *= 10;
			
			while (mod > 1) {
				back = x % mod;
				front = x / mod;
				
				numb = back * pw + front;
				
				if (s.find(numb) != s.end()) break;
				s.insert(numb);
				
				if (numb > x && numb >= A && numb <= B) ans++;
				
				pw *= 10;
				mod /= 10;
			}
		}
		
		cout << "Case #" << tc << ": " << ans << '\n';
	}
	
	return 0;
}




















