#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t, k, c, s;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> k >> c >> s;
        cout << "Case #" << tc << ": ";
        for(int i = 1; i <= k; ++i)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
