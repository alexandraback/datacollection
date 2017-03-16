#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<conio.h>

using namespace std;

#define MX  100020
#define inf 2000000000
#define pi acos(-1.0)

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    int t,x,y,cc=1;

    cin>>t;

    while(t--)
    {
        cin>>x>>y;

        cout<<"Case #"<<cc++<<": ";

        if(x>0)
        {
            cout<<"E";

            for(int i=1;i<x;i++)
            {
                cout<<"WE";
            }
        }
        else if(x<0)
        {
            x = -x;
            cout<<"W";
            for(int i=1;i<x;i++)
            {
                cout<<"EW";
            }
        }

        if(y>0)
        {
            for(int i=0;i<y;i++)
            {
                cout<<"SN";
            }
        }
        else if(y<0)
        {
            y = -y;
            for(int i=0;i<y;i++)
            {
                cout<<"NS";
            }
        }

        cout<<endl;
    }



    return 0;
}
