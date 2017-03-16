#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

bool isVowel[26] =
{
    1, 0, 0, 0, 1,  // a b c d e
    0, 0, 0, 1, 0,  // f g h i j
    0, 0, 0, 0, 1,  // k l m n o
    0, 0, 0, 0, 0,  // p q r s t
    1, 0, 0, 0, 0,  // u v w x y
    0               // z
};

int main( int argc, const char** argv ) {
    const char* filename = "sample.in";
    if (argc >= 2)
        filename = argv[ 1 ];
    
    ifstream input( filename );
    ofstream output( (string(filename) + ".out").c_str() );
    
    int T;
    input >> T;
    cout << T << endl;
    
    for (int i = 0 ; i < T ; i++)
    {
        string name;
        int N;
        input >> name >> N;
        size_t L = name.size();
        
        //~ cout << "\n# " << name << " " << N << endl;
        //~ memset( PTR, 0, sizeof(PTR)*N);
        
        //~ cout << "Case #" << (i+1) << ": ";
        output << "Case #" << (i+1) << ": ";
        
        size_t lastEnd = 0;
        size_t trailing = 0;
        long long result = 0;
        
        for( size_t j = 0 ; j < L ; j++ )
        {
            if( isVowel[ name[ j ] - 'a' ] )
            {
                if( trailing >= N )
                {
                    //~ lastEnd = j;
                }
                trailing = 0;
            }
            else
            {
                trailing++;
                
                if( trailing >= N )
                {
                    cout << lastEnd << '\t' << j << '\n';
                    size_t s = j + 1- N;
                    
                    size_t n_prefixes = (s - lastEnd + 1);
                    size_t n_postfixes = (L - j);
                    
                    result += n_prefixes * n_postfixes;
                    
                    lastEnd = s+1;
                }
            }
        }
        
        
        output << result << '\n';
        
        cout << "Success!\n";
        //~ cout << "Case #" << (i+1) << ": " << ' ' << result << endl;
    }
    
    //~ cout << endl;
}