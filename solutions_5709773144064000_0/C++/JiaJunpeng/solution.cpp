#include <vector> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <string.h> 
using namespace std;
int mat[2],rr[2],now,cnt;
double c,f,x,now_t,now_x,ans;
int main()
{
    freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    int i,j,s,p,q,t,tst=0;
    scanf("%d",&t);
    while(t--)
    {
       tst++;
       scanf("%lf%lf%lf",&c,&f,&x);
       ans=1000000000;
       for(i=0;i<=100000;i++)
       {
         if(i==0)
           now_t=x/2.0;
         else
         {
             now_t-=x/(2.0+(double)(i-1)*f);
             now_t+=c/(2.0+(double)(i-1)*f);
             now_t+=x/(2.0+(double)i*f);
         }
         if(ans>now_t)
             ans=now_t;
       }
       printf("Case #%d: %.20f\n",tst,ans);
    }
    return 0;
}
