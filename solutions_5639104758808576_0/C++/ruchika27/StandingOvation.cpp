#include<bits/stdc++.h>
using namespace std;
int main(){
  int T,N;char a[1001];
  scanf("%d",&T);
  for(int t=1;t<=T;t++){
    int count=0,count1=0;
    scanf("%d",&N);
    scanf("%s",a);
    count+=a[0]-'0';
    for(int i=1;i<=N;i++){
      if(a[i]>'0' && count<i){
	count1+=(i-count);
        count+=i-count;
	count+=a[i]-'0';

      }
      else
	count+=a[i]-'0';
    }
    printf("Case #%d: %d\n",t,count1);
  }
  return 0;
}
