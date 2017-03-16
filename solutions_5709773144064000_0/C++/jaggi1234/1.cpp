#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define iter(container,it) typeof(container.begin()) it
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h>
#endif
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define iter(container,it) typeof(container.begin()) it
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h>
#endif
int main()
{
    int t,tc=1;
    double C,F,X,R;
    cout_precision(7);
    fastin;
    cin>>t;
    while(t--)
    {
        double ans=0;
        cin>>C>>F>>X;
        R=2;
        while(1)
        {
            if(X/R < C/R + X/(R+F))
            {
                ans+=X/R;
                break;
            }
            ans+=C/R;
            //debug(C/R);
            R+=F;
        }
        cout<<"Case #"<<tc++<<": "<<ans<<"\n";
    }
}
