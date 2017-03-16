#pragma comment(linker,"/STACK:100000000000,100000000000")

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define D long double
#define pi pair<int,int>
#define F first
#define S second
#define forn(i,n) for (int(i)=0;(i)<(n);i++)
#define forr(i,x,y) for (int(i)=(x);(i)<=(y);i++)
#define ford(i,x,y) for (int(i)=(x);(i)>=(y);i--)
#define rev reverse
#define in insert
#define er erase
#define all(n) (n).begin(),(n).end()
#define graf vector<vector<pi> >
#define graf1 vector<vector<ll> >
#define sqr(a) (a)*(a)
#define file freopen("a.in","r",stdin);freopen("a.out","w",stdout);
#define y1 asdadasdasd

const int INF = 1e9;
const D cp = 2 * asin(1.0);
const D eps = 1e-9;
const ll mod = 1000000007;

using namespace std;

ll a[10][10],b[10][10],c[10][10];
ll sum,n,m;

void mult ()
{
    memset(c,0,sizeof(c));
    forn(i,n)
        forn(j,n)
            forn(k,n)
            c[i][j]+=a[i][k]*b[k][j];
    forn(i,n)
        forn(j,n)
        b[i][j]=c[i][j];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //file;
    int T;
    cin>>T;
    forn(Q,T)
    {
        cout<<"Case #"<<Q+1<<": ";
        cin>>n>>m;
        vector<pair<int,int> > coord;
        forn(i,n)
            forr(j,i+1,n-1) coord.pb(mp(i,j));
        int ms = coord.size();
        bool ok=false;
        ford(mask,(1<<ms)-1,0)
        {
            sum=0;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
            forn(i,ms)
            {
                a[coord[i].F][coord[i].S]=b[coord[i].F][coord[i].S]=((mask>>i)&1);
            }
            int k=0;
            while(1)
            {
                k++;
                sum+=b[0][n-1];
                mult();
                if (b[0][n-1]==0) break;
            }
            if (sum==m) {ok=true;break;}
        }
        if (ok) {cout<<"POSSIBLE\n";
            forn(i,n){forn(j,n) cout<<a[i][j];cout<<endl;}} else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
