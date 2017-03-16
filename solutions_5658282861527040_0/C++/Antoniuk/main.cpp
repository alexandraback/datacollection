#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int T = 0 ; T < t ; ++T)
    {
        int a, b, k;
        int ans = 0;
        cin >> a >> b >> k;
        for(int a1 = 0 ; a1 < a ; ++a1)
            for(int b1 = 0 ; b1 < b ; ++b1)
            if((a1&b1) < k)
                ++ans;
        
        cout << "Case #" << T+1 << ": ";
        
        cout << ans << "\n";
    }
    return 0;
}




