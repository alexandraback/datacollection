#include <stdio.h>
#include <string.h>
int map[101][101];
int n,m;
int rmax[101],cmax[101];
int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(rmax,0,sizeof rmax);
        memset(cmax,0,sizeof cmax);
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;++i)
         for (int j=0;j<m;++j)
         {
             scanf("%d",&map[i][j]);
             int t=map[i][j];
             if (t>rmax[i]) rmax[i]=t;
             if (t>cmax[j]) cmax[j]=t;
         }
        bool fla=true;
       for (int i=0;i<n && fla;++i)
        for (int j=0;j<m && fla;++j)
         {
             if (map[i][j]!=rmax[i] && map[i][j]!=cmax[j]) fla=false;
         }
      printf("Case #%d: ",++cas);
      if (fla) printf("YES\n"); else printf("NO\n");

    }
}
