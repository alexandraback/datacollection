#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
typedef long long LL;
LL power(LL a, LL p, LL mod){LL ret = 1;while(p){if(p&1)ret=(ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}
LL gcd(LL a, LL b){LL c=a%b; while(c!=0){a=b;b=c;c=a%b;} return b;}
int main()
{
    ios_base::sync_with_stdio(false);
    LL t, p, q, len, r, gc;
    int ans;
    string s;
    cin>>t;
    loop(x, 1, t+1)
    {
        ans = 0;
        cin>>s;
        len = s.size();
        r = 0; p = 0; q = 0;
        while(r<len && s[r]!='/')
        {
            p = p*10 + int(s[r]) - 48;
            r++;
        }
        r++;
        while(r<len)
        {
            q = q*10 + int(s[r]) - 48;
            r++;
        }
        gc = gcd(p, q);
        if(gc>1)
        {
            p = p/gc;
            q = q/gc;
        }
        if((q&-q)!=q)
            ans = -1;
        else
        {
            while(p<q)
            {
                p = p<<1;
                ans++;
            }
        }
        cout<<"Case #"<<x<<": ";
        if(ans==-1)
            cout<<"impossible\n";
        else
            cout<<ans<<endl;
    }
    return 0;
}
