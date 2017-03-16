#include <iostream>
#include <stdio.h>
using namespace std;
string s1="EW";
string s2="WE";
string s3="NS";
string s4="SN";
int main()
{
    int t,X,Y;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        string ans="";
        scanf("%d%d",&X,&Y);
        if(X>0)
        {
            while(X--)
                ans+=s2;
        }
        else
        {
            while(X++)
                ans+=s1;
        }
        if(Y>0)
        {
            while(Y--)
                ans+=s4;
        }
        else
        {
            while(Y++)
                ans+=s3;
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}