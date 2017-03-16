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

ll l,mi=1000000000000000000+10000000,f=0;
ll a[19],b[19];
string ana,anb;

void func(int i,string A,string B,int fl){
    string tmpA=A,tmpB=B,ta=A,tb=B;
    if(i==l){
       // cout<<A<<"  "<<B<<endl;
        assert(A.size()==l && B.size()==l);
        ll ad=0,bd=0,tmp=l;
        while(tmp--){
            ad*=10;
            ad+=(A[l-tmp-1]-'0');
            //cout<<ad<<"        ";
            bd*=10;
            bd+=(B[l-tmp-1]-'0');

        }
       // cout<<ad<<"   "<<bd<<endl;
            if(abs(ad-bd)<mi){
                mi=abs(ad-bd);
                ana=A;
                anb=B;
            }
            else if(abs(ad-bd)==mi && (A<ana || (A==ana && B<anb))){
                mi=abs(ad-bd);
                ana=A;
                anb=B;
            }
        return;
    }
    if(fl==1){
        if(a[i]==-1)A+='0';
        else A+=('0'+a[i]);
        if(b[i]==-1)B+='9';
        else B+=('0'+b[i]);
        func(i+1,A,B,1);
        return;
    }
    if(fl==-1){
        if(a[i]==-1)A+='9';
        else A+=('0'+a[i]);
        if(b[i]==-1)B+='0';
        else B+=('0'+b[i]);
        func(i+1,A,B,-1);
        return;
    }
    if(a[i]!=-1 && b[i]!=-1){
        if(a[i]>b[i])fl=1;
        if(a[i]<b[i])fl=-1;
        A+=('0'+a[i]);
        B+=('0'+b[i]);
        func(i+1,A,B,fl);
    }
    else if(a[i]==-1 && b[i]==-1){
        A+=('0');
        B+=('0');
        func(i+1,A,B,fl);
        tmpA+=('0');
        tmpB+=('1');
        func(i+1,tmpA,tmpB,-1);
        ta+=('1');
        tb+=('0');
        func(i+1,ta,tb,1);

    }
    else if(a[i]==-1){
        A+=('0'+ b[i]);
        B+=('0'+b[i]);
        func(i+1,A,B,fl);
        if(b[i]!=0){
        tmpA+=('0'+ b[i]-1);
        tmpB+=('0'+b[i]);
        func(i+1,tmpA,tmpB,-1);
        }
        if(b[i]!=9){
            ta+=('0'+ b[i]+1);
        tb+=('0'+b[i]);
        func(i+1,ta,tb,1);
        }
    }
    else{
        A+=('0'+ a[i]);
        B+=('0'+a[i]);
        func(i+1,A,B,fl);
        if(a[i]!=9){
        tmpA+=('0'+ a[i]);
        tmpB+=('0'+a[i]+1);
        func(i+1,tmpA,tmpB,-1);
        }
        if(a[i]!=0){
            ta+=('0'+ a[i]);
        tb+=('0'+a[i]-1);
        func(i+1,ta,tb,1);
        }
    }
    return;
}



int main()
{
    fastScan;
    ll t;
    cin>>t;
    repp(cas,1,t+1){
        mi=1000000000000000000+10000000;
        f=0;
        string sta,stb;
        cin>>sta>>stb;
        l=sta.size();
        rep(i,sta.size()){
            if(sta[i]=='?')a[i]=-1;
            else a[i]=sta[i]-'0';
            if(stb[i]=='?')b[i]=-1;
            else b[i]=stb[i]-'0';
        }
        func(0,"","",0);
        cout<<"Case #"<<cas<<": ";
        cout<<ana<<" "<<anb;
        cout<<endl;

    }

    return 0;
}
