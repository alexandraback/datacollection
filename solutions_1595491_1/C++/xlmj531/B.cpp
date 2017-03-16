#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 128;

int a[maxn], surp[maxn];
int n, s, p, cas, s1, s2;

int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.out","w",stdout);
    scanf("%d",&cas);
    for (int run = 1; run<=cas; run++ )
    {
        scanf("%d%d%d",&n,&s,&p);
        s1 = s2 = 0;
        for (int i = 0; i<n; i++ )
        {
            int x;
            scanf("%d",&x);
            if (x==0) a[i] = surp[i] = 0;
            if (x==1) a[i] = surp[i] = 1;
            if (x>1)
            {
                a[i] = (x+2)/3;
                surp[i] = (x%3==1 ? a[i] : a[i]+1);
            }
            //a[i] = (a[i]>=p);
            //surp[i] = (surp[i]>=p);
            if (a[i]>=p) ++s1;
            else if (surp[i]>=p) ++s2;
        }
        printf("Case #%d: %d\n",run,s1+min(s2,s));
    }
    return 0;
}
