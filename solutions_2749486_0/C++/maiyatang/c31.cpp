#include<fstream>
//#include<iostream>
#include<string>
using namespace std;
ifstream cin ("temp.in");
ofstream cout ("temp.out");
int main ()
{
    int t;
    cin>>t;
    int i;
    for (i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        int x,y;
        cin>>x>>y;
        int i;
        if (x>0)
        {
                for (i=0;i<x;i++)
                    cout<<"WE";
        }
        else
        {
            for (i=0;i<-x;i++) 
                cout<<"EW";
        }
        if (y>0)
        {
                for (i=0;i<y;i++)
                    cout<<"SN";
        }
        else
        {
            for (i=0;i<-y;i++) 
                cout<<"NS";
        }
        cout<<endl;
    }
    return 0;
}
