#include<bits/stdc++.h>
#define ll long long int
#define PB push_back
#define F first
#define S second
#define tr(c,i) for(typeof((c).begin())i = (c).begin(); i != (c).end(); i++) 
#define sint(n); scanf("%d",&n);
#define sll(n); scanf("%lld",&n);
#define pint(n); printf ("%d\n",n);
#define pll(n); printf ("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define set(a,b) memset(a, b, sizeof(a))


using namespace std;

ll arr[3][1000000];

int main()
{
    ll t;
    cin>>t;
    f(tst, 1, t+1)
    {
        ll j,p,s,k,ans=0;
        cin>>j>>p>>s>>k;
        printf("Case #%lld: ", tst);

        f(m, 1, j+1)
        {
            f(n, 1, p+1)
            {
                ll pct=0;
                if (pct>=k)
                    break;
                f(o, 1, s+1)
                {
                    //cout<<m<<" "<<n<<" "<<o<<endl;
                    arr[0][ans] = m;
                    arr[1][ans] = n;
                    arr[2][ans] = o;
                    ans++;
                    pct++;
                    if (pct>=k)
                        break;
                }
            }
        }
        cout<<ans<<endl;
        f(i, 0, ans)
        {
            cout<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i]<<endl;
        }
    }
    return 0;
}
