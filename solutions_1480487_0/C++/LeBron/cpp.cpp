#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int N=45;  
//__int64 MAX=(1ull<<63);  
int t,c,n,k;  
__int64 a[N],ans;  
__int64 sum[N];  
void dfs(int t,int d,__int64 num)  
{  
   if(ans>num)ans=num;  
   if(d==k||t==n+1)  
       return;  
   __int64 s=num;  
   s &= sum[t];  
   if(s>=ans)return;  
    dfs(t+1,d+1,num&a[t]);  
   dfs(t+1,d,num);  
      
}  
int main()  
{  
 freopen("C:/input.txt","r",stdin);
 freopen("C:/output.txt","w",stdout);
   cin>>t;  
   c=0;  
   while(t--)  
   {  
      printf("Case #%d: ",++c);  
      scanf("%d%d",&n,&k);  
      for(int i=1;i<=n;i++)  
         scanf("%I64d",&a[i]);  
      sort(a+1,a+n+1);  
    //  sum[n] = a[n];  
     // for(int i = n-1;i >= 1;i--)  
   //     sum[i] = a[i] & sum[i+1];  
      ans=1;
      for (int i=1;i<=60;i++)
      ans*=2;
      ans*=2;--ans;
      dfs(1,0,ans);  
      printf("%I64d\n",ans);  
   }  
   return 0;  
}  
