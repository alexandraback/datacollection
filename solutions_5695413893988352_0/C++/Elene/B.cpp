#include <bits/stdc++.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F first
#define S second
#define pp pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 2000000
#define P 1000000007
#define E 10000000
#define vec vector<vector<ll> >
using namespace std;
const int N=100005;
string a,b,ANS,BNS,x,y;

ll convert(string s){
    ll ans=0;
    for(int i=0;i<s.size();i++)ans=ans*10+(int)s[i]-'0';
    return ans;
}


void work(int ind,string x,string y){

    //cout<<"work "<<ind<<' '<<x<<' '<<y<<endl;

    for(int i=ind+1;i<x.size();i++)
       if(x[i]=='?')
       if(x[ind]<y[ind])x[i]='9';else x[i]='0';
    for(int i=ind+1;i<y.size();i++)
       if(y[i]=='?')
       if(y[ind]<x[ind])y[i]='9';else y[i]='0';
//
    //cout<<"next "<<x<<' '<<y<<endl;
    if(ANS==""){ANS=x,BNS=y;return;}



    ll X=convert(x);
    ll Y=convert(y);
    ll A=convert(ANS);
    ll B=convert(BNS);

    //cout<<X<<' '<<Y<<' '<<A<<' '<<B<<endl;

    if(abs(X-Y)<abs(A-B) ||
       abs(X-Y)==abs(A-B) && X<A ||
       abs(X-Y)==abs(A-B) && X==A && Y<B)ANS=x,BNS=y;
}

void check(int ind){
   // cout<<"check "<<ind<<endl;


    x=a,y=b;





    for(int i=0;i<ind;i++){
        if(x[i]=='?' && y[i]=='?')x[i]=y[i]='0';else
        if(y[i]=='?')y[i]=x[i];else
                     x[i]=y[i];

        if(x[i]!=y[i])return;
    }
    if(a[ind]!='?' && b[ind]!='?')work(ind,x,y);else
    if(x[ind]=='?' && y[ind]=='?'){
        x[ind]='0'; y[ind]='1'; work(ind,x,y);
        x[ind]='1'; y[ind]='0'; work(ind,x,y);
    }else
    if(x[ind]=='?'){
        if(y[ind]!='0'){x[ind]=y[ind]-1;work(ind,x,y);}
        if(y[ind]!='9'){x[ind]=y[ind]+1;work(ind,x,y);}
    }else
    if(y[ind]=='?'){
        if(x[ind]!='0'){y[ind]=x[ind]-1;work(ind,x,y);}
        if(x[ind]!='9'){y[ind]=x[ind]+1;work(ind,x,y);}
    }
}


int main()
{   freopen("B-small-attempt2.in","r",stdin);
   // freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>a>>b;
        while(a.size()<b.size())a="0"+a;
        while(b.size()<a.size())b="0"+b;

        int n=a.size();
        ANS=BNS="";

        for(int i=0;i<=n;i++){
            check(i);
            if(i==n)break;
            if(a[i]!='?' && b[i]!='?' && a[i]!=b[i])break;
        }

        cout<<"Case #"<<t<<": "<<ANS<<' '<<BNS<<endl;
    }


    return 0;
}
