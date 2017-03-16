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

int K,L,S;
int maxi=-1, found = 0;
string keys, target, current;
void recur(int cur){
     if (cur==S){
        int tmp=0;
        for (int i=0;i<S;++i){
            bool ok = 1;
            for (int j=0;j<L;++j){
                if (current[i+j]!=target[j]){
                   ok=0;
                   break;
                }
            }
            tmp+=ok;
        }
        maxi = max(maxi, tmp);
        found += tmp;
     }
     else{
          for (int i=0;i<K;++i){
              current[cur] = keys[i];
              recur(cur+1);
          }
     }
}
void solve(){
     printf(" ");
     scanf("%d %d %d",&K,&L,&S);
     cin >> keys;
     cin >> target;
     for (int i=0;i<10;++i) current[i]='.';
     maxi = -1; found = 0;
     recur(0);
     double ret = 1.*found;
     for (int i=0;i<S;i++){
         ret /= (1.*K);
     }
     //cout << "CHK "<< maxi << " " << ret << endl;
     printf("%.9lf\n",(1.*maxi) - ret);
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int i=0;i<10;++i) current+='.';
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
