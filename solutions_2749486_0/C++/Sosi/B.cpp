#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    //freopen("B.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T; cin>>T;
    for(int t=1; t<=T; t++)
    {
        string ret="";
        int X,Y; cin>>X>>Y;
        if(X < 0)
        {
            for(int i=0; i<-X; i++)
            {
                ret += "EW";
            }
        }else
        {
            for(int i=0; i<X; i++)
                ret += "WE";
        }
        if(Y < 0)
        {
            for(int i=0; i<-Y; i++)
            {
                ret += "NS";
            }
        }else
        {
            for(int i=0; i<Y; i++)
            {
                ret += "SN";
            }
        }
        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
}
