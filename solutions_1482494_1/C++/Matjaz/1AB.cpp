#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int a[1005],b[1005];
int T;

int main(){
    scanf("%d",&T);
    for (int t=1;t<=T;t++){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
        int done[1005][2];
        memset(done,0,sizeof done);
        int st=0;
        int op=0;
        int res=0;
        while (true){
        int z=-1;
        int maxi=0;
        for (int i=0;i<n;i++) {
            if (b[i]<=st&&done[i][1]==0){
               done[i][1]=1; st++;
               if (done[i][0]==0) st++;
               done[i][0]=1;
               op++;
               res++;
               z=4000;
               break;                           
               } else {
               if (a[i]<=st&&done[i][0]==0){
                  if (b[i]>z){
                     z=b[i];
                     maxi=i;           
                     }                        
                  }       
               }
            }
        if (z==4000) continue;
        if (z==-1) break;
        st++;
        res++;
        done[maxi][0]=1;
        }
        if (op!=n) printf("Case #%d: Too Bad\n",t); else printf("Case #%d: %d\n",t,res);
        }
    return 0;
    }
