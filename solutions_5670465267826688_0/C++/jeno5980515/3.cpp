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
    map <string, map<string,string> > m ;
    m["1"]["1"] = "1" ;
    m["1"]["i"] = "i" ;
    m["1"]["j"] = "j" ;
    m["1"]["k"] = "k" ;
    m["i"]["1"] = "i" ;
    m["i"]["i"] = "-1" ;
    m["i"]["j"] = "k" ;
    m["i"]["k"] = "-j" ;
    m["j"]["1"] = "j" ;
    m["j"]["i"] = "-k" ;
    m["j"]["j"] = "-1" ;
    m["j"]["k"] = "i" ;
    m["k"]["1"] = "k" ;
    m["k"]["i"] = "j" ;
    m["k"]["j"] = "-i" ;
    m["k"]["k"] = "-1" ;
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        if ( n2 > 0 )
            fout << endl ;
        int number1 , number2  ;
        string input ;
        fin >> number1 >> number2 ;
        fin >> input ;
        string s = input ;
        for ( int i = 0 ; i < number2 - 1; i ++ )
            s+=input ;
        bool neg = false ;
        bool a = false  , b = false  , c = false ;
        string s2 = "" ;
        s2 += s.at(0) ;
        if ( s2 == "i" )
            a = true ;
        bool result = false ;
        for ( int i = 1 ; i < s.length()  ; i ++ ){
            string s3 = "" ;
            s3 += s.at(i) ;
            s2 = m[s2][s3] ;
            if ( s2 == "-1" && a == true && b == true ){
                if ( i == s.length() - 1 && neg == false )
                    result = true ;
                c = true ;
            }
            if ( s2.length() > 1 ){
                s3 = "" ;
                s3 += s2.at(1) ;
                s2 = s3 ;
                if ( neg == false )
                    neg = true ;
                else
                    neg = false ;
            }
            if ( s2 == "i" ){
                a = true ;
                //b = false ;
                //c = false ;
            }
            if ( s2 == "k" && a == true ){
                b = true ;
                //c = false ;
            }

        }
        fout << "Case #" << n2 + 1 << ": "  ;
        if ( result == true )
            fout << "YES" ;
        else
            fout << "NO" ;
    }
    return 0;
}
