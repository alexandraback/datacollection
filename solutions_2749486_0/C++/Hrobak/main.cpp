#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <utility>
#include <fstream>
using namespace std;



string GET(int a,int b)
{
    string r="";
    int c=1;
    if(a>0)
    {
        int p=0;
        int co=1;
        while(p!=a)
        {
            if(co%2==1)
            {
                r+="W";
                p-=co;
            }
            else
            {
                r+="E";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    else
    {
        int p=0;
        int co=1;
        while(p!=a)
        {
            if(co%2!=1)
            {
                r+="W";
                p-=co;
            }
            else
            {
                r+="E";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    if(b>0)
    {
        int p=0;
        int co=1;
        while(p!=b)
        {
            if(co%2==1)
            {
                r+="S";
                p-=co;
            }
            else
            {
                r+="N";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    else
    {
        int p=0;
        int co=1;
        while(p!=b)
        {
            if(co%2!=1)
            {
                r+="S";
                p-=co;
            }
            else
            {
                r+="N";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    return r;
}





int main()
{
    ifstream cin ("/home/misha/iuuu.in");
    ofstream cout ("/home/misha/ouou");
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        int a,b;
        cin>>a>>b;
        string S=GET(a,b);
        cout<<"Case #"<<i<<": "<<S<<endl;
    }
    //cout<<S.length()<<endl;
    return 0;
}
