#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

//#define out cout

int main()
{
    int t;in>>t;
    for(int i=0;i<t;++i)
    {
        int r,c,w;in>>r>>c>>w;
        int ans=r*(c/w);
        int rem=c%w;
        if(rem==0)ans+=w-1;
        else ans+=w;
        out<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}
