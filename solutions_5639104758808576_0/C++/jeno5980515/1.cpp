#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

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
        string input ;
        int number ;
        fin >> number ;
        fin >> input ;
        int count1[2000]  ;
        for ( int i = 0 ; i < number+1 ; i ++ )
            count1[i] = 0 ;
        int addnum  = 0 ;
        for ( int i = 0 ; i < number+1  ; i ++ )
            count1[i] = (int)input[i] - 48 ;
        for ( int i = 0 ; i < number  ; i ++ ){
            if ( count1[i] == 0 )
                addnum ++ ;
            else if ( count1[i] > 1 ){
                count1[i+1] += count1[i] - 1 ;
            }

        }
        fout << "Case #" << n2 + 1 << ": " << addnum ;
    }
    return 0;
}
