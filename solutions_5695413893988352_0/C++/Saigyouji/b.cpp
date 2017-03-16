#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int mi=-1;
string rea,reb;

void deb(string &a,string &b,int l)
{
    if(l==b.size())
    {
        int na,nb;
        sscanf(a.c_str(),"%d",&na);
        sscanf(b.c_str(),"%d",&nb);
        //cout<<na<<" "<<nb<<endl;
        if(abs(na-nb)<mi||mi==-1)
        {
            mi=abs(na-nb);
            rea=a;
            reb=b;
        }
        return;
    }
    if(b[l]!='?'){deb(a,b,l+1);return;}
    int i;
    for(i=0;i<=9;i++)
    {
        b[l]='0'+i;
        deb(a,b,l+1);
        b[l]='?';
    }
}

void dea(string &a,string &b,int l)
{
    if(l==a.size()){deb(a,b,0);return;}
    if(a[l]!='?'){dea(a,b,l+1);return;}
    int i;
    for(i=0;i<=9;i++)
    {
        a[l]='0'+i;
        dea(a,b,l+1);
        a[l]='?';
    }
}

int main()
{
    int tc,tci=0;
    cin>>tc;
    while(tc--)
    {
        tci++;
        string a,b;
        cin>>a>>b;
        mi=-1;
        dea(a,b,0);
        cout<<"Case #"<<tci<<": "<<rea<<" "<<reb<<endl;
    }
    return 0;
}
