#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y);
#define slld(x) scanf("%lld",&x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007

vector <int>x;
int a[3000];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,j;
    sd(t);

    for(int q=1;q<=t;q++)
    {
        for(i=0;i<3000;i++)
            a[i]=0;
        int n;
        sd(n);
        for(i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int k;
                sd(k);
            a[k]++;
            }

        }
        printf("Case #%d:",q);
        for(i=0;i<3000;i++)
        {
            if(a[i]%2==1)
            {
                printf(" %d",i);
            }
        }
        printf("\n");






    }
}


