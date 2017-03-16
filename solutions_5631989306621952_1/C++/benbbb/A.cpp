#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char x[2000],y[2000];
void solve(int l,int r,int l2,int r2)
{
    int i,j;
    if(l>r) return ;
    if (l==r) {y[l2]=x[l];return ;}
    int maxn,mx;
    maxn=0;mx=0;
    for (i=l;i<=r;i++)
    if (x[i]>=maxn) {maxn=x[i];mx=i;}
    //cout<<mx<<endl;
    for (i=mx+1,j=l2+mx-l+1;j<=r2;i++)
    {
        y[j]=x[i];
        j++;
    }
    y[l2]=x[mx];
    solve(l,mx-1,l2+1,l2+mx-l);
    //solve(mx+1,r,l2+mx-l+1,r2);
    return ;
}
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("A.out","w",stdout);
    int T,ca;
    cin>>T;

    for (ca=1;ca<=T;ca++)
    {
        cin>>x;
        memset(y,0,sizeof y);
        int l=strlen(x)-1;
        solve(0,l,0,l);
        printf("Case #%d: ",ca);
        for (int i=0;i<=l;i++) cout<<y[i];
        cout<<endl;

    }

    fclose(stdout);
    return 0;
}
