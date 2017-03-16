#include<bits/stdc++.h>

using namespace std;

int main()
{
int t,it=1;
cin>>t;
while(t--)
{
string s;
cin>>s;
    string ans="";
    ans+=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]>=ans[0])
        {
        string ans1="";
        ans1+=s[i];
        ans1+=ans;
        ans=ans1;
        }
        else
        {
        ans+=s[i];
        }

    }
    cout<<"Case #"<<it++<<": ";
    cout<<ans<<endl;

}


return 0;}
