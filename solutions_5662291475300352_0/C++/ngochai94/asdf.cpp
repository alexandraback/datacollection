#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long t,n,d1,d2,m1,m2,h;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        if(n==1)
        {
            cin>>d1>>h>>m1;
            if(h==1)
            {
                cout<<0<<endl;
                continue;
            }
            d2=d1;m2=m1+1;
        }
        else
        {
            cin>>d1>>h>>m1>>d2>>h>>m2;
        }
        if(m2*(360-d2)>=m1*(720-d1)||m1*(360-d1)>=m2*(720-d2)) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
