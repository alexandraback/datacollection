#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

using namespace std;

int solve(int a, int b, int k)
{
    int ans = 0;
    rep(i,a)
        rep(j,b)
            if ((i&j) < k)
                ++ans;   
    return ans;
}

int main()
{
    freopen("outB.txt", "w", stdout);
    freopen("inB.txt", "r", stdin);
    int T;
    cin >> T;
    int a,b,k;
    forr(tc,1,T)
    {
        cin >> a >> b >> k;
        cout << "Case #" << tc << ": " << solve(a,b,k) << "\n";            
    }
    
    return 0;   
}
