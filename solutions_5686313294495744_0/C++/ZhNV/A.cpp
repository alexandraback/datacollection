#include <bits/stdc++.h>
using namespace std;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 2e3 + 15;
const int Q = 1e9 + 7;


const int ALP = 300;


string a[ALP][2];
int main(){
    srand(time(NULL));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int TT = 0; TT < T; TT++) {
		int n;
		cin >>n;
		for (int i = 0; i < n; i++)
			cin >> a[i][0] >> a[i][1];
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			map<string, bool> used1, used2;
			int cnt = 0;
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) {
					used1[a[i][0]] = true;
					used2[a[i][1]] = true;
				}
			}
			for (int i = 0; i < n; i++) {
				if (((mask >> i) & 1) == 0) {
					if (!used1[a[i][0]] || !used2[a[i][1]])
						ok = false;
			    	cnt++;
				}
			}
			if (ok)	{
				ans = max(ans, cnt);
			}	
		}	
		cout << "Case #" << TT + 1 << ": " << ans << "\n";
		cerr << TT << endl;
	}
		
    return 0;
}   