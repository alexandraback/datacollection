#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;



string st;

int main()
{
    freopen("00.in","r",stdin);
    freopen("0.out","w",stdout);
    int a,b,c,d,e,x,y,z,i,t,n,m;

    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>n>>m;
        st="";
        if(n!=0)
        {

        if(n>0)
        {
            for(a=1;a<n;a++) st=st+"EW";
            st=st+"E";
        }
        else
        {
            n=n*-1;
            for(a=1;a<n;a++) st=st+"WE";
            st=st+"W";
        }
        }
        if(m!=0)
        {

        x=abs(m)/2;
        y=abs(m)%2;
        if(m>0)
        {
            for(a=1;a<=x;a++) st=st+"SNSN";
            if(y)
            {
                st=st+"SNNSSN";
            }
        }
        else
        {
            for(a=1;a<=x;a++) st=st+"NSNS";
            if(y) st=st+"NSSNNS";
        }
        }
        //x=y=0;
        for(a=0;a<st.size();a++)
        {
            b=a+1;
            if(st[a]=='E') x=x+b;
            if(st[a]=='W') x=x-b;
            if(st[a]=='N') y=y+b;
            if(st[a]=='S') y=y-b;
        }
        cout<<"Case #"<<i<<": "<<st<<endl;
        //if(n!=x && y!=m) cout<<"ERROR"<<endl;
    }

    return 0;
}
