#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 105;

int a[N][N], b[N][N];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) 
				cin >> a[j][k];				

		bool fail = 0;

		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				bool ok = 0;	

				int mx = a[j][k];
				for (int q = 0; q < n; q++)
					mx = max(mx, a[q][k]);					
				if (a[j][k] == mx) 
					ok = 1;

				mx = a[j][k];
				for (int q = 0; q < m; q++)
					mx = max(mx, a[j][q]);					
				if (a[j][k] == mx) 
					ok = 1;

				if (!ok) 
					fail = 1;					
			}				

		printf("Case #%d: %s\n", i + 1, fail ? "NO" : "YES");
	}

	return 0;
}
