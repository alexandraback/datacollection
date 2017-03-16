#include <bits/stdc++.h>

using namespace std;

#define int long long

int mp=1ll<<40;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int test=0;test<T;test++)
    {
        cout<<"Case #"<<test+1<<": ";

        int p,q;
        char t;
        cin>>p>>t>>q;
        int g=gcd(p,q);
        p/=g;q/=g;
        if(mp%q) cout<<"Impossible";
        else
        {
            int x;
            for(x=0;(1<<x)*p<q;x++);
            cout<<x;
        }



        cout<<endl;

    }
}
