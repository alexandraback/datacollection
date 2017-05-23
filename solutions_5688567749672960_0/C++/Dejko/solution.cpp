#include <cstdio>

using namespace std;

int t[1000008]={0},rev;

inline int reversee(int x) {
    int rev=0;
    while (x) {
        rev=rev*10 + x%10;
        x/=10;
    }
    return rev;
}

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("AAA.out","w",stdout);

    t[1]=1;
    for (int i=2; i<=1000000; i++) {
        rev=reversee(i);
        t[i]=t[i-1]+1;
        if (rev<i && i%10!=0) {
            if (t[rev]+1 < t[i]) t[i]=t[rev]+1;
        }
    }

    int T,n;
    scanf("%d",&T);
    for (int tp=1; tp<=T; tp++) {
        scanf("%d",&n);
        printf("Case #%d: %d\n",tp,t[n]);
    }

    return 0;
}
