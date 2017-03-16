#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

int pw[7]={1,10,100,1000,10000,100000,1000000};
int n,m;
int st[11],num;

int ck(int x)
{
    int i,j,k=x,l=0,p,ans=0;
    while(x>0){
        l++;x/=10;
    }
    p=x=k;num=0;
    for(i=1;i<l;i++)
    {
        k=p%10;
        p=p/10+k*pw[l-1];
        if(p>x&&p<=m){
            ans++;
            st[++num]=p;
        }
    }
    sort(st+1,st+num+1);
    for(i=2;i<=num;i++)if(st[i]==st[i-1])ans--;
    return ans;
}

int main()
{
    //freopen("C-large.in","r",stdin);
    //freopen("3.out","w",stdout);
    int te,i,j,k;
    scanf("%d",&te);
    for(int pp=1;pp<=te;pp++)
    {
        scanf("%d%d",&n,&m);
        int ans=0;
        for(i=n;i<=m;i++)
        {
            ans+=ck(i);
        }
        printf("Case #%d: %d\n",pp,ans);
    }
    //system("pause");
}
