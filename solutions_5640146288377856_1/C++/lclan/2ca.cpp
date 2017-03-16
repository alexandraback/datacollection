#include<iostream>
using namespace std;
int main()
{
    int t,r,c,w;
    cin>>t;
    int s=1;
    while(t--)
    {
        cin>>r>>c>>w;
        int x=0;
        if(c%w>0)
        {
            x=1;
        }
        cout<<"Case #"<<s<<": "<<(c/w)*r+(w-1)+x<<endl;
        s++;
    }
}
