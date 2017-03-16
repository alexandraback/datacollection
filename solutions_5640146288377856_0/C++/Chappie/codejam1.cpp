#include<iostream>
using namespace std;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,r,c,w,turn;
    cin>>t;
    for(int z=0;z<t;z++)
    {
            cin>>r>>c>>w;
            turn=(c/w);
            turn=turn*r;
            if(c%w!=0)
                          turn++;
            turn=turn+w-1;
            cout<<"Case #"<<z+1<<": "<<turn<<endl;
    }
    return 0;
}         
