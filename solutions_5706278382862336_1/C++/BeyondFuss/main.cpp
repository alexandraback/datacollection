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
        long long P, Q;
        char c;

        input >> P >> c >> Q;

        long long res = Q;

        if ( P > Q )
        {
            output << "Case #" << i + 1 << ": " << "impossible" << "\n";

            continue;
        }

        while ( res )
        {
            if ( res % 2 != 0 )
                break;

            res = res / 2;
        }

        if ( P % res != 0 )
        {
            output << "Case #" << i + 1 << ": " << "impossible" << "\n";

            continue;
        }

        int gen = 1;
        long long pow = 1;

        while ( gen <= 40 )
        {
            Q = Q / 2;

            long long rem = Q / pow;

            if ( P - rem >= 0 )
                break;

            gen++;
        }

        if ( gen <= 40 )
            output << "Case #" << i + 1 << ": " << gen << "\n";
        else
            output << "Case #" << i + 1 << ": " << "impossible" << "\n";
    }

    return 0;
}
