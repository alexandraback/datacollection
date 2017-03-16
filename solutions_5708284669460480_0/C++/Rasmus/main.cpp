#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iterator>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const dbl pi = 3.14159265358979323846;
const int inf = (int) 1e9;
const dbl eps = 1e-9;

const int N = (int)9e5;

int k,l,s;
string x;
string y;
int check;
int cnt = 0;
int res[N];
int mx = 0;

void go(string now) {
	if ((int)now.size() == s) {	
		int kol = 0;
		FORE(i,s - l) {
			check = 1;
			REP(j,i,i + l) {
				if (now[j] != y[j - i]) {
					check = 0;
					break;
				}
			}
			kol += check;
		}
		res[cnt++] = kol;
		mx = max(kol, mx);

		return;
	}
	FOR(i,k) {
		go(now + x[i]);
	}
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	cout << fixed << setprecision(9);
	FOR(TT,T) {		
		cin >> k >> l >> s;
		cin >> x >> y;
		mx = 0;
		cnt = 0;
		go("");
		int my = 0;
		FOR(i,cnt) { 
			my += mx - res[i];
		}
		double out = (double)my / cnt;
		cout << "Case #" << TT + 1 << ": " << out << "\n";
	}
    return 0;
}