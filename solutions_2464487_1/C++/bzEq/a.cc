#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <utility>

using namespace std;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())
#define MP(x,y) make_pair((x),(y))

typedef long long ll;
const int INF=2147483647;
const int MOD=(int)1e9+7;
//const int MAX=
int main() {
    int T;
    scanf("%d",&T);
    REP(nc,T) {
        double r,t;
        scanf("%lf%lf",&r,&t);
        ll m=(ll)ceil((1-2*r+sqrt((2*r-1)*(2*r-1)+8*t))/4);
        ll n=m;
        for (; 2*n*n+(2*r-1)*n-t<=0; n++);
        n--;
        printf("Case #%d: %lld\n",nc+1,n);
    }
    return 0;
}
