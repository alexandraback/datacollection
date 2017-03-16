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

typedef tr1::unordered_map<char, char> hash;

int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	int N, S, p;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> N >> S >> p;
		
		vector<int> scores(N);
		
		for (int i = 0; i < N; ++i) cin >> scores[i];
		
		sort(scores.begin(), scores.end());
		
		int ans = 0;
		int x, rem;
		for (int i = 0; i < N; ++i) {
			if (scores[i] == 0) {
				if (!p) ans++;
				continue;
			} 
			
			rem = scores[i] % 3;
			
			if (S) {
				x = scores[i] / 3;
				
				if (rem == 0) {
					if (x + 1 >= p) {
						S--;
						ans++;
					}
				}
				else if (rem == 2) {
					if (x + 2 >= p) {
						S--;
						ans++;
					}
				}
				else {
					if (x + 1 >= p) {
						ans++;
					}
				}
			}
			else {
				x = scores[i] / 3;
				
				if ((rem <= 1) && ((scores[i] - (2 * x)) >= p)) ans++;
				else if (rem == 2 && (x + 1 >= p)) ans++;
			}
		}
		
		cout << "Case #" << tc << ": " << ans << '\n';
	}
	
	return 0;
}




















