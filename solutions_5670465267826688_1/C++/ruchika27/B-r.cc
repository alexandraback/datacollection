#include<bits/stdc++.h>
using namespace std;
int main(){
  int T,D,P;
  
  scanf("%d",&T);
  for(int t=1;t<=T;t++){
    int count=0;
    int a[1001]={0};
    int max1=INT_MIN;
    scanf("%d",&D);
    for(int i=0;i<D;i++){
      scanf("%d",&P);
	a[P]++;
      max1=max(max1,P);
      
    }
    for(int i=max1;i>=0;i--){
      if(a[i]>=i){
	count+=i;
	break;
      }
      else{
	count+=a[i];
	if(i%2==0)
	  a[i/2]+=a[i]*2;
	
	else{
	  a[i/2]+=a[i];
	  a[i/2+1]+=a[i];
	}
      }
    }
    printf("Case #%d: %d\n",t,count);
  }
  return 0;
}
