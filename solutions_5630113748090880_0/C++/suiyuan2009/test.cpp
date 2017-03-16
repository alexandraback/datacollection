#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2505;
typedef long long ll;

int c[maxn],n;

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--) {
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=0; i<n+n-1; i++)
            for(int j=0; j<n; j++) {
                int x;
                scanf("%d",&x);
                c[x]++;
            }
        printf("Case #%d:",++ncase);
        for(int i=0; i<maxn; i++)
            if(c[i]&1)printf(" %d",i);
        printf("\n");
    }
    return 0;
}
