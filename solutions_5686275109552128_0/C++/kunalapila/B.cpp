#include<bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d",&n)

int main()
{
    int T, D, finalans, ans, a[1000];
    s(T);
    for(int i=1;i<=T;i++)
    {
        s(D);
        for(int j=0;j<D;j++)
            s(a[j]);
        finalans=1000000000;
        for(int req=1;req<=1000;req++)
        {
            ans=0;
            for(int j=0;j<D;j++)
                ans+=(a[j]-1)/req;
            ans+=req;
            finalans=min(ans, finalans);
        }
        cout<<"Case #"<<i<<": "<<finalans<<endl;
    }
}
