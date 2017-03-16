
#include <iostream>

void dumpAllCombinations(int J, int P, int S)
{
    for ( int i = 0 ; i < J*P*S ; ++i ) {
        int jnum = i % J;
        int pnum = (i / J) % P;
        int snum = ((i / J) / P) % S;
        std::cout<< jnum+1 << ' ' << pnum+1 << ' ' << snum+1 << '\n';
    }
}

void dumpCombinationsBoundedByK(int J, int P, int K)
{
    for ( int jnum = 0 ; jnum < J ; ++jnum ) {
        for ( int pnum = 0 ; pnum < P ; ++pnum ) {
            int offset = jnum + pnum;
            for ( int step = 0 ; step < K ; ++step ) {

                int snum = (offset + step) % P;
                std::cout<< jnum+1 << ' ' << pnum+1 << ' ' << snum+1 << '\n';
            }
        }
    }
}


int main()
{
    int T;
    std::cin >> T;

    int J,P,S,K;
    for ( int casenum = 1 ; casenum <= T ; ++casenum ) {

        std::cin >> J >> P >> S >> K;

        // I think the best I can do is J * P * min(S,K).

        if ( S <= K ) {
            std::cout << "Case #" << casenum << ": " << J*P*S << '\n';
            dumpAllCombinations( J , P , S );
        } else {
            std::cout << "Case #" << casenum << ": " << J*P*K << '\n';
            dumpCombinationsBoundedByK( J , P , K );
        }
    }

    return 0;
}
