#include <bits/stdc++.h>

int main ( void ) {

    int tc, t, x, r, c;

    std::cin >> t;

    for ( tc = 1 ; tc <= t ; ++ tc ) {
        std::cin >> x >> r >> c;
        
        std::cout << "Case #" << tc << ": ";

        if ( x >= 7 || (r * c) % x != 0 ) { // always impossible
            std::cout << "RICHARD\n";
            continue;
        }
        if ( x == 1 || x == 2 ) { // always possible
            std::cout << "GABRIEL\n";
            continue;
        }

        if ( r > c ) {
            std::swap(r, c);
        }
        if ( r <= x - 2 ) { 
            std::cout << "RICHARD\n";
            continue;
        }

        std::cout << "GABRIEL\n";
    }


    return 0;
}
