#include<stdio.h>
#include<math.h>
      int ip(long long x) {
  if (x < 0) return 0;
  long long div = 1;
  while (x / div >= 10) {
    div *= 10ll;
  }        
  while (x != 0) {
    long long l = x / div;
    long long r =  x % 10ll;
    if (l != r) return 0ll;
    x = (x % div) / 10ll;
    div /= 100ll;
  }
  return 1;
}
int main()
{
  // freopen("1.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int t,i,j=0,k=1;
    long long a1[]={ 1, 2,3, 11, 22, 101,111, 121, 202, 212, 1001, 1111,2002, 10001, 10101, 10201,11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002}; 
    for(i=0;i<39;i++)a1[i]*=a1[i];scanf("%d",&t);
    while(k<=t)
    {    long long a,b;
               int c=0;scanf("%I64d%I64d",&a,&b);
              for(i=0;i<39;i++){if(a1[i]>=a&&a1[i]<=b){c+=1;}}
              printf("Case #%d: %d\n",k,c);
                  k++;  }
     return 0;
    }
