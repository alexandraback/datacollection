#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

#define bug puts("here");
#define lson o<<1
#define rson o<<1|1

using namespace std;

const int maxn = 1086;

int a[maxn];

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for(int kase=1;kase <=T;kase++) {
        int d;
        cin >> d;
        int p = 0;
        for(int i=0;i<d;i++) {
            scanf("%d",a+i);
            p = max(p,a[i]);
        }
        sort(a,a+d);
        int ans = 0x3f3f3f3f;
        for(int j=1;j<=p;j++)
        {
            int tmp = j;
            for(int i=d-1;i>=0;i--) {
                if(a[i] <= j) break;
                tmp += (a[i] + j - 1) / j - 1;
            }
            ans = min(ans, tmp);
        }
        printf("Case #%d: %d\n",kase,ans);
    }
}
