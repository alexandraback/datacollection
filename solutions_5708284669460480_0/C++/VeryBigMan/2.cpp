#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
using namespace std;
string vec;
string str1;
string target;
int k,l,s;
int maxans=0;
int getnum(string str)
{
    int ans=0;
    int l1=s;
    int l2=target.length();
    for(int i=0;i<=l1-l2;i++)
    {
        bool flag=true;
        for(int j=0;j<l2;j++)
        {
            if(str[i+j]!=target[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            ans++;
        }
    }
    maxans=max(ans,maxans);
    return ans;
}
int ret=0;
int need=0;
void dfs(int index, string str)
{
    if(index>s)
    {
        return;
    }
    for(int i=0;i<k;i++)
    {
        char prev=str[index];
        str[index]=vec[i];
        if(index==s-1)
        {
            need++;
            int temp=getnum(str);
            ret+=temp;
        }
        dfs(index+1, str);
        str[index]=prev;
    }
}
int func(string str)
{
    int ans=1;
    for(int i=1;i<=s;i++)
    {
        ans*=k;
    }
    return ans;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        need=0;
        maxans=0;
        ret=0;
        cin>>k>>l>>s;
        cin>>str1>>target;
        vec=str1;
        string tempstr;
        for(int i=0;i<s;i++)
        {
            tempstr.push_back('A');
        }
        dfs(0,tempstr);
    //    cout<<need<<endl;
        cout.setf(ios::showpoint);
        cout.precision(7);
        cout.setf(ios::fixed);
    //    cout<<ret<<" "<<func(str1)<<endl;
        cout<<"Case #"<<tt<<": "<<maxans-(double)ret/(double)func(str1)<<endl;
    }
    return 0;
}

