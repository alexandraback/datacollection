#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define N 1000005
#define M 25
#define Mod 1000000007
#define INF 2000000007
typedef long long LL;
int n , m , p;
double a[1005] , b[1005];
int cases = 0;

int A(){
    int i = n , j , k = 0;
    for (j=n;j>=1;--j)
        if (a[i] > b[j]) ++k , --i;
    return k;
}

int B(){
    int i , j = n , k = 0;
    for (i=n;i>=1;--i)
        if (b[j] > a[i]) ++k , --j;
    return n-k;
}

void Solve(){
     int i , j , k , l;
     cin >> n;
     for (i=1;i<=n;++i) scanf("%lf",&a[i]);
     for (i=1;i<=n;++i) scanf("%lf",&b[i]);
     sort(a+1,a+n+1);
     sort(b+1,b+n+1);
     printf("Case #%d: %d %d\n",++cases,A(),B());
}

int main(){
    freopen("D-large.in","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
