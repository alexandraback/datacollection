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

int ten[100] = {1};
int vis[2222222] = {0};

int main() {
	FOE(i, 1, 9) ten[i] = ten[i-1] * 10;
	
	int t; scanf("%d", &t); FOE(ca,1,t) {	
		int a, b; scanf("%d%d", &a, &b);
		int n = 0; while (a >= ten[n]) ++n;
		int ans = 0;
		FOE(x, a, b) vis[x] = 0;
		FOE(x, a, b) {
			FOR(i, 1, n) {
				int y = x/ten[i] + (x%ten[i]*ten[n-i]);
				if (a <= y && y <= b && y > x && vis[y] != x) {
					vis[y] = x;
					ans++;
				}
			}
		}
		printf("Case #%d: ", ca);
		printf("%d\n", ans);
	}
	return 0;
}
