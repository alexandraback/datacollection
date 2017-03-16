// A

#include <iostream>
#include <fstream>
using namespace std;

int r, c, w;

int main()
{
    ifstream fin ("A-small-attempt1.in");
    ofstream fout ("A-small.txt");
    int t;
    fin >> t;
    for ( int h = 0; h < t; h++ )
    {
        fout << "Case #" << h + 1 << ": ";
        fin >> r >> c >> w;
        if ( c % w == 0 )
        {
            fout << ( c / w ) * ( r - 1 ) + w + ( c / w - 1 ) << endl;
        }
        else
        {
            fout << ( c / w ) * ( r - 1 ) + w + ( c / w ) << endl;
        }
    }
    return 0;
}
