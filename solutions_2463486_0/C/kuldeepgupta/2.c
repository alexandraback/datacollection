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
   //freopen("1.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int t,i,j=0,k=1;
    long long a1[]={1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll, 104060401ll, 121242121ll, 123454321ll, 125686521ll, 400080004ll, 404090404ll, 10000200001ll, 10221412201ll,12102420121ll, 12345654321ll, 40000800004ll}; 
    scanf("%d",&t);
    while(k<=t)
    {    long long a,b;
               int c=0;scanf("%I64d%I64d",&a,&b);
              for(i=0;i<26;i++)if(a1[i]>=a&&a1[i]<=b){c+=1;}
              printf("Case #%d: %d\n",k,c);
                  k++;  }
     return 0;
    }
