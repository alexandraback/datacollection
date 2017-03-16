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

const int N = 1005;

double naomi[N], ken[N];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> naomi[j];
		for (int j = 0; j < n; j++)
			cin >> ken[j];
		sort(naomi, naomi + n);
		sort(ken, ken + n);

		int nao[2];
		nao[0] = nao[1] = 0;

		int p2 = 0;
		for (int j = 0; j < n; j++) {
			while (p2 < n && ken[p2] < naomi[j]) p2++;
			if (p2 >= n)
				nao[1]++;
			p2++;
		}

		p2 = n - 1;
		for (int j = 0; j < n; j++) {
			bool ok = 1;
			for (int k = p2, q = n - 1; k >= 0; k--, q--) {
				if (naomi[q] < ken[k])
					ok = 0;
			}

			if (ok) {				
				break;
			}
			else {
				p2--;
				nao[0]--;
			}	
		}
		nao[0] += n;
		printf("Case #%d: %d %d\n", i + 1, nao[0], nao[1]);
	}



	return 0;
}
