#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007

int casen;

int sou[2][8]={{1,1,1,0,0,-1,-1,-1},{1,0,-1,1,-1,1,0,-1}};
pair<int ,int > a[1000000];
int gg[66][66];
bool tell[66][66];
int r,c,x;
int ff[66];
int main(){
    freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
	scanf("%d",&casen);
    for (int casei=1;casei<=casen;casei++){
       for (int i=0;i<66;i++) for (int j=0;j<66;j++){ gg[i][j]=-1;tell[i][j]=0;}
       printf("Case #%d:",casei);printf("\n");
       int cnt=1;
       int s=0;
      // a[0]=mk(1,1);
       scanf("%d%d%d",&r,&c,&x);
       int tmpx=0,tmpy=0,ans1=0,ans0=0;
       if (r*c-x<0){
            printf("Impossible\n");continue;
       }else{
           int tt=r*c-x;
           if (c==1){
               for (int i=1;i<=tt;i++) gg[i][1]=0;
               gg[1][1]=1;
           }else if (r==1){
               for (int i=1;i<=tt;i++) gg[1][i]=0;gg[1][1]=1;
           }else if (tt==1){
               gg[1][1]=1;

               }else{
                memset(ff,0,sizeof(ff));
                if (tt>c*2){
                    ff[1]=c;ff[2]=c;tt-=2*c;
                }else{
                    ff[1]=tt/2;ff[2]=tt/2;tt-=(tt/2*2);
                }
                int ttt=ff[1];cnt=3;
                while (tt>0&&cnt<=r){
                   // printf("tt=%d\n",tt);
                    ff[cnt]=min(ttt,tt);
                    tt-=ff[cnt];
                    ttt=ff[cnt];cnt++;
                    if (cnt>r) break;
                }
                if (tt>0){
                     printf("Impossible\n");continue;
                }else{
                    // printf("%dlllll %d\n",ff[cnt-1],cnt);
                    if (ff[cnt-1]==1){
                        bool tell=true;
                        for (int i=cnt-2;i>2;i--){
                            if (ff[i]>2){  tell=false;ff[i]-=1;ff[cnt-1]=2;break;
                            }else{
                            }
                        }
                        if (tell){
                           // printf("%dlllll",ff[1]);
                            if (ff[1]>=4){
                                ff[1]--;ff[2]--;
                            }else{ printf("Impossible\n");continue;
                            }
                            ff[cnt-1]+=2;
                        }
                    }
                    for (int i=1;i<cnt;i++)
                    for (int j=1;j<=ff[i];j++) gg[i][j]=0;gg[1][1]=1;

                }

           }
            for (int i=1;i<=r;i++){ for (int j=1;j<=c;j++) if (gg[i][j]==0) printf("."); else if (gg[i][j]==1) printf("c"); else printf("*");printf("\n");}
       }
    }
}
