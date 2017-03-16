#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#define forup(i,a,b) for (int i=a;i<=b;i++)
#define fordown(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int T,l,f[4001][5],len[521296]; 
char s1[10001],s2[521296][11];

int main(){
    freopen("dict.txt","r",stdin);
    forup(i,1,521196) scanf("%s",s2[i]),len[i]=strlen(s2[i]);
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    forup(uu,1,T)
    {
         scanf("%s",s1);
         int n=strlen(s1);
         memset(f,127,sizeof(f));
         f[0][0]=0;
         forup(i,0,n)
             forup(j,0,4)
                 if (f[i][j]<1<<30)
                 {
                     forup(k,1,521196)
                          if (i+len[k]>n) continue;
                          else
                          {
                              bool ok=true;
                              int now=j+1,value=f[i][j];
                              forup(l,0,len[k]-1)
                              {
                                  if (now) --now;
                                  if (s2[k][l]!=s1[l+i]) 
                                    if (!now) now=5,value++;
                                    else
                                    {
                                        ok=false;
                                        break;
                                    }
                              }
                              if (ok) f[i+len[k]][max(now-1,0)]=min(f[i+len[k]][max(now-1,0)],value);
                          }
                     }
         int ans=1<<30;
         forup(j,0,4) ans=min(ans,f[n][j]);
         printf("Case #%d: %d\n",uu,ans);
    }                          
}
