// Copyright 2012, Vanya Davidenko.
// Используемая кодировка: UTF-8.

#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>



namespace {

template<class T, class TStream>
T Input(TStream& s) {
    T result;
    s >> result;
    return result;
}

}  // anonymous namespace



int main() {
    //auto& s = ::std::fstream("in.in");
    auto& s = ::std::cin;

    const size_t num_tests = Input<size_t>(s);

    for ( size_t i = 0 ; i != num_tests ; ++i ) {
        const size_t num_participants = Input<size_t>(s);
        ::std::vector<size_t> ji(num_participants);

        for ( size_t j = 0 ; j != num_participants ; ++j ) {
            ji[j] = Input<size_t>(s);
        }
        size_t sum = ::std::accumulate(ji.begin(), ji.end(), 0);
        size_t n = ji.size();
        size_t nz = n;
        size_t delta = 0;

        
        for ( size_t j = 0 ; j != num_participants ; ++j ) {
            double d = 0.0;
            if ( 2*sum > ji[j] * n ) {
                d = 100.0 * ( 2*sum - delta - ji[j] * nz ) / ( sum * nz );
            }

            if ( d == 0.0 ) {
                nz--;
                delta += ji[j];

            }
        }
        

        ::std::cout << "Case #"  << ( i + 1 ) << ": ";
        for ( size_t j = 0 ; j != num_participants ; ++j ) {
            double d = 0.0;
            if ( 2*sum > ji[j] * n ) {
                d = 100.0 * ( 2*sum - delta - ji[j] * nz ) / ( sum * nz );
            }

            ::std::printf("%f ", d);
        }
        ::std::cout << ::std::endl;
    }

    //system("pause");
    return 0;
}