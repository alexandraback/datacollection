#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define zero(x) (fabs(x)<eps)
#define pi acos(-1.0)
#define f1 first
#define f2 second
#define ms(x,y) memset(x,y,sizeof(x))
#define fr(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
int a,b,c,d,o;
int p[3],x[3];
int ans[1005][3];
int ij[11][11],ik[11][11],jk[11][11];
void doit()
{
   scanf("%d%d%d%d",&a,&b,&c,&d);
   fr(i,1,3) p[i]=i;
   x[1]=a;
   x[2]=b;
   x[3]=c;
   if (x[1]>x[2]) {swap(x[1],x[2]);swap(p[1],p[2]);}
   if (x[1]>x[3]) {swap(x[1],x[3]);swap(p[1],p[3]);}
   if (x[2]>x[3]) {swap(x[2],x[3]);swap(p[2],p[3]);}
ms(ij,0);
ms(ik,0);
ms(jk,0);
o=0;
//printf("%d\n",x[1]);
if (x[1]>1)
{
   fr(i,1,x[1])
   fr(j,1,x[2])
   fr(k,1,x[3])
   {
       if (ij[i][j]<d&&ik[i][k]<d&&jk[j][k]<d);else continue;
       ij[i][j]++;
       ik[i][k]++;
       jk[j][k]++;
       ans[o][0]=i;
       ans[o][1]=j;
       ans[o][2]=k;
       o++;
   }
}
else{
    int i=1;
    int tmp=1,tim,k;
    fr(j,1,x[2])
    {   tim=0;
        while (tim<x[3])
        {
            tim++;

            k=tmp;
            //printf("~~~%d %d\n",j,k);
            if (ij[i][j]<d&&ik[i][k]<d&&jk[j][k]<d){
       ij[i][j]++;
       ik[i][k]++;
       jk[j][k]++;
       ans[o][0]=i;
       ans[o][1]=j;
       ans[o][2]=k;
         tmp=tmp%x[3]+1;
       o++;
            }
        }
    }

}

   printf("%d\n",o);
   fr(i,0,o-1)
   {
       fr(j,1,3) if (p[j]==1) printf("%d",ans[i][j-1]);
       fr(j,1,3) if (p[j]==2) printf(" %d",ans[i][j-1]);
       fr(j,1,3) if (p[j]==3) printf(" %d\n",ans[i][j-1]);
   }
}

int main()
{
    freopen("cc2.in","r",stdin);
    freopen("cc2.txt","w",stdout);
    int cas,i=0;
    scanf("%d",&cas);
    while (cas--)
    {   printf("Case #%d: ",++i);
        doit();
    }
}
