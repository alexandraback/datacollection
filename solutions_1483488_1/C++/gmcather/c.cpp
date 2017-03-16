#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define maxN 2001000
bool vis[maxN];
int a,b;

int getlen(int m){
    int t=0;
    while(m){
        t++;
        m/=10;
    }
    return t;
}

int solve(int m){
    int n=0,t;
    int len=getlen(m);
    int i,j;
    int fact=1;
    vis[m]=1;
    n++;
    for(i=1;i<len;i++)  fact*=10;
    for(i=1;i<len;i++){
        t=(m%10)*fact+m/10;
        if(getlen(t)==len && a<=t && t<=b && !vis[t]){
              n++;
              vis[t]=1;
        }
        m=t;
    }
    if(n>1)   return (n-1)*n/2;
    else return 0;
}

int main(){
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\test.txt","r",stdin);
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\ans.txt","w",stdout);
    int i,j,cs,n=0;
    int sum;
    cin>>cs;
    while(cs--){
        n++;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&a,&b);
        sum=0;
        for(i=a;i<=b;i++){
            if(!vis[i]){
                sum+=solve(i);
            }
        }
        printf("Case #%d: %d\n",n,sum);
    }
    return 0;
}
