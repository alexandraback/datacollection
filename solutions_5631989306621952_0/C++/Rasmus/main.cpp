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

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	REPE(TT,1,T) {
		cout << "Case #" << TT << ": ";
		string s;
		cin >> s;
		string res = "";
		res += s[0];
		REP(i,1,s.size()) {
			string x = res + s[i];
			string y = s[i] + res;
			if (x > y) {
				res = x;
			} else {
				res = y;
			}
		}
		cout << res << "\n";
	}
    return 0;
}