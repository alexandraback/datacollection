#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream bef("b.in") ;
    ofstream kif("b.out") ;
    int db ;
    bef >> db >> ws ;

    for (int testcase = 1; testcase <= db; testcase++)
    {
        int n, s, p ;
        bef >> n ;
        bef >> s ;
        bef >> p ;

        int biztos = 0 ;
        int nembiztos = 0;
        for (int i = 0; i < n; ++i)
        {
            int k ;
            bef >> k ;
            switch (k % 3)
            {
                case 0:
                {
                    if (k/3 >= p) biztos++ ;
                    else if (k/3+1 >= p && k/3-1>=0 && k/3+1<=10) nembiztos++ ;
                    break ;
                }
                case 1:
                {
                    if (k/3+1 >= p && k/3+1<=10) biztos++ ;
                    break ;
                }
                case 2:
                {
                    if (k/3+1 >= p && k/3+1<=10) biztos++ ;
                    else if (k/3+2 >= p && k/3+2<=10) nembiztos++ ;
                }
            }
        }
        int ered = biztos + min(nembiztos, s) ;
        kif << "Case #" << testcase << ": " << ered << endl ;
    }

}
