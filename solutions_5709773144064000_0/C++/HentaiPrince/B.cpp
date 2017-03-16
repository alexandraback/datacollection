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
int n , m;
int a[5][5] , b[20];
int cases = 0;
void Solve(){
     int i , j , k , l;
     double C , F , X;
     cin >> C >> F >> X;
     double ans = X/2 , now = 0 , t = 2;
     for (i=1;i<=X;++i){
         now += C/t;
         t += F;
         ans = min(ans,now + X/t);
     }
     printf("Case #%d: %.7f\n",++cases,ans);
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
