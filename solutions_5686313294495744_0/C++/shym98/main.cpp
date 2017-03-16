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

vector<pair<string,string> > a(1100);
int n;

int ck(int mask)
{
    int k=0;
    forn(i,n)
    {
        if ((mask>>i)&1)
        {
            bool ok=false,ok1=false;
            forn(j,n)
            {
                if (((mask>>j)&1)==0)
                {
                    if (a[j].F == a[i].F) ok=true;
                    if (a[j].S == a[i].S) ok1=true;
                }
            }
            if (ok && ok1) k++;
        }
    }
    return k;
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
        cin>>n;
        a.resize(n);
        forn(i,n) cin>>a[i].F>>a[i].S;
        int mx=0;
        forn(mask,(1<<n))
        {
            mx=max(mx,ck(mask));
        }
        cout<<"Case #"<<Q+1<<": "<<mx<<endl;
    }
    return 0;
}
