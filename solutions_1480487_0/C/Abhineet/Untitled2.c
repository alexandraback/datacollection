#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int k=1;
    while(k<=t){
       int n;
       scanf("%d",&n);
       int arr[n];
       int sum=0,i;
       for(i=0;i<n;i++){
          scanf("%d",&arr[i]);
          sum+=arr[i];
       }
       double avg = (2.00* sum)/(1.00*n);
       double out[n];
       int flag=n;
       double sum2=0.0;
       for(i=0;i<n;i++){
          double req = avg - arr[i];
          out[i] = (req*100.00)/(1.00*sum);
          if(out[i]<0){
             out[i]=0;
             flag--;
          }
          sum2+=out[i];
       }
       int j;
       printf("Case #%d:",k);
         double sub = (sum2-100.00)/flag;
         for(j=0;j<n;j++){
              out[j] -= sub;
              if(out[j]<0)
                 out[j]=0;
         }
          for(i=0;i<n;i++)
             printf(" %f",out[i]); 
       printf("\n");
       k++;
    }
    return 0;
}
