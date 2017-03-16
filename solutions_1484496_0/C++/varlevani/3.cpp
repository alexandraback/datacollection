#include <stdio.h>
#include <map>
using namespace std;
int t, n;
long long a[1000];
long long jami;
map<long long, int> mp;
int main()
{
freopen("C-small-attempt0.in","r",stdin);
freopen("C-small.out","w",stdout);
scanf("%d",&t);
for(int it=1;it<=t;it++)
   {
   printf("Case #%d:\n",it);
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%I64d",&a[i]);
   int pas1, pas2;
   pas1 = pas2 = -1;
   mp.clear();
   for(int i=0;i<(1<<n);i++)
      {
      jami = 0;
      for(int j=0;j<n;j++)
         if(i&(1<<j))
            jami += a[j];
      if(mp.find(jami) != mp.end())
         {
         pas1 = mp[jami];
         pas2 = i;
         int kk = pas1 & pas2;
         pas1 ^= kk;
         pas2 ^= kk;
         break;
         }
      mp[jami] = i;
      }
   if(pas1 == -1)
      printf("Impossible\n");
   else
      {
      bool ind = 0;
      for(int j=0;j<n;j++)
         if(pas1 & (1<<j))
            {
            if(ind) printf(" ");
            printf("%d",a[j]);
            ind = 1;
            }
      printf("\n");
      ind = 0;
      for(int j=0;j<n;j++)
         if(pas2 & (1<<j))
            {
            if(ind) printf(" ");
            printf("%d",a[j]);
            ind = 1;
            }
      printf("\n");
      }
   }
return 0;
}
