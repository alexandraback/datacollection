// Problem 3
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
   long int N,ans1[20],ans2[20],i,j,k,A[20],ans1_i,ans2_i;
   LLU n,sum1,sum2;
   scanf("%ld",&N);
   for(i=0;i<N;i++)
    scanf("%ld",&A[i]);
   n=1<<N;
   for(i=1;i<n;i++)
      {
        sum1=0;
        memset(ans1,0,sizeof ans1);
        ans1_i=0;
        for(j=0;j<N;j++)
        {
         if((i & (1<<j))>0)
            {
             sum1+=A[j];
             ans1[ans1_i++]=A[j];
            }
        } 
         for(k=i+1;k<n;k++)
         {
          sum2=0;
          memset(ans2,0,sizeof ans2);
          ans2_i=0;
          for(j=0;j<N;j++)
          {
           if((k & (1<<j))>0)
            {
             sum2+=A[j];
             ans2[ans2_i++]=A[j];
            }
          }
          if(sum1==sum2)
          {
           printf("\n");
           for(i=0;i<ans1_i;i++)
            printf("%d ",ans1[i]);
           printf("\n");
           for(i=0;i<ans2_i;i++)
            printf("%d ",ans2[i]);            
           return;
          } 
         }
      }
     printf("\nImpossible");  
}
