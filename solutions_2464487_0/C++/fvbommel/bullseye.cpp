#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

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
        int t, r;
        input >> r >> t;
        cout << "# " << r << " " << t << endl;
        
        //~ cout << "Case #" << (i+1) << ": ";
        output << "Case #" << (i+1) << ": ";
        
        int paint_left = t;
        int radius = r;
        int rings = 0;
        for (int j = 0; paint_left >= 2*radius + 1; j++)
        {
            paint_left -= 2*radius + 1;
            radius += 2;
            rings++;
        }
        output << rings << '\n';
        
        cout << "Success!\n";
        cout << "Case #" << (i+1) << ": " << ' ';
        cout << rings;
        cout << endl;
    }
    
    cout << endl;
}