// D - Ominous Omino

#include <iostream>
#include <fstream>
using namespace std;

int x, r, c;

int main()
{
    ifstream fin ( "D-small-attempt0.in" );
    ofstream fout ( "D-small.txt" );
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> x >> r >> c;
        if ( ( r * c ) % x != 0 )
        {
            fout << "Case #" << h << ": RICHARD" << endl;
            continue;
        }
        if ( x == 1 || x == 2 )
        {
            fout << "Case #" << h << ": GABRIEL" << endl;
            continue;
        }
        if ( x == 3 )
        {
            if ( r == 1 || c == 1 ) fout << "Case #" << h << ": RICHARD" << endl;
            else fout << "Case #" << h << ": GABRIEL" << endl;
            continue;
        }
        if ( x == 4 )
        {
            if ( r <= 2 || c <= 2 ) fout << "Case #" << h << ": RICHARD" << endl;
            else fout << "Case #" << h << ": GABRIEL" << endl;
            continue;
        }
    }
    return 0;
}
