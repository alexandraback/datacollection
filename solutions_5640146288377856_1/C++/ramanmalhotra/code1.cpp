#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,a,b,c,w,i;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> a >> b >> c;
        cout <<"Case #" << i << ": " << (b+c-1)/c+(b*(a-1))/c+c-1<< endl;
    }
    return 0;
}
