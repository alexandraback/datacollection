#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

typedef struct {
    //Data
    int x, y;
} CaseData;

std::string solve( CaseData data ){
    //Code
    //
    std::stringstream r;



    if( data.x > 0 ){
        for( int x_i = data.x; x_i > 0; x_i-- ){
            r << "WE";
        }
    } else {
        for( int x_i = data.x; x_i < 0; x_i++ ){
            r << "EW";
        }
    }
    if( data.y > 0 ){
        for( int y_i = data.y; y_i > 0; y_i-- ){
            r << "SN";
        }
    } else {
        for( int y_i = data.y; y_i < 0; y_i++ ){
            r << "NS";
        }
    }


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

        infile >> data.x;
        infile >> data.y;
        outfile << "Case #" << i << ": " << solve( data ) << std::endl;
    }


    return 0;
}
