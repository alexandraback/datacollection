#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define endl '\n'
#define gcd __gcd
#define lcm(x,y) ((x)*(y)/gcd(x,y))
#define smin(x,y) (x=min(x,y))
#define smax(x,y) (x=max(x,y))
#define sgcd(x,y) (x=gcd(x,y))
#define slcm(x,y) (x=lcm(x,y))
#define obt __builtin_popcount
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define rsort(x,y) sort(x,y),reverse(x,y);
#define dbg(x) cerr<<#x<<": "<<x<<endl
using namespace std;
bool b[3030];
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
    int t;
    cin>>t;
    for(int _=0;_<t;_++)
    {
        for(int i=0;i<2500;i++)
            b[i]=0;
        int n;
        cin>>n;
        for(int i=0;i<2*n*n-n;i++)
        {
            int a;
            cin>>a;
            b[a-1]^=1;
        }
        cout<<"Case #"<<_+1<<": ";
        for(int i=0;i<2500;i++)
            if(b[i])
                cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}
