#include <bits/stdc++.h>

int main ( void ) {
    
    std::multiset<int> pancakes;
    int best_time, tc, t, d, p, i;


    std::cin >> t;

    for ( tc = 1 ; tc <= t ; ++ tc ) {
        std::cin >> d;
        pancakes.clear();
        for ( i = 0 ; i < d ; ++ i ) {
            std::cin >> p;
            pancakes.insert(-p);
        }

        i = 0;
        best_time = INT_MAX;
        while ( !pancakes.empty() ) {
            p = - (*pancakes.begin());
            best_time = std::min(best_time, p + i);
            if ( p == 1 ) {
                break;
            }
            ++ i;
            pancakes.insert(-(p >> 1));
            pancakes.insert(-(p - (p >> 1)));
            pancakes.erase(pancakes.begin());
        }

        std::cout << "Case #" << tc << ": " << best_time << "\n";
    }   

    return 0;
}
