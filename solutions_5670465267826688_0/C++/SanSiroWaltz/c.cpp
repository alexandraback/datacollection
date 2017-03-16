#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int g[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

struct ijk
{
    int data;
    ijk operator *(ijk a)const
    {
        int t=1;
        if (data<0) t=-t;
        if (a.data<0) t=-t;
        ijk x;
        x.data=t*g[abs(data)][abs(a.data)];
        return x;
    }
};

char s[10010];
ijk a[10010];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;scanf("%d",&test);
    for (int tt=1;tt<=test;tt++)
    {
        int l;ll n;scanf("%d%I64d",&l,&n);
        scanf("%s",s);
        for (int i=0;i<l;i++)
        {
            if (s[i]=='i') a[i].data=2;
            if (s[i]=='j') a[i].data=3;
            if (s[i]=='k') a[i].data=4;
        }
        ijk ans;ans.data=1;
        for (int i=0;i<l;i++) ans=ans*a[i];
        ijk t;t.data=1;
        for (int i=1;i<=n%4;i++) t=t*ans;
        if (t.data!=-1) {printf("Case #%d: NO\n",tt);continue;}
        ll ans1=ll(n)*l,ans2=-1;
        ijk now;now.data=1;
        for (int j=0;j<4;j++)
            for (int i=0;i<l;i++)
            {
                now=now*a[i];
                if (now.data==2) {ans1=min(ans1,ll(j)*l+i);break;}
            }
        now.data=1;
        for (int j=0;j<4;j++)
            for (int i=l-1;i>=0;i--)
            {
                now=a[i]*now;
                if (now.data==4) {ans2=max(ans2,ll(n-j-1)*l+i);break;}
            }
        if (ans1<ans2-1) printf("Case #%d: YES\n",tt); else printf("Case #%d: NO\n",tt);
    }
    return 0;
}
