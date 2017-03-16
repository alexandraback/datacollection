#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

typedef struct {
    //Data
    long long A, N;
    std::vector<long long> m;
} CaseData;

std::string solve( CaseData data ){
    //Code
    std::stringstream r;
    
    int c = 0;

    long long A = data.A;
    std::vector<long long> m = data.m;

    int removeCount = m.size();
    int addingTries = 0;
    bool firstAddAttempt = true;
    while( m.size() ){
        bool stuck = true;
        for (int i = 0; i < m.size(); i++) {
            if( m[i] < A ){
                A += m[i];
                stuck = false;
                m.erase( m.begin() + i );
                break;
            }
        }
        if( stuck ){
            removeCount = m.size();
            ++c;
            A = A + A - 1 ;
            ++addingTries;
            if( addingTries > removeCount ){
                c -= addingTries;
                c += removeCount;
                break;
            }

        } else {
            addingTries = 0;
        }
        if( c >= data.N ){
            c = data.N;
            break;
        }
    }

    r << c;

    return r.str();
}

int main(int argc, const char *argv[])
{
    if( argc != 3 ){
        std::cerr << "argument error" << std::endl;
        return -1;
    }

    std::ifstream infile( argv[1] );
    std::ofstream outfile( argv[2] );

    std::cerr << argv[1] << " -> " << argv[2] << std::endl;
   

    //Read Cases
    int numCases;
    if( infile.is_open() ){
        infile >> numCases;
    } else {
        std::cerr << "Failed to open input" << std::endl;
        return -1;
    }

    std::string garbage;
    std::getline( infile, garbage );

    for( int i = 1; i <= numCases; i++ ){
        CaseData data;
        //Populate data
        //Blah
        //

        infile >> data.A;
        infile >> data.N;
        for (int j = 0; j < data.N; j++) {
            long long s;
            infile >> s;
            data.m.push_back( s );
        }
        outfile << "Case #" << i << ": " << solve( data ) << std::endl;
    }


    return 0;
}
