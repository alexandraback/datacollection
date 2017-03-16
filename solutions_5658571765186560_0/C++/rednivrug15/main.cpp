/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    freopen("inp.txt" ,"r",stdin);
    freopen("op.txt","w",stdout);

    vector < pair < int, int >  > ans[5];
    ans[4].pb(mp(3,4));
    ans[4].pb(mp(4,3));
    ans[4].pb(mp(4,4));

    ans[3].pb(mp(2,3));
    ans[3].pb(mp(3,2));
    ans[3].pb(mp(3,3));
    ans[3].pb(mp(4,3));
    ans[3].pb(mp(3,4));

    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d:  ",cases);

        if(x==1)
            printf("GABRIEL\n");
        else if(x==2)
        {
            if((r*c)%2==0)
             printf("GABRIEL\n");
            else
                printf("RICHARD\n");
        }
        else
        {
            bool flag=0;
            for(int i=0; i<ans[x].size(); i++)
            {
                if(ans[x][i].first==r && ans[x][i].second==c)
                    flag=1;
            }
            if(flag==1)
                printf("GABRIEL\n");
            else
                printf("RICHARD\n");
        }
    }
    return 0;
}
