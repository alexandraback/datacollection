// Problem 1
#include<stdio.h>
typedef long long unsigned int LLU;
typedef long long int LL;
void solve();
int main(void)
{
    int T,t;
/*    freopen("sample_input.txt","r",stdin);
    freopen("sample_output.txt","w",stdout);
*/
    freopen("s_input.in","r",stdin);
    freopen("s_output.txt","w",stdout);
/*    freopen("b_input.in","r",stdin);
    freopen("b_output.txt","w",stdout);
*/
    scanf("%d",&T);
    for(t=1;t<=T;t++)
     {
       printf("Case #%d: ",t);
       solve();
       printf("\n");
     }
    return 0;
}
void solve()
{
  int N,S[201],i,j;
  long tot=0;
  double ans=0.0,t;
  scanf("%d",&N);
  for(i=0;i<N;i++)
   {
    scanf("%d",&S[i]);
    tot+=S[i];
   }
    t=(tot/(double)N)*2;
   for(i=0;i<N;i++)
   {
    ans=(t-S[i])/(double)tot;
    printf("%f ",ans*100.00);
   }
}
