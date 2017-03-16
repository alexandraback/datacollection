#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

int n, tc, s, p, pts[1000];

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		cin >> n >> s >> p;
		REP(i,n) cin >> pts[i];
		int ans = 0, probans = 0;
		REP(i,n){
			int rem = pts[i]%3;
			int maxpts = pts[i]/3 + (pts[i]%3 ? 1 : 0);
			int minpts = pts[i]/3;
			if (maxpts >= p) ++ans;
			else if (maxpts==p-1&&rem==2 || maxpts==p-1&&rem==0&&minpts) ++probans;
		}
		ans += MIN(probans, s);
		cout << "Case #" << ic+1 << ": " << ans << endl;
	}
	return 0;
};