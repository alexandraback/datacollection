#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define F first
#define S second

int main()
{
    freopen("A-large (1).in","rt",stdin);
    freopen("out.txt","wt",stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        string s,out="";
        cin>>s;
        for(int j=0 ; j<s.size(); j++){
            if(!j)out+=s[j];
            else{
                if(s[j]>=out[0])out=s[j]+out;
                else out+=s[j];
            }
        }
        cout<<"Case #"<<i<<": "<<out<<endl;

    }
    return 0;
}
