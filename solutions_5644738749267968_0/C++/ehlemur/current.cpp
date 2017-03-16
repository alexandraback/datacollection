#include <bits/stdc++.h>


double between ( const double& a , const double& b ) {
    return (a + b) / 2;
}

int ken ( const double& naomi , std::set<double>& blocks , const bool& erase = true ) {
    std::set<double>::iterator it;

    it = blocks.upper_bound(naomi);
    if ( it == blocks.end() ) {
        blocks.erase(blocks.begin());
        return 1;
    }

    if ( erase ) {
        blocks.erase(it);
    }
    return 0;
}


int main ( void ) {

    int T, N, deceitful_points, war_points, i, j, t;

    std::set<double> ken_set;
    std::deque<double> ken_deque;
    std::vector<double> ken_blocks;
    std::vector<double> naomi_blocks;

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> T;

    for ( t = 1 ; t <= T ; ++ t ) {
        std::cin >> N;

        ken_blocks.clear();
        naomi_blocks.clear();

        ken_blocks.resize(N);
        naomi_blocks.resize(N);

        deceitful_points = war_points = 0;

        for ( i = 0 ; i < N ; ++ i ) {
            std::cin >> naomi_blocks[i]; 
        }

        for ( i = 0 ; i < N ; ++ i ) {
            std::cin >> ken_blocks[i]; 
        }

        std::sort(ken_blocks.begin(), ken_blocks.end());
        std::sort(naomi_blocks.begin(), naomi_blocks.end());

        ken_set = std::set<double>(ken_blocks.begin(), ken_blocks.end());
        for ( i = 0 ; i < N ; ++ i ) {
            war_points += ken(naomi_blocks[i], ken_set);
        }

        ken_deque = std::deque<double>(ken_blocks.begin(), ken_blocks.end());
        for ( i = 0 ; i < N ; ++ i ) {
            for ( j = i ; j < N ; ++ j ) {
                if ( naomi_blocks[j] < ken_deque[j-i] ) {
                    /* BEGIN DEBUG 
                    std::cout << "processing naomi's " << naomi_blocks[i] << std::endl;
                    std::cout << "considering ken's " << ken_deque.back() << std::endl;
                    std::cout << "ken has:";
                    for ( double x : ken_deque ) {
                        std::cout << " " << x;
                    }
                    std::cout << std::endl;
                    /* END DEBUG */  

                    if ( naomi_blocks[i] < ken_deque.back() ) {
                        /* BEGIN DEBUG 
                        std::cout << "choose to decieve, +0" << std::endl;
                        /* END DEBUG */
                        ken_deque.pop_back();
                    }
                    else {
                        /* BEGIN DEBUG 
                        std::cout << "there is no greater, +1" << std::endl;
                        /* END DEBUG */
                        ++ deceitful_points;
                        ken_deque.pop_front();
                    }
                    break;
                }
            }
            if ( j == N ) {
                deceitful_points += N - i;
                break;
            }
        }

        std::cout << "Case #" << t << ": " << deceitful_points << " " << war_points << "\n";
    }

    return 0;

}
