#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream bef("c.in") ;
    ofstream kif("c.out") ;
    int db ;
    bef >> db >> ws ;

    for (int testcase = 1; testcase <= db; testcase++)
    {
        int a, b ;
        bef >> a ;
        bef >> b ;
        int db = 0 ;
        int len = log10(a) + 1 ;
        int szorzo = pow(10, len-1) ;
        vector<int> voltmar(b+1, 0) ;
        for (int i = a; i <= b; i++)
        {
            int k = i ;
            for (int j = 0; j < len; ++j)
            {
                k = k / 10 + (k % 10) * szorzo ;
                if (k >= a && k <= b && i < k && voltmar[k] != i)
                {
                    db ++ ;
                    voltmar[k] = i ;
                }
            }
        }

        kif << "Case #" << testcase << ": " << db << endl ;
    }


}
