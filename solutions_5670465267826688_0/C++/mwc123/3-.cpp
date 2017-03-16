#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define MAXN 100000
#define LL long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,m,l,x;
int ma[4][4]={0,1,2,3,
              1,10,3,12,
              2,13,10,1,
              3,2,11,10};
char s[10002];
bool check()
{
    int i,j,k,a,b,c;
    int h[10002];
    int p1=0,p2=0,p3=0;
    int f1,f2,f3;
    n=l*x;
    h[n]=0;f1=1;
    for(i=n-1;i>=0;i--)
    {
        a=s[i%l]-'i'+1;
        h[i]=ma[a][h[i+1]%10];
        if(h[i]/10==1)f1*=-1,h[i]%=10;
        if(f1==-1)h[i]=h[i]+10;
    }
    f1=f2=f3=1;
    for(i=0;i<n;i++)
    {
        a=s[i%l]-'i'+1;
        p1=ma[p1][a];
        if(p1/10==1)f1*=-1;
        p1=p1%10;
        if(p1==1&&f1==1)
        {
            f2=1;p2=0;
            for(j=i+1;j<n;j++)
            {
                b=s[j%l]-'i'+1;
                p2=ma[p2][b];
                if(p2/10==1)f2*=-1;
                p2=p2%10;
                if(p2==2&&f2==1)
                {
                    if(h[j+1]==3)return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("3in.txt", "r", stdin);
        freopen("3out.txt", "w", stdout);
    #endif
    int T,t;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d",&l,&x);
        scanf("%s",s);
        printf("Case #%d: ",t);
        if(check())puts("YES");
        else puts("NO");
    }
    return 0;
}
