#include <bits/stdc++.h>
#define mp make_pair
#define ll long long

using namespace std;

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int t;
    cin >> t;
    int a = 1;
    while(a <= t)
    {
        int r , c  , w;
        cin >> r >> c >> w;
        int ans = c/(w) + w-1;
        if(c%w!=0)
            ans++;


        cout <<"Case #" << a++ << ": " << ans << endl;
    }
}
