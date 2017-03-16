#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define F first
#define S second
map<int,int> mp;
int main()
{
    freopen("B-large (1).in","rt",stdin);
    freopen("out.txt","wt",stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n,d;
        cin>>n;

        for(int k=1; k<2*n; k++)
        for(int j=0 ; j<n; j++){
           cin>>d;
            mp[d]++;
        }
        vector<int> v;
        for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++)
            if(it->second%2==1)v.push_back(it->first);

         cout<<"Case #"<<i<<":";
        for(int g=0; g<v.size(); g++)
            cout<<" "<<v[g];
        cout<<endl;
mp.clear();
    }
    return 0;
}
