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

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    REP(ic,tc){
        int m, n;
        cin >> m >> n;
        vector<vector<int> > a(m, vector<int>(n, 0));
        REP(i,m) REP(j,n) cin >> a[i][j];
        bool ok = true;
        for (int i = 0; i < m && ok; ++i){
            for (int j = 0; j < n && ok; ++j){
                bool be = true;
                REP(k,n) if (a[i][k] > a[i][j]) be = false;
                if (!be) {
                    be = true;
                    REP(k,m) if(a[k][j] > a[i][j]) be = false;
                    if (!be) ok = false;
                }
            }
        }
        cout << "Case #" << ic+1 << ": ";
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
};