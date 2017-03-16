#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int a,b,k;
int p2[33];

LL doit(int x,int y,int z,int at) {
    if (z <= 0) return 0;
    //printf("%d: %d,%d,%d\n",at,x,y,z);
    LL ret = 0;
    if (x < y) swap(x,y);
    if (x <= z) return x*1LL*y;
    if (x > p2[at] && y > p2[at]) {
        ret += doit(x-p2[at],y-p2[at],z-p2[at],at-1);
        ret += doit(x-p2[at],p2[at],z,at-1);
        ret += doit(p2[at],y-p2[at],z,at-1);
        ret += doit(p2[at],p2[at],z,at-1);
    }
    else {
        if (x > p2[at]) {
            ret += doit(x-p2[at],y,z,at-1);
            ret += doit(p2[at],y,z,at-1);
        }
        else {
            ret += doit(x,y,z,at-1);
        }
    }
    return ret;
}

int main() {
    int tc;
    scanf("%d",&tc);
    p2[0] = 1;
    for (int i=1; i<31; i++)
        p2[i] = p2[i-1]*2;
    for (int t=1; t<=tc; t++) {
        scanf("%d%d%d",&a,&b,&k);
        LL ans = doit(a,b,k,30);
        printf("Case #%d: %lld\n",t,ans);
    }
	return 0;
}
