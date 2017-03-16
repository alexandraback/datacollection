#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream bef("a.in") ;
    ofstream kif("a.out") ;
    int testcasedb ;
    bef >> testcasedb >> ws ;

    for (int testcase = 1; testcase <= testcasedb; testcase++)
    {
        int eddig, teljes ;
        bef >> eddig >> teljes ;
        double prob = 1 ;

        double min = teljes + 2 ; // Újrakezdjük

        // Visszatörlünk vagy nem törlünk
        for (int i = 1; i <= eddig; ++i)
        {
            double p ;
            bef >> p ;
            prob = prob * p ;

            double expected = prob * (teljes + eddig - 2 * i + 1) + (1-prob) * (teljes + eddig - 2 * i + teljes + 2);
            if (min > expected) min = expected ;
        }
        kif.precision(10);
        kif << "Case #" << testcase << ": " << min << endl ;
    }
}
