#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define x first
#define y second
#define pow hi1
#define mp make_pair
#define ll long long
#define pb push_back
#define bro pair<int, int>
#define all(a) (a).begin(), (a).end()

const int N=45;

int t, ans, i, n=41;
long long g, p, q, pow[N];

long long gcd(long long x, long long y)
{
    while(x>0&&y>0)
        if(x>y)x%=y; else y%=x;
    return x+y;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("A-small-attempt4.in","r",stdin);
    freopen("1.txt","w",stdout);
    pow[0]=1;
    for(i=1; i<n; i++)
        pow[i]=pow[i-1]+pow[i-1];
    cin>>t;
    char c;
    int k=0;
    while(t--)
    {
        k++;
        ans=-1;
        cin>>p>>c>>q;
        g=gcd(p, q);
        p/=g;
        q/=g;
        for(i=0; i<=n; i++)
            if(pow[i]>q)break; else
            if(q%pow[i]==0&&(q/pow[i])<=p)
            {
                ans=i;
                break;
            }
        int f=0;
        for(i=0; i<=n; i++)
            if(pow[i]==q)
            {
                f=1;
                break;
            }
        if(!f)ans=-1;
        cout<<"Case #"<<k<<": ";
        if(ans<0)cout<<"impossible"<<endl;
            else cout<<ans<<endl;
    }
}
