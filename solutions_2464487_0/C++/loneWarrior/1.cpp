#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define LL long long

using namespace std;

int main()
{
    int T, c, r, t, i, j, s;
    cin>>T;
    c=1;
    while(T--)
    {
        cin>>r>>t;
        cout<<"Case #"<<c++<<": ";
        s=0;
        j=0;
        while(s<=t)
        {
           s+=(r+1)*(r+1) - r*r;
           r+=2;
           j++;
        }
        cout<<j-1<<'\n';
    }
    return 0;
}
