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
        int ans = 0;
        for(int i = 0 ; i < r-1 ; i++)
            ans += c/w;
        ans += c/w + w-1;
        if(c%w!=0)
            ans++;


        cout <<"Case #" << a++ << ": " << ans << endl;
    }
}
