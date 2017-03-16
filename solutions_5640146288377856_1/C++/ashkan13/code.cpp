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

/*_____________________________________________________________________________________*/
int main() {
	//*
	freopen("aa.in", "r", stdin);
	freopen("aa.out", "w", stdout);
	//*/
	int T;
	cin >> T;
	For1 (tc, T) {
		//cerr << "--> " << tc << " / " << T << endl;
		int row, col, w;
		cin >> row >> col >> w;

		int ans = row * col;
		
		if (w != 1) {
			if (w == col) ans = row + w - 1;
			else {
				ans = 0;
				int x = col / w;
			
				// nw
				if (row != 1) ans += (row - 1) * x;

				if (x * w == col) x--;
				ans += x + w;
			}
		}

		cout << "Case #" << tc << ": ";
		cout << ans << endl;
	}
	
	return 0;
}
/*
6
1 4 2
1 7 7
2 5 1

2 4 2
2 5 2
3 4 3

3
7
10

5
6
6
*/