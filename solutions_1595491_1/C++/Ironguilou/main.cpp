#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int nCases ;
    cin >> nCases ;

    string s ;
    string line ;

    getline(cin, s) ;
    for (int i = 0 ; i < nCases ; i++)
    {
        // reading input file
        getline(cin, line) ;
        istringstream stream(line) ;

        int nNonSuprising = 0 ;
        int nSurprising = 0 ;

        int N, S, p, t ;
        stream >> N ;
        stream >> S ;
        stream >> p ;
        for (int i = 0 ; i < N ; i++)
        {
            stream >> t ;
            if (t >= 3 * p - 2)
                nNonSuprising++ ;
            else if (p >= 2 && t >= 3 * p - 4)
                nSurprising++ ;
        }

        // writing output file
        cout << "Case #" << i + 1 << ": " ;
        cout << nNonSuprising + min(nSurprising, S) ;
        cout << endl ;
    }


    return 0;
}
