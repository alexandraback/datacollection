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
int n;
int war(const vector<double>& naomi,const vector<double>& ken)
{
    int i,j=0,naomi_wins=0,ken_wins=0;
    for(i=0; i<n; i++)
    {
        while(j<n)
        {
            if(ken[j]>naomi[i])
            {
                break;
            }
            j++;
        }
        if(j==n)  // Game over already!..
        {
            naomi_wins+=n-i;
            break;
        }
        else
        {
            j++;
            ken_wins++;
        }
    }
    return naomi_wins;
}
int dwar(const vector<double>& naomi,const vector<double>& ken)
{
    int i,j=0,naomi_wins=0,ken_wins=0;
    for(i=0; i<n; i++)
    {
        if(naomi[i]<ken[j])
        {
            ken_wins++;
        }
        else
        {
            naomi_wins++;
            j++;
        }
    }
    return naomi_wins;
}
int main()
{
    int t,i,tc=1;
    fastin;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<double> naomi(n),ken(n);
        for(i=0; i<n; i++)
        {
            cin>>naomi[i];
        }
        for(i=0; i<n; i++)
        {
            cin>>ken[i];
        }
        sort(all(naomi));
        sort(all(ken));
        int ans=war(naomi,ken);
        int dans=dwar(naomi,ken);
        cout<<"Case #"<<tc++<<": "<<dans<<" "<<ans<<"\n";
    }
}
