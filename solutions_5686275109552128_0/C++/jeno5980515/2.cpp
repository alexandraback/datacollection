#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
    fstream fin("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        if ( n2 > 0 )
            fout << endl ;
        int number , max1 = 0 , array1[2000] , maxindex = 0 ;
        fin >> number ;
        int sum = 0 ;
        for ( int i = 0 , num ; i < number ; i ++ ){
            fin >> num ;
            array1[i] = num ;
            max1 = max(max1,num) ;
        }
        int min1 = max1 ;
        for ( int i = max1 - 1 ; i > 0  ; i -- ){
            int count_move = 0 ;
            double d1 = i ;
            for ( int j = 0 ; j < number ; j++ ){
                if ( array1[j] > i ){
                    double d2 = array1[j] ;
                    double result = ceil(d2/d1) ;
                    int r = (int)result ;
                    count_move += r - 1 ;
                }
            }
            min1 = min(min1,i+count_move) ;
        }
        fout << "Case #" << n2 + 1 << ": " << min1 ;
    }
    return 0;
}
