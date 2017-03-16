#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))

void solve(){
     printf(" ");
     int a,b,k,ret;
     ret=0;
     scanf("%d %d %d",&a,&b,&k);
     for (int i=0;i<a;++i){
         for (int j=0;j<b;++j){
             if ((i&j)<k){
                ret++;
             }
         }
     }
     printf("%d\n",ret);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
