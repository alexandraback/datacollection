#include <iostream>
#include <limits>
#include <vector>

typedef std::pair<long,long> longpair;
typedef std::vector<longpair> prodline;

long run_factory( prodline& lineA , long slotA , long used_in_slotA
                , prodline& lineB , long slotB , long used_in_slotB)
{
    long total = 0;

    if( lineA[slotA].second == lineB[slotB].second )
    {

        total = std::min( lineA[slotA].first-used_in_slotA
                        , lineB[slotB].first-used_in_slotB );
        used_in_slotA += total;
        used_in_slotB += total;

        if( used_in_slotA >= lineA[slotA].first )
        {
            used_in_slotA = 0;
            slotA++;
        }

        if( used_in_slotB >= lineB[slotB].first )
        {
            used_in_slotB = 0;
            slotB++;
        }
    }

    long best_total = 0;
    for( unsigned int start_a=slotA ; start_a<lineA.size() ; ++start_a )
    for( unsigned int start_b=slotB ; start_b<lineB.size() ; ++start_b )
    {
        if( start_a != slotA ) { used_in_slotA = 0; }
        if( start_b != slotB ) { used_in_slotB = 0; }

        if( lineA[start_a].second == lineB[start_b].second )
        {
            long this_total = run_factory( lineA , start_a , used_in_slotA,
                                           lineB , start_b , used_in_slotB );
            if( this_total > best_total )
            {
                best_total = this_total;
            }
        }
    }
    total += best_total;

    return total;
}

int main()
{
    int N;
    std::cin >> N;
    ++N;//test cases are indexed from 1

    //now ingore the rest of the line inc newline, eases some tests that
	//try to read a line at a time (and stick on this \n if not removed)
    std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n' );

    for( int test_case=1 ; test_case<N ; ++test_case )
    {
    //Prep
        long size_a,size_b;
        std::cin >> size_a >> size_b;

        std::vector< longpair > lineA;
        for( int entry=0 ; entry<size_a ; ++entry )
        {
            long count,type;
            std::cin >> count;
            std::cin >> type;
            lineA.push_back( longpair(count,type));
        }

        std::vector< longpair > lineB;
        for( int entry=0 ; entry<size_b ; ++entry )
        {
            int count,type;
            std::cin >> count;
            std::cin >> type;
            lineB.push_back( longpair(count,type));
        }

    //Work
        long result = run_factory( lineA , 0 , 0 , lineB , 0 , 0 );

    //Result
        std::cout << "Case #" << test_case << ": " << result << std::endl;

    //Clean Up
    }
}
