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
int ds[23][2000001];
long double d[1234];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	cin >> tt;
	forn(t, tt) {
		cin >> n;
		int x = 0;
		forn(i, n){
			cin >> c[i];
			x += c[i];
		}
		int res = 0, res2 = 0;
		memset(ds, 0, sizeof ds);
		
		forn(i, n) {
			if (res)break;
			forn(sum, 2000001) {
				if (res)break;
				if (sum < c[i])continue;
				if (sum == c[i]) {
					ds[i][sum] = (1 << i);
					continue;
				}
				ds[i][sum] = 0;
				bool was = 0;
				forn(j, i) {
					if (ds[j][sum - c[i]]) {
						if (was) {
							res = ds[i][sum] ^ (1 << i);
							res2 = ds[j][sum - c[i]];
							break;
						}
						was = 1;
						ds[i][sum] = ds[j][sum - c[i]] ^ (1 << i);
					}
				}
			}
		}
		

		cout << "Case #" << (t + 1) << ":\n";
		if (res){
			forn(i, n)
				if (res & (1 << i))
					printf("%d ", c[i]);
			puts("");
			forn(i, n)
				if (res2 & (1 << i))
					printf("%d ", c[i]);
			puts("");
		}else {
			puts("Impossible");
		}
		/*
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
						if (s[j] > score + EPS)
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
		*/
	}

	return 0;
}
