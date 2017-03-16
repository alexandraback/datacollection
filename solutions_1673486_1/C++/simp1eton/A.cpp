#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100005
using namespace std;

typedef double Lf;
int A,B,testcase;
Lf P[MAXN],S[MAXN],X[MAXN],ans,tmp;

int main(){
  freopen("A-large.in","r",stdin);
  freopen("ans.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d%d",&A,&B);
    S[0] = P[0] = 1.0;
    for(int i=1;i<=A;++i){
      scanf("%lf",&P[i]);
      S[i] = P[i] * S[i-1];
    //  printf("%lf * %lf = %lf\n",S[i-1],P[i],S[i-1]*P[i]);
    }
    X[A] = P[A];
    for(int i=A-1;i>0;--i) X[i] = X[i+1] * P[i];
    //for(int i=1;i<=A;++i) printf("%lf: %lf\n",P[i], S[i]);
    ans = 10.0*(Lf)(B);
    for(int i=0;i<=A;++i){
      tmp = (Lf)(A-i) + S[i] * ((Lf)(B-i+1)) + (1.0-S[i]) * ((Lf)(B-i+1+B+1));
   //   printf("%d + %lf * %d + %lf * %d = %lf\n",A-i,S[i],B-A+1,1.0-S[i],B-A+1+B+1);
   //   printf("dp[%d] = %lf\n",i,tmp);
      ans = min(ans,tmp);
    }
    ans = min(ans,(Lf)(B+2));
    printf("Case #%d: %lf\n",TC,ans);
  }
 // system("pause");
}
