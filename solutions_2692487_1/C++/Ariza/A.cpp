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

void solve(){
     int A,n,tmp;
     vector<int>mote;
     scanf("%d %d",&A,&n);
     for (int i=0;i<n;++i){
         scanf("%d",&tmp);
         mote.pb(tmp);
     }
     sort(mote.begin(),mote.end());
     int ctr,ta,ret;
     ret=1000000000;
     
     if (A==1){
        printf("%d\n",n);
        return;
     }
     for (int idx=n;idx>=0;--idx){
         ta=A;
         ctr=0;
         for (int i=0;i<idx;++i){
             //cout << ta << " ";
             if (mote[i]<ta) ta+=mote[i];
             else{
                  while (ta<=mote[i]){
                        ta+=(ta-1);
                        ctr++;
                  }
                  ta+=mote[i];
             }
         }
         //cout << endl;
         //cout << "OK " << idx << " " << ctr << endl;
         ret=min(ret,ctr+(n-idx));
     }
     printf("%d\n",ret);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
    }
    return 0;
}
