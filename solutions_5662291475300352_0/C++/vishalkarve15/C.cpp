#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int d[1010];
int h[1010];
int m[1010];

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d%d%d",&d[i],&h[i],&m[i]);

        if(n==1 && h[0]==1)
        {
            printf("Case #%d: 0\n",tt);
            continue;
        }
        ll d1,m1,d2,m2;
        if(n==1 && h[0]==2)
        {
            d1=d2=d[0];
            m1=m[0];
            m2=m1+1;
        }
        if(n==2)
        {
            d1=d[0];
            d2=d[1];
            m1=m[0];
            m2=m[1];
        }
        if(m1>m2)
        {
            swap(m1,m2);
            swap(d1,d2);
        }
        if(m2*(360-d2)>=m1*(720-d1))
            printf("Case #%d: 1\n",tt);
        else
            printf("Case #%d: 0\n",tt);
    }
    return 0;
}
