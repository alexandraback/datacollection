#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}
