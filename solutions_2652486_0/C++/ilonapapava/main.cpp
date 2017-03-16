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


int a[10], f[5], z[10], r, n, m, k;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cout.flags(ios::fixed);
    cout.precision(2);
	cin >> r >> r >> m >> n >> k;
	cout << "Case #1:" << endl;
	for (int q = 1; q <= r; q++) {
		for (int i = 1; i <= 7; i++)
			cin >> a[i];
		bool g = 0;
		for (int i1 = 2; i1 <= 5; i1++) {
			if (g) break;
			for (int i2 = 2; i2 <= 5; i2++) {
				if (g) break;
				for (int i3 = 2; i3 <= 5; i3++) {
					f[1] = i1;
					f[2] = i2;
					f[3] = i3;
					z[1] = 1;
					z[2] = f[3];
					z[3] = f[2];
					z[4] = f[1];
					z[5] = f[1] * f[3];
					z[6] = f[1] * f[2];
					z[7] = f[2] * f[3];
					z[8] = f[1] * f[2] * f[3];
					bool ff = 0;
					for (int i = 1; i <= 7; i++) {
						ff = 0;
						for (int j = 1; j <= 8; j++)
							if (a[i] == z[j]) {
								ff = 1;
								break;
							}
						if (!ff) break;
					}
					if (ff) {
						cout << i1 << i2 << i3 << '\n';
						g=  1;
						break;
					}
				}
				
			}
		}
	}
    return 0;
}



