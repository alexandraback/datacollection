#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int n,a[1001],v[1001],posa[1001],posv[1001];
bool ab[1001],av[1001];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for (int uu=1;uu<=test;uu++)
    {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&v[i]),posa[i]=i,posv[i]=i;
    for (int i=1;i<=n;i++)
       for (int j=i+1;j<=n;j++)
       {
          if (a[posa[j]]<a[posa[i]] || (a[posa[j]]==a[posa[i]] && v[posa[j]]>v[posa[i]]) )
          {
             int k=posa[i];posa[i]=posa[j];posa[j]=k;
          }
          if (v[posv[j]]<v[posv[i]] || (v[posv[j]]==v[posv[i]] && a[posv[j]]<a[posv[i]]) )
          {
             int k=posv[i];posv[i]=posv[j];posv[j]=k;
          }
       }
    memset(ab,false,sizeof(ab));
    memset(av,false,sizeof(av));
    int cnt=0,zhi=0;
    int lefta=1,leftv=1;
    //for (int i=1;i<=n;i++) printf("%d %d\n",posa[i],posv[i]);
    printf("Case #%d: ",uu);
    bool ok=false;
    for (int i=1;i<=100000;i++)
    {
        bool go=false;
        for (int j=1;j<=n;j++)
           if (!av[posv[j]] && !ab[posv[j]] && v[posv[j]]<=cnt)
           {
               cnt+=2;
               av[posv[j]]=true;
               go=true;
               ++zhi;
               break;
           }
           else if (v[posv[j]]>cnt) break;
        if (zhi==n)
        {
           ok=true;
           printf("%d\n",i);
           break;
        }
        if (go) continue;
        for (int j=1;j<=n;j++)
           if (!av[posv[j]] && ab[posv[j]] && v[posv[j]]<=cnt)
           {
               cnt++;
               ++zhi;
               av[posv[j]]=true;
               go=true;
               break;
           }
           else if (v[posv[j]]>cnt) break;
        if (zhi==n)
        {
           ok=true;
           printf("%d\n",i);
           break;
        }
        if (go) continue;
        int max=0,pos=0;
        for (int j=1;j<=n;j++)
           if (!ab[posa[j]] && !av[posa[j]] && a[posa[j]]<=cnt)
           {
              if (v[posa[j]]>max) max=v[posa[j]],pos=posa[j];
              go=true;
           }
        if (go) 
        {
           ab[pos]=true;
           ++cnt;
           continue;
        }
        break;
    }
    if (!ok)
    printf("Too Bad\n");
    }
}
