#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#define eps 1e-9
#define inf 0x7fffffff
#define N 1005
using namespace std;
bool ma[N][N];
bool mb[N];
int n,ni;
void dfs(int s,int t){
     for (int i=1;i<=n;i++)
     if (ma[s][i])
     {
         if (i==t){ni++;continue;}
         if (!mb[i]){
              mb[i]=1;
              dfs(i,t);
              }
          }
     return ;
     }
int main()
{
    int i,j,m,T,t;
    freopen ("3.in","r",stdin);
    freopen ("3.out","w",stdout);
    cin>>T;
    for (int l=1;l<=T;l++){
        cin>>n;
        memset (ma,0,sizeof (ma));
        for (j=1;j<=n;j++){
            cin>>m;
            for (i=0;i<m;i++){
                cin>>t;
                ma[j][t]=1;
                }
            mb[1]=1;
            }
        bool fa=0;
        for (i=1;i<=n;i++){
        for (j=1;j<=n;j++)
        if (i!=j){
        memset (mb,0,sizeof (mb));
        ni=0;
        dfs(i,j);
        if (ni>1){fa=1;break;}
        }
        if (fa==1)break;
        }
        printf ("Case #%d: %s\n",l,fa?"Yes":"No");
        }
    return 0;
}
