#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)
            swap(r,c);
        //GABRIEL : can fit everything
        //RICHARD : can't fit
        if(x>=7 || (r*c)%x!=0)
        {
            printf("Case #%d: RICHARD\n",tt);
            continue;
        }
        if(x==6||x==5)
        {
            if(r<=3)
            {
                printf("Case #%d: RICHARD\n",tt);
                continue;
            }
            printf("Case #%d: GABRIEL\n",tt);
            continue;
        }
        if(r<x-1)
        {
            printf("Case #%d: RICHARD\n",tt);
            continue;
        }
        printf("Case #%d: GABRIEL\n",tt);
    }
    return 0;
}
