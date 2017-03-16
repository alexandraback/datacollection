#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 0.0000001
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define maxn 32000

int t,x,r,c;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>x>>r>>c;
        if(r>c) swap(r,c);
        //cout<<x<<' '<<r<<' '<<c<<endl;
        bool flag=false;
        if(x>c||x>6||(r*c)%x!=0||x>=2*r+1) flag=true;
        if(x==4&&r==2) flag=true;
        if(x==5&&r<=3) flag=true;
        if(x==6&&r<=3) flag=true;
        if(flag) cout<<"RICHARD"<<endl;
        else cout<<"GABRIEL"<<endl;
        //cout<<endl;
    }
}

