#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i=1;i<=(n);++i)
#define rep2(i,x,y) for (int i=(x);i<=(y);++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
int a[10000];
int n;
void MAIN(){
    rep(i,2500) a[i]=0;
    scanf("%d",&n);
    rep(i,2*n-1)
        rep(j,n)
        {
            int t;
            scanf("%d",&t);
            a[t]=1-a[t];
        }
    rep(i,2500) if (a[i]==1) printf(" %d",i);
    printf("\n");
}
int main() {
    freopen("d:\\oi\\gcj1a\\B-large.in","r",stdin);
    freopen("d:\\oi\\gcj1a\\B-large.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d:",i);
        MAIN();
    }
    return 0;
}