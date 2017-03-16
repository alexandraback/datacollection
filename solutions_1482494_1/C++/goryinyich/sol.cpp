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

int n, tc, stars;
int r[1000][2];
bool u[1000][2];

int brush(){
	REP(i,n) if (!u[i][1] && r[i][1]<=stars){
		u[i][1] = true;
		++stars;
		if (!u[i][0]){
			u[i][0] = true;
			++stars;
		}
		return 0;
	}
	int besti = -1;
	int maxr = -1;
	REP(i,n) if (!u[i][0] && r[i][0]<=stars){
		if (r[i][1] > maxr){
			besti = i;
			maxr = r[i][1];
		};
	}
	if (besti == -1) return -1;
	++stars;
	u[besti][0] = true;
	return 0;
}

int get(){
	int res = 0;
	while (stars < 2*n){
		++res;
		int r = brush();
		if (r < 0) return -1;
	}
	return res;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		cin >> n;
		REP(i,n) cin >> r[i][0] >> r[i][1];
		memset (u, false, sizeof (u));
		stars = 0;
		int r = get();
		cout << "Case #" << ic+1 << ": ";
		if (r >= 0) cout << r << endl;
		else cout << "Too Bad" << endl;
	}
	return 0;
};