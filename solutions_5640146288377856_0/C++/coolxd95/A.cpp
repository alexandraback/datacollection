#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("test", "r", stdin);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int testCases;
    cin>>testCases;
    for(int testcase=0;testcase<testCases;testcase++)
    {
        int r,c,w,t=0;
        cin>>r>>c>>w;
        t=r*(c/w);
        t+=w;
        if(c%w==0)
            t-=1;
        cout<<"Case #"<<testcase+1<<": "<<t<<endl;
    }
    return 0;
}
