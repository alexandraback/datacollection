#include <iostream>
#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(long long i=a;i<=b;i++)
#define fox(i,a,b) for(long long i=a;i>=b;i--)
using namespace std;
int t,xx,yy,n;
double ans;
int a[100][100];
void dfs(int x,double y){
   int w,tw;
   if (x>n) {
        if (a[50+xx][yy]) ans+=y;
        return;
   }
   if (x==1){
        a[50][0]=1;
        dfs(x+1,y);
        a[50][0]=1;
        return;
   }
   fox(i,40,0) if (a[50][i]){
        w=i+2;break;
   }
   if (a[49][w-1]){
        if (a[51][w-1]){
            a[50][w]=1;dfs(x+1,y);a[50][w]=0;
        }else {
            tw=w+1;
            fo(i,1,w){
                if (a[50+i][w-i]){
                    tw=i;break;
                }
            }
            a[50+tw-1][w-tw+1]=1;
            dfs(x+1,y);
            a[50+tw-1][w-tw+1]=0;
        }
   }else {
        if (a[51][w-1]){
            tw=w+1;
            fo(i,1,w){
                if (a[50-i][w-i]){
                    tw=i;break;
                }
            }
            a[50-tw+1][w-tw+1]=1;
            dfs(x+1,y);
            a[50-tw+1][w-tw+1]=0;
        }else {
            tw=w+1;
            fo(i,1,w){
                if (a[50-i][w-i]){
                    tw=i;break;
                }
            }
            a[50-tw+1][w-tw+1]=1;
            dfs(x+1,y*0.5);
            a[50-tw+1][w-tw+1]=0;

            tw=w+1;
            fo(i,1,w){
                if (a[50+i][w-i]){
                    tw=i;break;
                }
            }
            a[50+tw-1][w-tw+1]=1;
            dfs(x+1,y*0.5);
            a[50+tw-1][w-tw+1]=0;
        }
   }
}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d\n",&t);
    fo(tt,1,t) {
        printf("Case #%d: ",tt);
        scanf("%d %d %d",&n,&xx,&yy);
        memset(a,0,sizeof(a));
        ans=0;
        if ((abs(xx)>50)||(yy>50)) printf("0.0\n");
        else {
        dfs(1,1);
        
        printf("%.7f\n",ans);}
    }
}
