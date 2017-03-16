#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
int arr[500];
int val[500];
int n;
bool found;
void recu(int level);
void check();
int main(){
  int tests;
  scanf("%d",&tests);
  for(int t=1;t<=tests;t++){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    found=false;
    recu(0);
    printf("Case #%d:",t);
    if(found){
      printf("\n");
      for(int i=0;i<n;i++) if(val[i]==0) printf("%d ",arr[i]);
      printf("\n");
      for(int i=0;i<n;i++) if(val[i]==1) printf("%d ",arr[i]);
    }else{
      printf(" Impossible");
    }
    printf("\n");
  }
  return 0;
}



void check(){
  LL sum1=0;
  LL sum2=0;
  for(int i=0;i<n;i++){
    if(val[i]==0) sum1+=arr[i];
    if(val[i]==1) sum2+=arr[i];
  }
  if(sum1==sum2 && sum1!=0){
    found=true;
  }
}
void recu(int level){
  if(level==n){
    check();
    return;
  }
  for(int i=0;i<3;i++){
    val[level]=i;
    recu(level+1);
    if(found) return;
  }
}
