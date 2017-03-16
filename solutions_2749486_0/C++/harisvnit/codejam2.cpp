#include<iostream>

using namespace std;

int main()
{
    int t,q,x,y,i;
    cin>>t;
    for(q=0; q<t; q++)
    {
        cin>>x>>y;
        cout<<"Case #"<<q+1<<": ";
        if(x>0)
        {
            for(i=0; i<x; i++)
            {
                cout<<"WE";
            }
        }
        else
        {
            x=x*(-1);
            for(i=0; i<x; i++)
            {
                cout<<"EW";
            }
        }
        if(y>0)
        {
            for(i=0; i<y; i++)
            {
                cout<<"SN";
            }
        }
        else
        {
            y=y*(-1);
            for(i=0; i<y; i++)
            {
                cout<<"NS";
            }
        }
        cout<<endl;

    }
    return 0;
}
