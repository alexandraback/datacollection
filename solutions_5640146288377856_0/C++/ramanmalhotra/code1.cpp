#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,r,c,w,i;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> r >> c >> w;
        cout <<"Case #" << i << ": " << r*(c-1)/w + w<< endl;
    }
    return 0;
}
