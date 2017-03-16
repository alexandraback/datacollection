#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define uint unsigned int


inline void func()
{
    int r,c,w;
    cin>>r>>c>>w;
    if(w==1 || w==c || w==c-1)
        cout<<c<<endl;
    else if(w==c-2)
        cout<<w+1<<endl;
    else
    {
        if(c==5 || c==6 )
            cout<<4<<endl;
        else if(c==7)
            cout<<5<<endl;
        else if(c==8)
        {
            if(w==5)
                cout<<6<<endl;
            else 
                cout<<5<<endl;
        }
        else if(c==9)
        {
            if(w==3)
                cout<<5<<endl;
            else if(w==6)
                cout<<7<<endl;
            else
                cout<<6<<endl;
        }
        else
        {
            if(w==6 || w==7)
                cout<<w+1<<endl;
            else
                cout<<6<<endl;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++)
    {
        cout<<"Case #"<<tc+1<<": ";
        func();
    }
}
