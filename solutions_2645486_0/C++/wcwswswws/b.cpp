#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
long long E,R;
priority_queue< long long > a;
priority_queue< long long > b;

int main()
{
    freopen("B-small-attempt10.in","r",stdin);
    freopen("B-small-attempt10.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%I64d%I64d%d",&E,&R,&n);
        while (!a.empty()) a.pop();
        while (!b.empty()) b.pop();
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            long long x;
            scanf("%I64d",&x);
            a.push(x);
        }
        if (E<=R)
        {
            while (!a.empty()) {ans+=E*a.top();a.pop();}
        } else
        {
            long long F=E%R,G=E/R;
            ans=E*a.top();long long nn=n;
            a.pop();
            while ((nn>0)&&(!a.empty()))
            {
                if ((!b.empty())&&(b.top()*F>=a.top()*R)&&(nn>1))
                {
                    ans+=b.top()*F;b.pop();
                    nn--;
                    if (nn<=1) break;
                    continue;
                }
                nn--;
                if (nn<=G)
                {
                    ans+=nn*R*a.top();
                    break;
                }
                ans+=G*R*a.top();nn-=G;
                if (F>0) b.push(a.top());
                a.pop();
                if (a.empty()) break;
                if (nn==0) break;
                nn++;
            }
        }
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}
