#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
#define ITER(v)      __typeof((v).begin())
#define FOREACH(i,v) for(ITER(v) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
#define x first
#define y second

const int N = 2036;
int a[N], s[N], o[N], idx[N];

int main() {
	int t; scanf("%d", &t); FOE(ca,1,t) {
		int n, S, p; scanf("%d%d%d", &n, &S, &p);
		int a[n]; FOR(i, 0, n) scanf("%d", a+i);
		int ns = 0;
		FOR(i, 0, n) {
			s[i] = -1999;
			if (2 <= a[i] && a[i] <= 28)	//...
			FOE(k, 2, 4) {
				int y = a[i] + k;
				if (y % 3 == 0 && 1 <= y / 3 && y / 3 <= 10) {
					s[i] = y / 3;
					break;
				}
			}
			o[i] = a[i] / 3 + (a[i] % 3 > 0);
		}
		
//		FOR(i, 0, n) {
	//		printf("%d %d\n", o[i], s[i]);
		//} puts("");		
		int ans = 0;
		FOR(i, 0, n) {
			if (o[i] >= p) {
				ans++;
			}
		}
		FOR(i, 0, n) {
			if (S > 0 && o[i] < p && s[i] >= p) {
				--S;
				ans += (s[i] >= p);
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
