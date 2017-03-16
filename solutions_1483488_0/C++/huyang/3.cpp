#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

bool h[1111111];
int pw[7]={1,10,100,1000,10000,100000,1000000};

bool check(int x,int y)
{
  //  printf("%d %d\n",x,y);
    int i,j,k;
    k=x;
    j=0;
    while(k>0){
        j++;
        k/=10;
    }
    for(i=1;i<j;i++)
    {
        k=x%10;
        x=x/10+k*pw[j-1];
    //    printf("%d %d\n",x,y);
        if(x==y)return true;
    }
    return false;
}

int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("3.out","w",stdout);
    int te,i,j,k;
    h[10]=h[100]=h[1000]=h[10000]=h[100000]=h[1000000]=true;
    scanf("%d",&te);
    for(int pp=1;pp<=te;pp++)
    {
        int ans=0,n,m;
        scanf("%d%d",&n,&m);
        for(i=n;i<=m;i++)
        for(j=i+1;j<=m;j++)
        if(!h[j])
        {
            if(check(i,j))ans++;
        }
        printf("Case #%d: %d\n",pp,ans);
    }
}
