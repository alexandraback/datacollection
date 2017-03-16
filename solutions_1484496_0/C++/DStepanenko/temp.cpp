#include <iostream> 
#include <stdio.h> 
#include <cmath> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <sstream> 
#include <utility> 
#include <map> 
#include <set> 
#include <memory.h> 
using namespace std; 
 
#define forn(i, n) for(int i = 0; i < (int) (n); ++i) 
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i) 
 
#define ll long long 
#define ld long double 
#define PLL pair <ld, ld> 
#define PII pair <int, int> 
#define pb push_back 
#define sz size

const ld EPS = 1e-7; 

const int MAXN = 1010;
const int MAXM = (1 << 21) + 3;

const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 7); 
const ld PI = 3.1415926535897932384626433832795; 

string s1, s2;
int k;

int a[MAXN], b[MAXM];

int mask[MAXN];
map <int, int> M;

int main() 
{ 
     
    freopen("input.txt","rt", stdin); 
    freopen("output.txt", "wt", stdout);     
    
	cout.precision(9);
	cout.setf(ios::fixed);

	int tk;
	cin >> tk;

	mask[0] = 1;
	
	forn(i, 25){
		mask[i + 1] = mask[i] * 2;
	}

	forn(ii, tk){
		printf("Case #%d:\n", ii + 1);	

		int n;
		cin >> n;

		forn(i, n){
			cin >> a[i];
		}

		b[0] = 0;
		M.clear();

		fore(ma, 1, mask[n]){
			forn(i, n){
				if (ma & mask[i]) {
					b[ma] = b[ma - mask[i]] + a[i];
					break;
				}
			}
			M[b[ma]] = ma;
		}
		bool ok = 0;
		int m1, m2;

		fore(ma, 1, mask[n]){
			if (M[b[ma]] != ma){
				ok = 1;
				int m3 = ma;
				int m4 = M[b[ma]];

				m1 = m3 - (m3 & m4);
				m2 = m4 - (m3 & m4);
				break;
			}
		}

		if (ok){
			int s1 = 0, s2 = 0;

			forn(i, n){
				if (m1 & mask[i]) s1 += a[i];
				if (m2 & mask[i]) s2 += a[i];
			}
			//cout << s1 << " " << s2 << endl;
			if (s1 != s2) cout << "asddasdasasdasdadsadsa!!!!!!!!";
		}
		if (!ok) cout <<  "Impossible\n";
		else
		{
			forn(i, n){
				if (m1 & mask[i]) cout << a[i] << " ";
			}
			cout << endl;

			forn(i, n){
				if (m2 & mask[i]) cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	

	return 0; 
}