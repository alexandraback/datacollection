#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(ll i=0;i<a;++i)
#define repp(i,a,b) for(ll i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define    foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);







int main()
{
    fastScan;
    ll t;
    cin>>t;
    repp(cas,1,t+1){
        map<string,int> mpa,mpb;
        vector<pair<string,string> > vec;
        ll n;
        cin>>n;
        string a,b;
        rep(i,n){
            cin>>a>>b;
            vec.pb(mp(a,b));
            if(mpa.find(a)==mpa.end())mpa[a]=1;
            else mpa[a]++;
            if(mpb.find(b)==mpb.end())mpb[b]=1;
            else mpb[b]++;
        }
        ll an=0;
        rep(i,n){
            if(mpa[vec[i].X]>1 && mpb[vec[i].Y]>1){
                an++;
                mpa[vec[i].X]--;
                mpb[vec[i].Y]--;
            }
        }
        cout<<"Case #"<<cas<<": ";
        cout<<an;
        cout<<endl;

    }

    return 0;
}
