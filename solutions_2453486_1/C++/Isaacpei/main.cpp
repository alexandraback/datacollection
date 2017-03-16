#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>


using namespace std;

const int INF=0x3f3f3f3f;
typedef long long ll;
const int M=1005;
const int mod=1e9+7;
const double eps=1e-6;
const double Pi=2*acos(0.0);

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int bit(int x){return 1<<x;}
inline double dabs(double x){return x>0?x:(-x);}
inline int abs(int x){return x>0?x:(-x);}
inline int lowbit(int x){return x&(-x);}

char ma[5][5];
int T,cas=1;

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   for(scanf("%d",&T);cas<=T;cas++){
      int jud=0;
      for(int i=0;i<4;i++){
         scanf("%s",ma[i]);
      }
      printf("Case #%d: ",cas);
      for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
            if(ma[i][j]=='.') jud=3;
         }
      }
      for(int i=0;i<4;i++){
         int o=0,x=0,t=0;
         for(int j=0;j<4;j++){
            if(ma[i][j]=='O') o++;
            else if(ma[i][j]=='X') x++;
            else if(ma[i][j]=='T') t++;
         }
         if(o==4||(o==3&&t==1)) jud=2;
         if(x==4||(x==3&&t==1)) jud=1;
      }
      if(jud==0||jud==3){
         for(int i=0;i<4;i++){
            int o=0,x=0,t=0;
            for(int j=0;j<4;j++){
               if(ma[j][i]=='O') o++;
               else if(ma[j][i]=='X') x++;
               else if(ma[j][i]=='T') t++;
            }
            if(o==4||(o==3&&t==1)) jud=2;
            if(x==4||(x==3&&t==1)) jud=1;
         }
      }
      if(jud==0||jud==3){
         int o=0,x=0,t=0;
         for(int i=0;i<4;i++){
            if(ma[i][i]=='O') o++;
            else if(ma[i][i]=='X') x++;
            else if(ma[i][i]=='T') t++;
         }
         if(o==4||(o==3&&t==1)) jud=2;
         if(x==4||(x==3&&t==1)) jud=1;
      }
      if(jud==0||jud==3){
         int o=0,x=0,t=0;
         for(int i=0;i<4;i++){
            if(ma[i][3-i]=='O') o++;
            else if(ma[i][3-i]=='X') x++;
            else if(ma[i][3-i]=='T') t++;
         }
         if(o==4||(o==3&&t==1)) jud=2;
         if(x==4||(x==3&&t==1)) jud=1;
      }
      if(jud==0) puts("Draw");
      else if(jud==1) puts("X won");
      else if(jud==2) puts("O won");
      else puts("Game has not completed");
   }
   return 0;
}
