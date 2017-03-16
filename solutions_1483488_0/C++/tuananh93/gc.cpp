#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,a,b) for (int i = (a); i < (b); i++)
#define DOWN(i,a,b) for (int i = (a); i > (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FREOPEN freopen("C-small-attempt0.in", "r", stdin); freopen("a.out", "w", stdout)

int f[2000100][20];
int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main() {
	FREOPEN;
	int ntest;
	cin >> ntest;
	
	FOR (i, 1, 2000000) {
		f[i][0] = 0;
		int x = i;
		int cnt = 0;
		while (x) {
			cnt++;
			x /= 10;
		}
		x = i;
		
		FOR (j, 1, cnt - 1) {
			int y = (x % p[j]) * p[cnt - j] + x / p[j];
			f[i][0]++;
			f[i][f[i][0]] = y;
		}
		
		sort(f[i] + 1, f[i] + 1 + f[i][0]);
		
		int mk = f[i][0];
		f[i][0] = 1;
		FOR (j, 1, mk)
			if (f[i][j] != f[i][f[i][0]]) {
				f[i][0]++;
				f[i][f[i][0]] = f[i][j];
			}
		
	}
	
/*	FOR (i, 124, 300) {
        cout << i << ": " << endl;
        FOR (j, 1, f[i][0]) cout << f[i][j] << " " ;
        cout << endl;   
    }*/
	
	FOR (test, 1, ntest) {
		int a , b;
		int res = 0;
		cin >> a >> b;
		FOR (i, a, b)
		FOR (j, 1, f[i][0])
			res += (f[i][j] > i && f[i][j] <= b);
		
		printf("Case #%d: %d\n", test, res);
	}
	return 0;
}
