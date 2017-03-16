#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void cn(string &s,string &a)
{
    int i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<s.size();j++)if(s[j]==a[i])
        {
            s[j]=0;
            break;
        }
    }
}

void dec(string &s,vector<int> &v)
{
    int i;
    string a;
    for(i=0;i<s.size();i++)
    {
        if(s[i]==0)continue;
        if(s[i]=='z'){a="zero";cn(s,a);v.push_back(0);}
        if(s[i]=='w'){a="two";cn(s,a);v.push_back(2);}
        if(s[i]=='u'){a="four";cn(s,a);v.push_back(4);}
        if(s[i]=='x'){a="six";cn(s,a);v.push_back(6);}
        if(s[i]=='g'){a="eight";cn(s,a);v.push_back(8);}
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i]==0)continue;
        if(s[i]=='o'){a="one";cn(s,a);v.push_back(1);}
        if(s[i]=='t'){a="three";cn(s,a);v.push_back(3);}
        if(s[i]=='f'){a="five";cn(s,a);v.push_back(5);}
        if(s[i]=='s'){a="seven";cn(s,a);v.push_back(7);}
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='i')v.push_back(9);
    }
}

int main()
{
    int tc,tci=0;
    cin>>tc;
    while(tc--)
    {
        tci++;
        int i;
        string s;
        cin>>s;
        for(i=0;i<s.size();i++)s[i]+=32;
        vector<int> v;
        dec(s,v);
        sort(v.begin(),v.end());
        cout<<"Case #"<<tci<<": ";
        for(i=0;i<v.size();i++)cout<<v[i];cout<<endl;
        //for(i=0;i<s.size();i++){if(s[i]==0)cout<<'0';else cout<<s[i];}cout<<endl;
    }
    return 0;
}
