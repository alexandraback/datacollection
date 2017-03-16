#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <set>
#include <algorithm>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
using namespace std;
const int maxn = 102;
int size[maxn];
int a,n;

void read() {
    scanf("%d%d",&a,&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&size[i]);
    }
    sort(size, size + n);
    return;
}

void solve() {
    if (a == 1) {
        printf("%d\n",n);
        return;
    }
    int l = 0;
    while(l < n && size[l] < a) {
        a += size[l++];
    }
    int res = n - l;
    int cnt = 0;
    while(l < n) {
        while(a <= size[l]) {
            cnt++;
            a += a-1;
        }
        while(l < n && size[l] < a) {
            a += size[l++];
        }
        res = MIN(res, cnt + n - l);
    }
    printf("%d\n",res);
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("C-large-1.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int i=1;i<=cas;i++) {
        printf("Case #%d: ",i);
        read();
        solve();
    }
    return 0;
}
