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
     int len;
     string str;
     cin >> len >> str;
     int ctr=0,ans=0;
     for (int i=0;i<=len;++i){
         if (str[i]=='0') continue;
         if (ctr<i){
            ans+=(i-ctr);
            ctr=i;
         }
         ctr+=(str[i]-'0');
     }
     printf("%d\n",ans);
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
