#include <iostream>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

long long qw,n,x,ind;
bool mark1,mark2;
string s,s1;

char mul(char c,char a)
{
  //  cout<<c<<"*"<<a<<endl;
    if(c==a)
    {
        if(a!='1')
            ind*=-1;
        c='1';
        return c;
    }
    if(a=='1')
        return c;
    if(c=='1')
    {
        c=a;
        return c;
    }
    if(c!='i' && a!='i')
    {
        if(c>a)
            ind*=-1;
        c='i';
    }
    else if(c!='j' && a!='j')
    {
        if(c<a)
            ind*=-1;
        c='j';
    }
    else
    {
        if(c>a)
            ind*=-1;
        c='k';
    }
    return c;
}

int main()
{
    ifstream cin("C-large.in");
    ofstream cout("C-large.out");
    cin>>qw;
    for(int q=1;q<=qw;q++)
    {
        cin>>n>>x;
        if(x>20)
            x=20+x%20;
        cin>>s1;
        s="";
        for(int i=0;i<x;i++)
            s+=s1;
        char c=s[0];
        ind=1;
        mark1=mark2=false;
        if(c=='i')
            mark1=true;
        for(int i=1;i<s.size();i++)
        {
            c=mul(c,s[i]);
            //cout<<c<<" "<<ind<<endl;
            if(c=='i' && ind==1)
                mark1=true;
            if(mark1 && c=='k' && ind==1)
                mark2=true;
        }
        cout<<"Case #"<<q<<": ";
        if(mark2 && c=='1' && ind==-1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
