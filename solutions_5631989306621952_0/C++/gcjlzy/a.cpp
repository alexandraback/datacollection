#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const ll N=1e9;
string s;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int n,i;
        char c='A';
        cin>>s;
        string ans="";
        for(i=0;i<s.length();i++)
            if(c<=s[i])
        {
            ans=s[i]+ans;
            c=s[i];
        }
        else ans+=s[i];
        printf("Case #%d: ",k);
        cout<<ans<<endl;
    }

    return 0;
}
