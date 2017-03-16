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


string solve1(int x,int y){
     int ctr=0;
     int step=1;
     string ret="";
     if (x<0){
        for (;;){
            if (ctr-step<=x){
               for (int i=0;i<ctr-x;++i){
                   ret+="EW";
                   step+=2;
               }
               break;
            }
            
            ret+="W";
            ctr-=step;
            step++;
        }
     }
     else{
        for (;;){
            if (ctr+step>=x){
               for (int i=0;i<x-ctr;++i){
                   ret+="WE";
                   step+=2;
               }
               break;
            }
            
            ret+="E";
            ctr+=step;
            step++;
        }          
     }
     
     ctr=0;
     if (y<0){
        for (;;){
            if (ctr-step<=y){
               for (int i=0;i<ctr-y;++i){
                   ret+="NS";
                   step+=2;
               }
               break;
            }
            
            ret+="S";
            ctr-=step;
            step++;
        }
     }
     else{
        for (;;){
            if (ctr+step>=y){
               for (int i=0;i<y-ctr;++i){
                   ret+="SN";
                   step+=2;
               }
               break;
            }
            ret+="N";
            ctr+=step;
            step++;
        }          
     }
     return ret;
}
string solve2(int x,int y){
     int ctr=0;
     int step=1;
     string ret="";
     if (y<0){
        for (;;){
            if (ctr-step<=y){
               for (int i=0;i<ctr-y;++i){
                   ret+="NS";
                   step+=2;
               }
               break;
            }
            
            ret+="S";
            ctr-=step;
            step++;
        }
     }
     else{
        for (;;){
            if (ctr+step>=y){
               for (int i=0;i<y-ctr;++i){
                   ret+="SN";
                   step+=2;
               }
               break;
            }
            
            
            ret+="N";
            ctr+=step;
            step++;
        }          
     }
     
     ctr=0;
     if (x<0){
        for (;;){
            if (ctr-step<=x){
               for (int i=0;i<ctr-x;++i){
                   ret+="EW";
                   step+=2;
               }
               break;
            }
            
            ret+="W";
            ctr-=step;
            step++;
        }
     }
     else{
        for (;;){
            if (ctr+step>=x){
               for (int i=0;i<x-ctr;++i){
                   ret+="WE";
                   step+=2;
               }
               break;
            }
            
            ret+="E";
            ctr+=step;
            step++;
        }          
     }

     return ret;
}
void solve(){
     int x,y;
     string ans;
     scanf("%d %d",&x,&y);
     if (abs(x)<=abs(y)) ans=solve1(x,y);
     else ans=solve2(x,y);
     cout << ans << endl;
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
