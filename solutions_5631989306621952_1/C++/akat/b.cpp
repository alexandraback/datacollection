#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
void solve()
{
    string s,o="";
    cin>>s;
    int n=s.size(),i;
    for(i=0;i<n;i++)
        if(o+s[i]>s[i]+o)o=o+s[i];
        else o=s[i]+o;
    cout<<o<<'\n';
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
