#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

float arr1[1002];
float arr2[1002];

int main(){
   int TC;
   scanf("%d",&TC);
   for(int T=1;T<=TC;T++){
      int N;
      scanf("%d",&N);
      for(int i=0;i<N;i++){
         scanf("%f",&arr1[i]);
      }
      for(int i=0;i<N;i++){
         scanf("%f",&arr2[i]);
      }
      sort(arr1,arr1+N);
      sort(arr2,arr2+N);
      int i=N-1,j=N-1;
      int ans1=0;      
      while(i>=0){
         if(arr2[j]>=arr1[i]){
            ans1++;
            i--;
            j--;
         }else
            i--;
      }
      int ans2=0; 
      i=N-1;j=N-1;      
      while(j>=0){
         if(arr1[i]>arr2[j]){
            ans2++;
            i--;
            j--;
         }else
            j--;
      }
      printf("Case #%d: %d %d\n",T,ans2,N-ans1);
   }
   return 0;
}