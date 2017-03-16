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

int T, e, r, n, v[12], cur[12], maxi = 0, ans[12];

void gen(int index, int energy, int osten) {
	if (index == n) {
		int curr = 0;
		for (int i = 0; i < n; i++)
			curr += cur[i] * v[i];
		if (curr > maxi) {
			maxi = max(maxi, curr);
			for (int i = 0;i < n; i++)
				ans[i] = cur[i];
		}
		return;
	}
	cur[index] = energy;
	osten = min(osten + r, e);
	for (int i = 0; i <= osten; i++)
		gen(index + 1, i, osten - i);
	return;
}

int main()
{
	freopen("A.txt", "r", stdin);
	freopen("Ans.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cout.flags(ios::fixed);
    cout.precision(2);
	cin >> T;
	for (int q = 1; q <= T; q++) {
		cin >> e >> r >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		maxi = 0;
		for (int i = 0; i <= e; i++)
			gen(0, i, e - i);
		cout << "Case #" << q << ": " << maxi << '\n';
		/*for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << endl << endl;*/
	}
    return 0;
}



