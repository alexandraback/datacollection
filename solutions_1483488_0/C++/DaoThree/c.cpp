#include <iostream>
#include <math.h>
using namespace std;
bool flag[20000010];

bool check(int p)
{
     bool u[20];
     memset(u,true,sizeof(u));
     while (p != 0)
     {
           int j = p % 10;
           p = p / 10;
           if (!u[j])
              return false;
           u[j] = false;
     }
     return true;
}

int change(int i,int uu)
{
            int qq = log(uu)/log(10);
            int pp = 1;
            for (int ii = 0 ;ii < qq ;ii++)
                pp = pp * 10;
            int p = (i % 10) * pp + i / 10;
            //printf("%d %d\n",uu,p);
            return p;

}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int n,a,b,t;
    scanf("%d",&t);
    for (int tt = 1 ; tt <= t ;tt++)
    {
        memset(flag,true,sizeof(flag));
        scanf("%d%d",&a,&b);
        int ans = 0;
        for (int i = max(a,10) ; i <= b ;i++)
        {
            //if (!check(i)) continue;
            if (!flag[i]) continue;
            flag[i] =false;
            int s = 1;
            int p = change(i,i);
//            printf("%d %d\n",i,p);
            while (flag[p])
            {
                  flag[p] = false;
                  if (p >=a && p <= b)
                  {
//                   printf("%d\n",p);
                   s++;
                  }
                  
                   p = change(p,i);
            }
            ans += (s-1)*s /2;
  
        }
        printf("Case #%d: %d\n",tt,ans);
    }
}
