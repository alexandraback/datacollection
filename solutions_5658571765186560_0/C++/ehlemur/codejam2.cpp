#include <bits/stdc++.h>

int main ( void ) {

    int tc, t, x, r, c;

    std::cin >> t;

    for ( tc = 1 ; tc <= t ; ++ tc ) {
        std::cin >> x >> r >> c;

        std::cout << "Case #" << tc << ": ";
        if ( x == 1 ) {
            std::cout << "GABRIEL\n";
        }
        else if ( x == 2 ) {
            std::cout << (((r * c) & 1) ? "RICHARD\n" : "GABRIEL\n");
        }
        else if ( x == 3 ) {
            if ( (r * c) % 3 == 0 ) {
                if ( r % 3 == 0 ) {
                    std::cout << ((c >= 2) ? "GABRIEL\n" : "RICHARD\n");
                }
                else {
                    std::cout << ((r >= 2) ? "GABRIEL\n" : "RICHARD\n");
                }
            }
            else {
                std::cout << "RICHARD\n";
            }
        }
        else if ( x == 4 ) {
            if ( (r * c) & 3 ) {
                std::cout << "RICHARD\n";
            }
            else {
                if ( r > c ) {
                    std::swap(r, c);
                }
                if ( (r * c) == 4 ) {
                    std::cout << "RICHARD\n";
                }
                else if ( (r * c) == 8 ) { // 8 x 1 = RICHARD , 4 x 2 = RICHARD (because of T)
                    std::cout << "RICHARD\n";
                }
                else if ( (r * c) == 12 ) { // 12 x 1 = RICHARD , 6 x 2 = RICHARD (because of T) , 4 x 3 = GABRIEL
                    if ( r == 1 || r == 2 ) {
                        std::cout << "RICHARD\n";
                    }
                    else {
                        std::cout << "GABRIEL\n";
                    }
                }
                else if ( (r * c) == 16 ) { // 16 x 1 = RICHARD , 8 x 2 = RICHARD (because of T), 4 x 4 = GABRIEL
                    if ( r == 1 || r == 2 ) {
                        std::cout << "RICHARD\n";
                    }
                    else {
                        std::cout << "GABRIEL\n";
                    }
                }
            }
        }
    }


    return 0;
}
