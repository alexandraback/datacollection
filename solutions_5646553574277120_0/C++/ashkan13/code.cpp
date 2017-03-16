// In the Name of Allah
// AD13
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
typedef vector <int> VI;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/

int c, d, v;
int dArr[1010];
bool is[1010];

void f (set <int> & pos, int ind) {
	if (ind == d) {
		int tot = 0;
		For (i, d)
			if (is[i])
				tot += dArr[i];
		pos.insert(tot);
	}
	else {
		is[ind] = false;
		f (pos, ind + 1);
		is[ind] = true;
		f (pos, ind + 1);
	}
}

/*_____________________________________________________________________________________*/
int main() {
	//*
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	//*/
	int T;
	cin >> T;
	For1 (tc, T) {
		cerr << "--> " << tc << " / " << T << endl;
		cin >> c >> d >> v;
		For (i, d) cin >> dArr[i];
		int ans = 0;
		if (dArr[0] != 1) {
			ans++;
			dArr[d++] = 1;
			//sort (dArr, dArr + d);
		}

		set <int> pos;
		f (pos, 0);
		while (true) {
			int can = 0;
			For1 (i, v) {
				if (pos.find(i) == pos.end()) {
					can = i;
					break;
				}
			}
			if (can == 0) break;
			ans++;
			dArr[d++] = can;
			f (pos, 0);
		}

		cout << "Case #" << tc << ": ";
		cout << ans << endl;
	}
	
	return 0;
}
/*

*/