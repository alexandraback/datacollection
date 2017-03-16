#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "KRLevel.h"

using namespace std ;

int canO (vector <KRLevel>, int) ;
int canT (vector <KRLevel>, int) ;

int main()
{

    //Area for holding global variables
    int testCases ;
    int runs = 0 ;


    //Code used to input the file for testing
    ifstream inputFile ;
    string filename ;

    cout << "What is the name of the inputfile?: " ;
    getline(cin,filename) ;
    cout << endl ;
    inputFile.open(filename.c_str()) ;

    //Code used to write out the correpsonding file
    ofstream outputFile ;

    cout << "What would you like to name the output file?: " ;
    getline(cin,filename) ;
    cout << endl ;
    outputFile.open(filename.c_str()) ;

    inputFile >> testCases ;

    while (runs < testCases)
    {
        int numL ;
        inputFile >> numL ;

        vector<KRLevel> levels ;
        bool done = false ;
        int plays = 0 ;
        int stars = 0 ;
        int result = 0 ;

        for (int i = 0 ; i < numL ; i++)
        {
            int o ;
            int t ;
            inputFile >> o ;
            inputFile >> t ;
            KRLevel curr = KRLevel(o, t, i) ;

            levels.push_back(curr) ;
        }

        while (!done)
        {
            int oR = 0 ;
            int tR = 0 ;

            tR = canT(levels, stars) ;

            if (tR != -99)
            {
                levels[tR].clear() ;
                plays ++ ;

                if (levels[tR].uO())
                {
                    stars += 1 ;
                }

                else
                {
                    stars += 2 ;
                }

            }

            else
            {
                oR = canO(levels, stars) ;

                if (oR != -99)
                {
                    stars += 1 ;
                    levels[oR].oClear() ;
                    plays ++ ;
                }
            }

            if(oR == -99 && tR == -99)
            {
                done = true ;
            }
        }

        bool clear = true ;
        int level = 0 ;

        while (clear && (level < numL))
        {
            clear = levels[level].isClear() ;
            level ++ ;
        }

        if (!clear)
        {
            result = 2 ;
        }


        if (result == 2)
        {
            outputFile << "Case #" << (runs + 1) << ": " << "Too Bad" << endl ;
        }

        else
        {
            outputFile << "Case #" << (runs + 1) << ": " << plays << endl ;
        }

        runs ++ ;
    }

    inputFile.close() ;
    outputFile.close() ;
    return 0 ;
}

int canO (vector<KRLevel> levels, int stars)
{
    int loopSet = levels.size() ;
    vector <KRLevel> can ;
    KRLevel curr ;

    for (int i = 0 ; i < loopSet ; i++)
    {
        if ((levels[i].getO() <= stars) && (levels[i].isClear() == false) && (levels[i].uO() == false ))
        {
            can.push_back(levels[i]) ;
        }
    }

    if (can.size() != 0)
    {
        curr = can[0] ;
        for (int i = 1 ; i < can.size() ; i++)
        {
            if (can[i].getT() > curr.getT())
            {
                curr = can[i] ;
            }
        }
    }

    else
    {
        return -99 ;
    }

    return (curr.getP()) ;
}

int canT (vector<KRLevel> levels, int stars)
{
    int loopSet = levels.size() ;
    vector <KRLevel> can ;


    for (int i = 0 ; i < loopSet ; i++)
    {
        if ((levels[i].getT() <= stars) && (levels[i].isClear() == false))
        {
            can.push_back(levels[i]) ;
        }
    }

    if (can.size() != 0)
    {
        return can[0].getP() ;
    }

    else
    {
        return -99 ;
    }

}
