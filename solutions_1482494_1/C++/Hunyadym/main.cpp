#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream bef("b.in") ;
    ofstream kif("b.out") ;
    int testcasedb ;
    bef >> testcasedb >> ws ;

    for (int testcase = 1; testcase <= testcasedb; testcase++)
    {
        vector<char> lista(1000, 0) ;
        vector<int> star1(1000) ;
        vector<int> star2(1000) ;

        int stars = 0 ;

        int leveldb ;
        bef >> leveldb ;


        for (int i = 0; i < leveldb; ++i)
        {
            bef >> star1[i] ;
            bef >> star2[i] ;
        }

        bool lepes = true ;
        int lepesdb = 0 ;
        while (lepes)
        {
            lepes = false ;
            lepesdb++ ;
            for (int i = 0; i < leveldb; ++i)
            {
                if (lista[i] < 2 && star2[i] <= stars)
                {
                    stars += 2-lista[i] ;
                    lista[i] = 2 ;
                    lepes = true ;
                    break ;
                }
            }
            if (!lepes)
            {
                int best = -1 ;
                for (int i = 0; i < leveldb; ++i)
                {
                    if (lista[i] < 1 && star1[i] <= stars)
                    {
                        if (best == -1 || star2[best] < star2[i])
                        {
                            best = i ;
                        }
                    }
                }
                if (best != -1)
                {
                    stars += 1 ;
                    lista[best] = 1 ;
                    lepes = true ;
                }
            }
        }
        bool ok = true ;
        for (int i = 0; i < leveldb; ++i)
        {
   //         cout << (int) lista[i] << endl  ;
            if (lista[i] != 2)
            {
                ok = false ;
                break ;
            }
        }
        if (ok)
        {
            kif << "Case #" << testcase << ": " << lepesdb - 1 << endl ;
  //          cout << "Case #" << testcase << ": " << lepesdb - 1 << endl ;
        }
        else
        {
            kif << "Case #" << testcase << ": " << "Too Bad" << endl ;
  //          cout << "Case #" << testcase << ": " << "Too Bad" << endl ;
        }


    }
}
