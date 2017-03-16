#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define LL long long

using namespace std;

int T, c, n, v[10],r, e, s;

int max(int i, int E)
{
    if(i>=n-1)
    {
        return v[i]*E;
    }
    else
    {
        int res=0, a;
        for(int j=0; j<=E; ++j)
        {
            int E1 = ((E+r-j)>e)? e : (E+r-j);
            //cout<<j<<' '<<E1<<'\n';
            a=j*v[i] + max(i+1, E1);
            if(a>res)
                res=a;
        }
        return res;
    }
}
int main()
{
    cin>>T;
    c=1;
    int i;
    while(T--)
    {
        cout<<"Case #"<<c++<<": ";
        cin>>e>>r>>n;
        for(i=0; i<n; ++i)
            cin>>v[i];
        cout<<max(0,e)<<'\n';
    }
    return 0;
}
