#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

int GCD(int u, int v) {
    if ( u > v )
        return 1 ;
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main()
{
    fstream fin("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        if ( n2 > 0 )
            fout << endl ;
        int x , r , c ;
        fin >> x >> r >> c ;
        int total = r * c ;
        bool result = false ;
        if ( total % x != 0 )
            result = true ;
        if ( x >= 7 )
            result = true ;
        for ( int i = 1 ; i <= x ; i ++ ){
            if ( (i > r || x - i +1 > c) && ( i > c || x - i+1 > r ) ){
                result = true ;
                break ;
            }
        }
        if ( x == 6 ){
            if ( (r == 2 && c == 6) || (r==6&&c==2) )
                result = true ;
        }
        if ( x== 5 ){
            if ( (r == 1 && c == 5) || (r==5&&c==1) )
                result = true ;
            if ( (r == 2 && c == 5) || (r==5&&c==2) )
                result = true ;
        }
        if ( x == 4 ){
            if ( (r == 2 && c == 4) || (r==4&&c==2) )
                result = true ;
            if ( (r == 1 && c == 4) || (r == 4 && c == 1) )
                result = true ;
            if ( (r == 2 && c == 2) )
                result = true ;
        }
        if ( x == 3 ){
            if ( (r == 1 && c == 3) || (r == 3 && c == 1) )
                result = true ;
        }
        if ( x == 1 )
            result = false ;
        fout << "Case #" << n2 + 1 << ": " ;
        if ( result == false )
            fout << "GABRIEL"  ;
        else
            fout << "RICHARD"  ;

    }
    return 0;
}
