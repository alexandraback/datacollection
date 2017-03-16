#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int k, l, s, mx;
string s1, s2, s3;
double ver, ans;

void rec(int pos = 0) {
	if(pos == s) {
		int cnt = 0;
		for(int i = 0; i < s; i++) if(i + l - 1 < s) {
			bool ok = 1;
			for(int f = 0; f < l; f++) {
				if(s3[i + f] != s2[f]) {
					ok = 0;
				}
			}
			cnt += ok;
		}
		ans += cnt * ver;
		mx = max(mx, cnt);
		return;
	}
	for(int i = 0; i < k; i++) {
		s3[pos] = s1[i];
		rec(pos + 1);
	}
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		mx = 0, ans = 0;
		scanf("%d%d%d\n", &k, &l, &s);
		getline(cin, s1);
		getline(cin, s2);
		s3.clear();
		for(int i = 0; i < s; i++) {
			s3.push_back(' ');
		}
		double vv = 1. / (k + 0.);
		ver = 1;
		for(int i = 0; i < s; i++) {
			ver *= vv;
		}
		rec(0);
		vv = mx * 1. - ans;
		printf("Case #%d: %.7lf\n", t, vv);
	}

	return(0);
}

// by Kim Andrey
