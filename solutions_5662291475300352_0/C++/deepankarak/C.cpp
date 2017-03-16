#include<bits/stdc++.h>

using namespace std;

#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()

int d[1001],h[1001],m[1001];

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int tc=1,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        int hh = 0;
        vector < pii > v;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&d[i],&h[i],&m[i]);
            hh += h[i];
            int j;
            for(j=0;j<h[i];j++)
            {
                v.pb(mp(d[i],m[i]+j));
            }
        }
        sort(all(v));
        assert(v.size() <= 2);
        assert(hh <= 2);
        int ans = 0;
        if(hh == 0)
        {
            ans = 0;
        }
        else if(hh == 1)
        {
            ans = 0;
        }
        else
        {
            assert(v.size() == 2);
            ll t1 = v[0].ss;
            ll t2 = v[1].ss;
            ll d1 = v[0].ff;
            ll d2 = v[1].ff;

            if(d1 == d2 && abs(t1-t2) <= 1)
            {
                ans = 0;
            }
            else
            {
                if(t1 > t2)
                {
                    if((360-d2+d1)*t2 < 360*t1)
                        ans = 1;
                    else
                        ans = 0;
                }
                else if(t1 == t2)
                {
                    ans = 0;
                }
                else
                {
                    if((360-d2+d1)*t2 > t1*360)
                        ans = 1;
                    else
                        ans = 0;
                }
            }
        }
        printf("Case #%d: %d\n",tc++,ans);
    }
    return 0;
}

