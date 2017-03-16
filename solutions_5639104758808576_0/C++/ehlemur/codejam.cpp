#include <bits/stdc++.h>

int main ( void ) {
    int debt, tc, t, n, i;
    std::string s;

    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::cin >> t;

    for ( tc = 1 ; tc <= t ; ++ tc ) {
        std::cin >> n >> s;
        
        debt = 0;
        for ( i = n ; i >= 0 ; -- i ) {
            debt = std::max(i, debt - (s[i] - '0'));
        }

        std::cout << "Case #" << tc << ": " << debt << "\n";
    }

    return 0;
}
