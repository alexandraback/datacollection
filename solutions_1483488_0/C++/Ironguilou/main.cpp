#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <set>

using namespace std;

inline int recycle(int n, int r, int nDigits)
{
    int b = (int) pow(10, nDigits - r) ;
    return n % b * pow(10, r) + n / b ;
}

inline int numDigits(int n)
{
    return (int) log10(n) + 1 ;
}

int main()
{
    int nCases ;
    cin >> nCases ;

    string s ;
    string line ;

    getline(cin, s) ;

    int A, B ;
    int nDigits ;
    set<int> recycledFound ;
    for (int i = 0 ; i < nCases ; i++)
    {
        // reading input file
        getline(cin, line) ;
        istringstream stream(line) ;

        stream >> A ;
        stream >> B ;
        nDigits = numDigits(A) ;

        int nRecycled = 0 ;
        for (int i = A ; i <= B ; i++)
        {
            recycledFound.clear() ;
            for (int r = 1 ; r < nDigits ; r++)
            {
                int recycled = recycle(i, r, nDigits) ;
                if (i < recycled && recycled <= B && numDigits(recycled) == nDigits && recycledFound.count(recycled) == 0)
                {
                    nRecycled++ ;
                }
                recycledFound.insert(recycled) ;
            }

        }

        // writing output file
        cout << "Case #" << i + 1 << ": " ;
        cout << nRecycled ;
        cout << endl ;
    }


    return 0;
}
