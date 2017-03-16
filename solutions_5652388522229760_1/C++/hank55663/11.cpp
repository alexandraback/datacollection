#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
      int n;
      scanf("%d",&n);
      if(n==0){
        printf("Case #%d: INSOMNIA\n",T);
        continue;
      }
      int a=n;
      int sum=0;
      int di[10];
      memset(di,0,sizeof(di));
      for(;sum!=10;a+=n){
        int b=a;
        while(b){
            if(di[b%10]==0)
            sum++;
            di[b%10]=1;
            b/=10;
        }
      }
      printf("Case #%d: %d\n",T,a-n);
    }
}
