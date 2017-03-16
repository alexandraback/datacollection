#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
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
int N,M,K;

void solve2(){
     int tmp;
     vector<int> num,gue;
     for (int i=0;i<K;++i){
         scanf("%d",&tmp);
         num.pb(tmp);
     }
     bool memo[256];
     memset(memo,0,sizeof(memo));
     int ctr;
     for (int i=2;i<=M;++i){
         for (int j=2;j<=M;++j){
             for (int k=2;k<=M;++k){
                 memset(memo,0,sizeof(memo));
                 memo[i]=1;
                 memo[j]=1;
                 memo[k]=1;
                 memo[i*j]=1;
                 memo[j*k]=1;
                 memo[i*k]=1;
                 memo[i*j*k]=1;
                 memo[1]=1;
                 ctr=0;
                 for (int l=0;l<K;++l){
                     if (memo[num[l]]) ctr++;
                 }
                 if (ctr==K){
                    printf("%d%d%d\n",i,j,k);
                    return;
                 }
             }
         }
     }
}
void solve(){
     int R;
     scanf("%d %d %d %d",&R,&N,&M,&K);
     for (int i=0;i<R;++i){
         solve2();
     }
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:\n",test);
        solve();
    }
    return 0;
}
