#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    fstream fin("in.txt",ios::in) ;
    fstream fout("out.txt",ios::out) ;
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        int r , c , w ;
        fin >> r >> c >> w ;
        int total = 0 ;
        total += r * ( c / w )  ;
        if ( c % w == 0 )
            total += w - 1 ;
        else
            total += w  ;
        fout << "Case #" << n2 + 1 << ": " << total <<endl ;
    }
    return 0;
}
