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
ll M=1e9+7;



ll mpe(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    fastScan;
    ll t;
    cin>>t;
    repp(cas,1,t+1){
        string str;
        cin>>str;
        int arr[26]={0};
        int ans[10]={0};
        rep(i,str.size()){
            arr[str[i]-'A']++;
        }
        //cout<<arr['O'-'A'];
        int mi=10000000;

        mi=10000000;
        mi=min(mi,arr['S'-'A']);mi=min(mi,arr['I'-'A']);mi=min(mi,arr['X'-'A']);
        ans[6]=mi;
        arr['S'-'A']-=mi;arr['I'-'A']-=mi;arr['X'-'A']-=mi;

         mi=10000000;
        mi=min(mi,arr['S'-'A']);mi=min(mi,(arr['E'-'A'])/2);mi=min(mi,arr['V'-'A']);mi=min(mi,arr['N'-'A']);
        ans[7]=mi;
        arr['S'-'A']-=mi;arr['V'-'A']-=mi;arr['N'-'A']-=mi;arr['E'-'A']-=2*mi;

        mi=10000000;
        mi=min(mi,arr['E'-'A']);mi=min(mi,arr['I'-'A']);mi=min(mi,arr['G'-'A']);mi=min(mi,arr['H'-'A']);mi=min(mi,arr['T'-'A']);
        ans[8]=mi;
        arr['E'-'A']-=mi;arr['I'-'A']-=mi;arr['G'-'A']-=mi;arr['H'-'A']-=mi;arr['T'-'A']-=mi;


        mi=10000000;
        mi=min(mi,arr['Z'-'A']);mi=min(mi,arr['E'-'A']);mi=min(mi,arr['R'-'A']);mi=min(mi,arr['O'-'A']);
        ans[0]=mi;
        arr['Z'-'A']-=mi;arr['R'-'A']-=mi;arr['E'-'A']-=mi;arr['O'-'A']-=mi;

        mi=10000000;
        mi=min(mi,arr['F'-'A']);mi=min(mi,arr['I'-'A']);mi=min(mi,arr['V'-'A']);mi=min(mi,arr['E'-'A']);
        ans[5]=mi;
        arr['F'-'A']-=mi;arr['I'-'A']-=mi;arr['V'-'A']-=mi;arr['E'-'A']-=mi;

        mi=10000000;
        mi=min(mi,arr['F'-'A']);mi=min(mi,arr['O'-'A']);mi=min(mi,arr['U'-'A']);mi=min(mi,arr['R'-'A']);
        ans[4]=mi;
        arr['F'-'A']-=mi;arr['O'-'A']-=mi;arr['U'-'A']-=mi;arr['R'-'A']-=mi;

        mi=10000000;
        mi=min(mi,arr['T'-'A']);mi=min(mi,arr['W'-'A']);mi=min(mi,arr['O'-'A']);
        ans[2]=mi;
        arr['T'-'A']-=mi;arr['W'-'A']-=mi;arr['O'-'A']-=mi;


        mi=10000000;
        mi=min(mi,arr['T'-'A']);mi=min(mi,(arr['E'-'A'])/2);mi=min(mi,arr['R'-'A']);mi=min(mi,arr['H'-'A']);
        ans[3]=mi;
        arr['T'-'A']-=mi;arr['H'-'A']-=mi;arr['R'-'A']-=mi;arr['E'-'A']-=2*mi;


        mi=10000000;
        mi=min(mi,(arr['N'-'A'])/2);mi=min(mi,arr['I'-'A']);mi=min(mi,arr['E'-'A']);
        ans[9]=mi;
        arr['N'-'A']-=2*mi;arr['I'-'A']-=mi;arr['E'-'A']-=mi;

        mi=10000000;
        mi=min(mi,arr['O'-'A']);mi=min(mi,arr['N'-'A']);mi=min(mi,arr['E'-'A']);
        ans[1]=mi;
        arr['O'-'A']-=mi;arr['N'-'A']-=mi;arr['E'-'A']-=mi;








        rep(i,26)assert(arr[i]==0);
        //cout<<arr['O'-'A']<<"  "<<arr['T'-'A']<<"  "<<arr['W'-'A'];


        cout<<"Case #"<<cas<<": ";
        rep(i,10){
            while(ans[i]--)cout<<i;
        }
        cout<<endl;

    }

    return 0;
}
