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
const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 7); 
const ld PI = 3.1415926535897932384626433832795; 

string s1, s2;
int k;

int a[MAXN];

bool us[MAXN];
ld q[MAXN];

int main() 
{ 
     
    freopen("input.txt","rt", stdin); 
    freopen("output.txt", "wt", stdout);     
    
	cout.precision(9);
	cout.setf(ios::fixed);

	int tk;
	cin >> tk;

	forn(ii, tk){
		printf("Case #%d: ", ii + 1);

		memset(us, 0, sizeof us);

		int n;
		cin >> n;

		int x = 0;
		
		forn(i, n){
			cin >> a[i];
			x += a[i];
		}

		int idx = 0;

		while (true){
			ld c = 0;
			bool ok = 1;

			forn(i, n){
				if (!us[i]) idx = i;
			}
			
			int cnt = 0;

			forn(i, n) {
				if (us[i]) continue;
				
				c += (.0 + a[idx] - a[i]) / x;
				++cnt;
			}

			if (cnt == 0) cnt = 1;

			ld t = (1 - c) / cnt;

			forn(i, n){
				if (us[i]){
					q[i] = 0;
					continue;
				}

				q[i] = t + (.0 + a[idx] - a[i]) / x;
				if (q[i] < -EPS){
					us[i] = 1;
					ok = 0;
				}
				//cout << q * 100 << " ";
			}

			if (ok) break;
		}
		
		forn(i, n){
			cout << q[i] * 100 << " ";
		}
		cout << endl;
	}
	

	return 0; 
}