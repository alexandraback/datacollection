// D - Ominous Omino

#include <iostream>
#include <fstream>
using namespace std;

int x, r, c;

int main()
{
    ifstream fin ( "D-large.in" );
    ofstream fout ( "D-large.txt" );
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
        if ( x == 5 )
        {
            if ( r <= 2 || c <= 2 ) fout << "Case #" << h << ": RICHARD" << endl;
            else if ( ( r == 3 && c == 5 ) || ( r == 5 && c == 3 ) ) fout << "Case #" << h << ": RICHARD" << endl;
            else fout << "Case #" << h << ": GABRIEL" << endl;
            continue;
        }
        if ( x == 6 )
        {
            if ( r >= 4 && c >= 4 ) fout << "Case #" << h << ": GABRIEL" << endl;
            else fout << "Case #" << h << ": RICHARD" << endl;
            continue;
        }
        if ( x >= 7 )
        {
            fout << "Case #" << h << ": RICHARD" << endl;
            continue;
        }
    }
    return 0;
}
