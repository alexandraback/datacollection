#define _CRT_SECURE_NO_DEPRECATE
#define _ASSERTE

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin,a.end()
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tt;
	cin >> tt;
	forn(t, tt) {
		int n, m, a[120][120];
		cin >> n >> m;
		forn(i, n)
			forn(j, m)
				cin >> a[i][j];
		string ans = "YES";
		forn(i, n)
			forn(j, m){
				int str_ok = 1;
				forn(k, m)
					if (a[i][k] > a[i][j])
						str_ok = 0;
				int col_ok = 1;
				forn(k, n)
					if (a[k][j] > a[i][j])
						col_ok = 0;
				if (str_ok + col_ok == 0){
					ans = "NO";
					break;
				}
			}

		cout << "Case #" << (t + 1) << ": " << ans << endl;
	}

	return 0;
}