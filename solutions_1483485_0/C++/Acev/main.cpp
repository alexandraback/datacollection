#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

//////////////////// Defines ////////////////////

#define inf      2147483647
#define inf64    9223372036854775807
#define eps      1e-6
#define pi      3.14159265358
#define sqr(a) (a)*(a)
#define rall(a) a.rbegin(),a.rend()
#define all(a) a.begin(),a.end()
#define sz(a) (a).size()
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back 
typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define ContinueIf(x) if ((x)) continue
#define ContinueUnless(x) if(!(x)) continue

#define BreakIf(x) if ((x)) break
#define BreakUnless(x) if(!(x)) break

#define ReturnUnless(x) if (!(x)) return
#define ReturnIf(x) if ((x)) return

#define ReturnUnless2(x, ret) if (!(x)) return ret
#define ReturnIf2(x, ret) if ((x)) return ret

//////////////////// Problem Code ////////////////////

char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int k, T;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &T);
	char g[1000002];
	cin.getline(g, 1000002);

	for(k = 1 ; k <= T ; ++k) {
		string s;
		cin.getline(g, 1000002);
		int n = strlen(g);
		s.resize(n);
		for (int i = 0; i < n; ++i) {
			s[i] = g[i];
			if (g[i] >= 'a' && g[i] <= 'z') {
				s[i] = mapping[g[i] - 'a'];
			}
		}
		cout << "Case #" << k << ": " << s << endl;
	}

	return 0;
}

