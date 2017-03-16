#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;
int n,x,s1,l1,t1,s2,l2,t2;
int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        cin>>n;
        if(n==1)
            {
                cin>>l1>>x>>s1;
                l2=l1;
                s2=s1+1;
            }
        else
            cin>>l1>>x>>s1>>l2>>x>>s2;
        t1=(360-l1)/360*s1;
        t2=(360-l2)/360*s2;
        if(t1>t2)
        {
            if(t1<t2+l2)
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
        else
        {
            if(t2<t1+l1)
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
    }
    return 0;
}
