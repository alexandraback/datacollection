#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  freopen("B-small-attempt0(2).in","r",stdin);
  freopen("output.txt","w",stdout);
  //
  int T, K, L, S;
  char k[10], l[10];
  //
  cin>>T;
  //cout<<T<<endl;
  for(int t = 1; t <= T; t++){
    scanf("%d%d%d\n",&K,&L,&S);
    for(int i = 0; i < K; i++)scanf("%c",&k[i]);scanf("\n");
    //cout<<k<<endl;
    for(int i = 0; i < L; i++)scanf("%c",&l[i]);
    //cout<<l<<endl;
    //
      int limit = 1;
      int bmax = 0;
      int sum = 0;
      for(int i = 0; i < S; i++)limit*=K;
      for(int i = 0; i < limit; i++){
        int tmp = i;
        char t[10];
        for(int j = 0; j < S; j++)t[j] = k[tmp%K], tmp/=K;
        //if(S<5)cout<<t<<endl;
        int cnt = 0;
        for(int j = 0; j < S; j++){
          if(j+L>S)break;
          for(int ll = 0; ll <= L; ll++){
            if(ll==L)cnt++;
              else
                if(t[j+ll]!=l[ll])break;
          }
        }
        if(cnt > bmax)bmax = cnt;
        sum += cnt;
      }
      //cout<<bmax<<" "<<sum<<endl;
      double result = (1.0)*bmax - (1.0)*sum/limit;
    //
    printf("Case #%d: %0.6lf\n",t,result);
  }
  return 0;
}
