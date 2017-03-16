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
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        vector<pair<int,pair<int,int> > > res;
        map<pair<pair<int,int>,pair<int,int> >, int> pos;
        forn(i,a)
            forn(j,b)
                forn(q,c)
                {
                    if (pos[mp(mp(1,i),mp(2,j))]<k && pos[mp(mp(1,i),mp(3,q))]<k && pos[mp(mp(2,j),mp(3,q))]<k)
                    {
                        res.pb(mp(i+1,mp(j+1,q+1)));
                        pos[mp(mp(1,i),mp(2,j))]++;
                        pos[mp(mp(1,i),mp(3,q))]++;
                        pos[mp(mp(2,j),mp(3,q))]++;
                    }
                }
        cout<<res.size()<<endl;
        forn(i,res.size()) cout<<res[i].F<<' '<<res[i].S.F<<' '<<res[i].S.S<<endl;
        res.clear();
        pos.clear();
    }
    return 0;
}
