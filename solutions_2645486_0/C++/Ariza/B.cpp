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
int act[15];
int E,R,N;
int DFS(int pos,int now){
    int best,ctr;
    if (now<0) return -1000000000;
    if (pos==N){
       return 0;
    }
    now+=R;
    if (now>E){
       now=E;
    }
    best=-1000000000;
    for (int i=0;i<=now;++i){
        ctr=DFS(pos+1,now-i)+(i*act[pos]);
        if (best<ctr) best=ctr;
    }
    return best;
}
void solve(){
     scanf("%d %d %d",&E,&R,&N);
     for (int i=0;i<N;++i) scanf("%d",&act[i]);
     if (R>=E){
        int ans=0;
        for (int i=0;i<N;++i) ans+=act[i]*E;
        printf("%d",ans);
        return;
     }
     int ans=DFS(0,E);
     printf("%d",ans);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
        printf("\n");
    }
    return 0;
}
