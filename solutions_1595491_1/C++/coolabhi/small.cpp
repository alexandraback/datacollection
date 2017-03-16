#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cctype>
#include<climits>
#define pp pair<int,int>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   long long unsigned int T,S,N,p,a,b,c,i,t;
   scanf("%lld",&T);
   for(i=1;i<=T;i++)
   {
     scanf("%lld%lld%lld",&N,&S,&p);
     c=0;
     while(N--)
     {
       scanf("%lld",&t);
       a=t/3;
       b=t%3;
       if(t==0 && p==1);
       else if(a>=p)
       c++;
       else if(b==0 && (a+1)>=p && S>0){c++;S--;}
       else if((b==1 || b==2)&& (a+1)>=p)c++;
       else if(b==2 && (a+2)>=p && S>0){c++;S--;}
     }
     printf("Case #%lld: %lld\n",i,c);
   }
   return 0;
}
