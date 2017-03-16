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
int cases = 0;
LL gcd(LL x , LL y){ return x ? gcd(y%x,x) : y;}
void Solve(){
     int i , j , k , l;
     LL x , y , t , p , tx , ty;
     int ans = 0;
     scanf("%lld/%lld",&x,&y);
     t = gcd(x,y);
     x /= t; y /= t;
     t = y;
     while (t != 1){
           if (t % 2){
                 printf("Case #%d: impossible\n",++cases);
                 return;
           }
           t /= 2;
     }
     while (x < y){
           if (y % 2){
                 ans = 0;
                 break;
           }
           y /= 2; ++ans;
     }
     printf("Case #%d: ",++cases);
     if (ans == 0) puts("impossible"); else cout << ans << endl;
}

int main(){
    freopen("3.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
