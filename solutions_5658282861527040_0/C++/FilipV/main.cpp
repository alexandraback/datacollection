#include <cstdio>

using namespace std;

int main()
{
 freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
   int t,no=1;
   scanf("%d",&t);
   while(t--)
   {
   int a,b,k;
   scanf("%d%d%d",&a,&b,&k);
   int cnt=0;
   for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
   {
       if((i&j)<k)cnt++;
   }
   printf("Case #%d: %d\n",no++,cnt);
   }

      return 0;
}
