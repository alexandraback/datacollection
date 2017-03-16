#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
char first=s[0],last=s[0];
string t="";
t.push_back(s[0]);
for(int i=1;i<s.length();i++)
{
    bool flag=true;
   
    if(s[i]<last or s[i]< first)
    {
        t.push_back(s[i]);
        last=s[i];
        continue;
    }
    else if(s[i]>=first or s[i]>=last);
    {
        t.insert(t.begin(),s[i]);
        first=s[i];
    }  
     //cout<<t<<endl;
}
return t;
}
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
    string s;
    cin>>s;
    cout<<"Case #"<<i<<": ";
    cout<<solve(s)<<endl;
}
}
