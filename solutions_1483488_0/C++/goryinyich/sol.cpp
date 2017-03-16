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

int tc;
string a, b;
int m, n, p10[9];

int main(){
	p10[0] = 1;
	for (int i = 1; i < 9; ++i) p10[i] = 10*p10[i-1];
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		cin >> a >> b;
		int l = a.size();
		int m = atoi (a.c_str());
		int n = atoi (b.c_str());
		int ans = 0;
		for (int i = m; i <= n; ++i){
			int t = i;
			set<int> q;
			REP(j,l-1){
				t = t/10 + (t%10)*p10[l-1];
				if (t > i && t <= n) q.insert(t);
			}
			ans += q.size();
		}
		cout << "Case #" << ic+1 << ": " << ans << endl;
	}
	return 0;
};