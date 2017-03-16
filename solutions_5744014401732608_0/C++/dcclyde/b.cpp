
#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
    int N;
    std::cin >> N;

    for ( int casenum = 1 ; casenum <= N ; ++casenum ) {

        ll B;
        ll M;
        std::cin >> B >> M;

        // test: is M <= 2^(B-2)?

        ll compare = 1 << (B-2);

        if ( M > compare ) {
            std::cout<<"Case #"<<casenum<<": IMPOSSIBLE"<<std::endl;
            continue;
        }
        std::cout<<"Case #"<<casenum<<": POSSIBLE"<<std::endl;

        // find base 2 representation of M.
        std::vector<int> base2rep( B-1 );
        for ( int i = 0 ; i < base2rep.size() ; ++i )
            base2rep[ i ] = ( M >> i ) & 1;

        std::cerr << "base2rep is:";
        for ( int i = 0 ; i < base2rep.size() ; ++i )
            std::cerr<<" "<<base2rep[i];
        std::cerr<<std::endl;

        // start dumping the result.
        // first row is special:
        std::cout<<'0';
        if ( base2rep[ B-2 ] == 1 ) {
            for ( int i = 0 ; i < B-1 ; ++i )
                std::cout<<'1';
        } else {
            for ( int i = 0 ; i < B-2 ; ++i )
                std::cout<<base2rep[ B-3-i ];
            std::cout<<'0';
        }
        std::cout<<'\n';

        // remaining rows are always the same.
        for ( int row = 1 ; row < B ; ++row ) {
            for ( int col = 0 ; col <= row ; ++col )
                std::cout<<'0';
            for ( int col = row+1 ; col < B ; ++col )
                std::cout<<'1';
            std::cout<<'\n';
        }
    }

    return 0;
}
