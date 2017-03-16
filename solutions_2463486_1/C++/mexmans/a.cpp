#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
LL val[] = {
1,
2,
3,
11,
22,
101,
111,
121,
202,
212,
1001,
1111,
2002,
10001,
10101,
10201,
11011,
11111,
11211,
20002,
20102,
100001,
101101,
110011,
111111,
200002,
1000001,
1001001,
1002001,
1010101,
1011101,
1012101,
1100011,
1101011,
1102011,
1110111,
1111111,
2000002,
2001002
};
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		LL a,b; cin >> a >> b;
		int res = 0;
		for (int i = 0; i < 39; i++) {
			if (a <= sqr(val[i]) && sqr(val[i]) <= b) {
				res++;
			}
		}
		cout << "Case #" << t << ": " << res << endl;
	}
	return 0;
}
