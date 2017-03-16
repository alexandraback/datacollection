#include <bits/stdc++.h>

using namespace std;
                                                                          	
#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file ""     
#define F first                       
#define S second 
#define pb push_back  
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <ll, ll> PII;
typedef double ld;
                                                                                          
const int N = 2e6; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

const int mN = 100;
typedef vector <int> vi;

int cell;
                         
bool bit(int mask, int pos) {
	return mask & (1 << pos);
}

int n;        
vector <vi> a;
vi v[N];

int main () {
#ifdef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
#endif		
	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	int tests;
	cin >> tests;
	forn(test, 1, tests) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		forn(i, 1, 2 * n - 1) {
			v[i].resize(n);
			forn(j, 0, n - 1)
				cin >> v[i][j];
		}	
		sort(v + 1, v + 2 * n);       

		forn(mask, 1, (1 << (2 * n - 1)) - 1) {
			if (_bits(mask) != n) continue;
			a.resize(n);
			forn(i, 0, n - 1)
				a[i].resize(n);
			int ptr = 0;
			bool f = 0;
			forn(i, 1, 2 * n - 1) {
				if (!bit(mask, i - 1)) continue;
				forn(j, 0, n - 1)
					a[j][ptr] = v[i][j];
				++ptr;
			}                   
			forn(i, 0, n - 1) {
				forn(j, 0, n - 1) {
					if (i && a[i - 1][j] >= a[i][j]) f = 1;
					if (j && a[i][j - 1] >= a[i][j]) f = 1;
				}
			}	
			if (f) continue;  
			ptr = 0;
			int ans = -1;
			forn(i, 1, 2 * n - 1) {
				if (bit(mask, i - 1)) continue;
				if (a[ptr] == v[i]) {
					++ptr;
					continue;
				}
				if (ans != -1) {
					f = 1;
					break;
				}
				ans = ptr;
				++ptr;
				--i;
			}
			if (f) continue;    
			if (ans == -1) ans = n - 1;	
			forn(i, 1, n - 1)
				if (a[ans][i] <= a[ans][i - 1]) f = 1;
			if (f) continue;
			forn(i, 0, n - 1)
				cout << a[ans][i] << " ";
			cout << "\n";
			break;	
		}                 
		forn(i, 1, 2 * n)
			v[i].clear();
	}
	
	return 0;         	
}
