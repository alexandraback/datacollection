#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

int ProcessCase();

const int maxCases = 50;
const int maxScore = 10;

int main()
{

    int numCases;
    cin >> numCases;

    assert( numCases > 0 && numCases <= maxCases );

    cin.ignore(1000, '\n');

    for( int i = 1; i <= numCases; ++ i )
    {
        int p = ProcessCase();

        cout << "Case #" << i << ": " << p << endl;
    }

	return 0;
}

int ProcessCase()
{
    int A;
    cin >> A;
    int B;
    cin >> B;

    assert( A <= B );

    int recycledNumberCount = 0;

    for( int m = A; m < B; ++m )
    {
        stringstream s;
        s << m;
        string sn = s.str();

        vector<int> prevRotations;

        for( int i = 0; i < sn.length(); ++i )
        {
            rotate(sn.begin(), sn.begin() + 1, sn.end() );

            if( sn.at(0) == '0' )
            {
                continue;
            }

            stringstream t(sn);
            int n;
            t >> n;

            // We've rotated in such a way that we got the original number back.
            // e.g., 1212 >> 2121 >> 1212
            // Any other rotations will just be duplicates of numbers we've already found,
            // so break out of the inner loop.
            /*if( n == m )
            {
                break;
            }*/
            if( n <= B &&
               n > m &&
               find( prevRotations.begin(), prevRotations.end(), n) == prevRotations.end() )
            {
                //cout << "( " << m << ", " << n << " )" << endl;
                ++recycledNumberCount;
            }

            prevRotations.push_back( n );
        }
    }

    cin.ignore( 1000, '\n');

    return recycledNumberCount;
}
