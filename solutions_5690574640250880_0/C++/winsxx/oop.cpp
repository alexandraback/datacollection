#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
 
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define PI 3.14159265359
#define eps 0.000001
#define mINF -2000000000

#define LL long long

int main(){
   int TC;
   scanf("%d",&TC);
   for(int T=1;T<=TC;T++){
      int R,C,M,harusdapat,x,y;
      bool bisa=true;
      bool arr[55][55];
      memset(arr,0,50*50*sizeof(bool));
      scanf("%d %d %d",&R,&C,&M);
      harusdapat=R*C-M;
      x=0;y=0;
      if(harusdapat==0) bisa=false;
      if(bisa && harusdapat) {
         arr[0][0]=true;
         harusdapat-=1;
      }
      if((R==1||C==1)&&harusdapat){
         if(R>1){
            for(int i=1;i<harusdapat+1;i++){
               arr[i][0]=true;
            }
            harusdapat=0;
         }else{
            for(int i=1;i<harusdapat+1;i++){
               arr[0][i]=true;
            }
            harusdapat=0;
         }   
      }
      if(bisa && harusdapat){
         for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
               if(i<R && j<C && arr[i][j]==false){
                  arr[i][j]=true;
                  harusdapat--;
               }
         if (harusdapat<0) bisa=false;
      }
      if(bisa){
         if(R>1 && C>1)
         for(int i=2;i<max(R,C);i++){
            if(harusdapat>1 && i<R){
               arr[i][0]=true;
               arr[i][1]=true;
               harusdapat-=2;
            }
            if(harusdapat>1 && i<C){
               arr[0][i]=true;
               arr[1][i]=true;
               harusdapat-=2;
            }
         }
         for(int i=2;i<R;i++)
            for(int j=2;j<C;j++){
               if(arr[i-1][j]==false||arr[i][j-1]==false)
                  break;
               if(harusdapat){
                  arr[i][j]=true;
                  harusdapat--;
               }
            }
      }
      if(harusdapat!=0) bisa=false;
      printf("Case #%d:\n",T);
      if(bisa){
         for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
               if(i==y && j==x)
                  printf("C");
               else if(arr[i][j])
                  printf(".");
               else printf("*");
            printf("\n");
         }
      }
      else
         printf("Impossible\n");
   }
   return 0;
}