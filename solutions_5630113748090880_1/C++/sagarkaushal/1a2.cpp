#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        long long i,j,k,a=0,n;
        cin>>n;
        map<long long int,long long int> ma;
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>k;
                ma[k]++;    
            }    
        }
        map<long long int,long long int>::iterator it;
        set<long long >se;
        for(it=ma.begin();it!=ma.end();it++)
        {
            if(it->second%2!=0)
                se.insert(it->first);
        }
        cout<<"Case #"<<tt<<":";
        set<long long int>::iterator iit;
        for(iit=se.begin();iit!=se.end();iit++)
            cout<<" "<<*iit;
        cout<<"\n";
    }
    return 0;
}
