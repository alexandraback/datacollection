#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL unsigned long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 100000000
using namespace std;

#define MAXN 110000
double d[MAXN];
int A, B;
int a, b;
int vis[MAXN][2];
double dp[MAXN][2];
double solve(int pos, int en) {
	if(pos == a) {
		if(en == 0) {
			return 1 + B - a;
		}
		else {
			return 2 + B - a + B;
		}
	}
	if(vis[pos][en] != 0)
		return dp[pos][en];
	double &ret = dp[pos][en] = (double)1e18;
	vis[pos][en] = 1;
	ret = solve(pos + 1, en) * d[pos];
	ret += solve(pos + 1, 1) * (1.0 - d[pos]);
	return ret;
}

int main() {
	int tes;
	cin >> tes;
	for(int c = 1; c <= tes; c++) {
		CLR(vis);
		cin >> A >> B;
		for(int i = 0; i < A; i++) {
			cin >> d[i];
		}
		double ans = 2.0 + (double)B;
		for(int j = 0; j <= A; j++) {
			CLR(vis);
			CLR(dp);
			a = A - j;
			double a1 = j + solve(0, 0);
			//cout<<c<<" : " << a1<<endl;
			ans = min(a1, ans);
		}
		printf("Case #%d: %.6f\n", c, ans);
	}
	return 0;
}



