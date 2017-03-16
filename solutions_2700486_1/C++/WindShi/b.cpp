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

int n,T,x,y;
double f[2001][2001];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    forup(uu,1,T)
    {
        scanf("%d%d%d",&n,&x,&y);
        printf("Case #%d: ",uu);
        int step=(abs(x)+abs(y))/2+1,use=2*step*(step*2-1)/2;
        if (use<=n) printf("%.10lf\n",1.0);
        else if (n<=2*(step-1)*(step*2-3)/2) printf("%.10lf\n",0.0);
        else
        {
             memset(f,0,sizeof(f));
             f[0][0]=1.0;
             int hehe=n-2*(step-1)*(step*2-3)/2,haha=step*2-2;
             forup(i,0,min(haha,hehe))
                forup(j,0,min(haha,hehe-i-1)) 
                  if (j<haha && i<haha) 
                    f[i+1][j]+=f[i][j]*1.0/2.0,f[i][j+1]+=f[i][j]*1.0/2.0;
                  else if (j<haha && i==haha) f[i][j+1]+=f[i][j];
                  else if (j==haha && i<haha) f[i+1][j]+=f[i][j];
             double ans=0;
             forup(i,y+1,min(hehe,haha)) ans+=f[i][hehe-i]; 
             printf("%.10lf\n",ans);
        }
    }
}
    
