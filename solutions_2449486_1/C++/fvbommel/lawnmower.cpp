#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
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
    
    
    static int lawn[100][100];
    static int rowmax[100] = { 0 };
    static int colmax[100] = { 0 };
    
    for (int i = 0 ; i < T ; i++)
    {
        cout << "Case #" << (i+1) << endl;
        int N, M;
        input >> N >> M;
        if( N > 100 || M > 100 || N < 1 || M < 1 )
        {
            cerr << "INCORRECT INPUT DIMENSIONS: " << N << " x " << M << endl;
            return -1;
        }
        
        fill_n(rowmax, N, 0);
        fill_n(colmax, M, 0);
        
        for (int n = 0 ; n < N ; n++)
        {
            for (int m = 0 ; m < M; m++ )
            {
                int h;
                input >> h;
                
                rowmax[n] = max(rowmax[n], h);
                colmax[m] = max(colmax[m], h);
                cout << h << ' ';
                
                lawn[n][m] = h;
            }
            cout << '\n';
        }
        output << "Case #" << (i+1) << ": ";
        
        // The pattern is possible iff each pixel is the maximum of
        // either its row or its column.
        for (int n = 0 ; n < N ; n++)
        {
            for (int m = 0 ; m < M; m++ )
            {
                if( lawn[n][m] != rowmax[n] && lawn[n][m] != colmax[m] )
                {
                    // Not possible
                    cout << "NO: " << lawn[n][m] << ' ' << rowmax[n] << ' ' << colmax[m] << endl;
                    output << "NO\n";
                    goto next_case;
                }
            }
        }
        output << "YES\n";
next_case:;
    }
    
    cout << endl;
}