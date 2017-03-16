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
#define EPS 1e-14
#define delta 1e-9

int tt, n;

int s[1234], c[1234];
long double d[1234];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	cin >> tt;
	forn(t, tt) {
		int x = 0;
		cin >> n;
		forn(i, n) {
			cin >> s[i];
			x += s[i];
		}


		forn(i, n) {
			long double L = 0, R = 1;

			forn(it, 10000) {

				long double m = (L + R) / 2;
				long double score = s[i] + m * x;
				long double per = 1 - m;

				bool happy = 1;
				forn(j, n) {
					if (i != j) {
						if (s[j] > score - EPS)
							continue;
						long double mm = (delta + s[i] - s[j]) * 1. / x + m;
						if (mm > per + EPS) {
							per = -1;
							break;
						}
						per -= mm;
					}
				}
				if (per > +EPS)
					happy = 0;

				if (happy) {
					d[i] = m; R = m;
				}else {
					L = m;
				}
			}
		}


		cout << "Case #" << (t + 1) << ": ";
		forn(i, n) {
			printf("%.6lf", d[i]*100);
			if (i != n - 1)
				printf(" ");
		}
		puts("");
	}

	return 0;
}
