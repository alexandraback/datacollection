#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ll long long
#define v vector
#define pr pair<int,int>
#define sd second
#define ft first
#define pb push_back
#define mp make_pair
#define total 400000
#define pie 3.1415926535897932384626433832795
int flag=0;
string str(int x)
{
    string ans="";
    while(x!=0)
    {
        ans+=x%10+48;
        x/=10;
    }
    int i,n=ans.length(),t;
    for(i=0;i<ans.length()/2;i++)
    {

        t=ans[i];
        ans[i]=ans[n-i-1];
        ans[n-i-1]=t;
    }
    return ans;
}
string convert(int x,int n)
{
    string j=str(x);
    string ans="";
    for(int i=1;i+j.length()<=n;i++)
    {
        ans+="0";
    }
    ans+=j;
    return ans;
}
bool check(string s,int x)
{
    string d=str(x);
    if(d.length()>s.length())
    {
        return 0;
    }
    else
    {
        d=convert(x,s.length());
    }
    for(int i=0;i<d.length();i++)
    {
        if(s[i]==d[i])
            continue;
        else
        {
            if(s[i]!='?')
                return 0;
        }
    }
    return 1;
}
int main()
{
   // freopen("B-small-attempt0.in","r",stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t,k,i,j;
    string s,d;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>s>>d;
        int sans=INT_MAX,dans=INT_MAX;
        int m=INT_MAX;
        for(i=0;i<=999;i++)
        {
            if(check(s,i))
            {
                for(j=0;j<=999;j++)
                {
                    if(check(d,j))
                    {
                        if(abs(i-j)<m)
                        {
                            m=abs(i-j);
                                sans=i;
                                dans=j;
                        }
                        else if(abs(i-j)==m)
                        {
                            if((i<=sans&&j==dans)||(i==sans&&j<=dans))
                            {
                                sans=i;
                                dans=j;
                            }
                        }


                    }
                }
            }
        }
        flag=1;
        string fans,fdans;
        fans=convert(sans,s.length());
        fdans=convert(dans,s.length());
        cout<<"Case #"<<k<<":"<<" "<<fans<<" "<<fdans<<endl;
    }
    return 0;
}
