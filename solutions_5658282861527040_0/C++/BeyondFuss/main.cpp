#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void error( const char *str)
{
    cout << str;

    exit( 1);
}

int main()
{
    ifstream input( "input.txt");

    if ( !input )
        error( "Cannot open input file");

    ofstream output( "output.txt");

    if ( !output )
        error( "Cannot open output file");

    int num_cases;

    input >> num_cases;

    for ( int i = 0; i < num_cases; i++ )
    {
        int A, B, K;

        input >> A >> B >> K;

        long long count = 0;

        for ( int j = 0; j < A; j++ )
            for ( int k = 0; k < B; k++ )
                if ( (j & k) < K )
                    count++;

        output << "Case #" << i + 1 << ": " << count << "\n";
    }

    return 0;
}
