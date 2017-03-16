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
char a[2000],b[3000];
void MAIN(){
    scanf("%s",a);
    int n=strlen(a);
    int l,r;
    l=1500; r=1500; b[1500]=a[0];
    rep(i,n-1)
    {
        if (a[i]>=b[l]) b[--l]=a[i]; else b[++r]=a[i];
    }
    rep2(i,l,r) printf("%c",b[i]);
    printf("\n");
}
int main() {
    freopen("d:\\oi\\gcj1a\\A-large.in","r",stdin);
    freopen("d:\\oi\\gcj1a\\A-large.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d: ",i);
        MAIN();
    }
    return 0;
}