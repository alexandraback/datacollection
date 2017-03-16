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

bool game(int x,int r,int c){
     if (r>c) swap(r,c);
     
     if ((r*c)%x!=0) return 0;
     
     if (x<=2) return 1;
     if (x==3){
        if (r<=1) return 0;
        else return 1;
     }
     if (x==4){
        if (r<=2) return 0;
        else return 1;
     }
     /*
     if (x==5){
        if (r<=2) return 0;
        else if (r==3){
             
        }
     }
     if (x==6){
     }
     if (x>=7) return 0;
     */
}
void solve(){
     printf(" ");
     int x,r,c;
     scanf("%d %d %d",&x,&r,&c);
     printf(game(x,r,c)?"GABRIEL\n":"RICHARD\n");
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
