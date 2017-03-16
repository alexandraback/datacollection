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

bool ispalin(int n){
    int l = 0;
    int a[25];
    while (n > 0) {
        a[l++] = n%10;
        n /= 10;
    }
    REP(i,l/2) if (a[i] != a[l-1-i]) return false;
    return true;
}

LL Lsqrt(LL n){
    LL res = (LL)sqrt(double(n));
    while (res*res > n) --res;
    while ((res+1)*(res+1) <= n) ++res;
    return res;
}

int main(){
    vector<int> is2palin (10000001, 0);
    for (LL i = 1; i < is2palin.size(); ++i) {
        is2palin[i] = ispalin(i) && ispalin(i*i);
    }
    for (int i = 1; i < is2palin.size(); ++i) is2palin[i] += is2palin[i-1];
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    REP(ic,tc){
        LL a, b;
        cin >> a >> b;
        LL i1 = Lsqrt(a);
        while (i1*i1 < a) ++i1;
        LL i2 = Lsqrt(b);
        while (i2*i2 > b) --i2;
        cout << "Case #" << ic+1 << ": " << is2palin[i2] -is2palin[i1-1] << endl;
    }
	return 0;
};