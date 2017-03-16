#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

typedef struct {
    //Data
    int n;
    std::string name;
} CaseData;

bool isConso( char a ){
    if( a == 'a' || a =='e' || a=='i' || a=='o' || a=='u' )
        return false;
    else 
        return true;
}

std::string solve( CaseData data ){
    //Code
    //
    std::stringstream r;

    int n = data.n;

    int consec = 0;
    std::vector<int> start_pos;
    for (int i = 0; i < data.name.size(); i++) {
        /* code */
        if( isConso(data.name[i]) ){
            ++consec;
            if( consec >= n )
                start_pos.push_back(i - n + 1 );
        }
        else {
            consec = 0;
        }
            
    }

    int ss = 0;
    for (int i = 0; i < start_pos.size(); i++) {
        /* code */
//        std::cout << "start at: " << start_pos[i] << std::endl;
        int s = start_pos[i];
        int e = s + n - 1;
        int ss_b = (i == 0 ) ? s+1 : s - start_pos[i-1];
        int ss_a = data.name.size()-e;
        ss += ss_b * ss_a;
    }
        //std::cout << "val: " << ss << std::endl;

        r << ss;

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
        infile >> data.name;
        infile >> data.n;

        outfile << "Case #" << i << ": " << solve( data ) << std::endl;
    }


    return 0;
}
