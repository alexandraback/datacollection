#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    string fileName = "C-small-attempt1";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    int currentCase=0;

    ifstream fileIn(fileInName.c_str());
    ofstream fileOut(fileOutName.c_str());;

    if ( ! fileIn.is_open() )
    {
        cout << "File " << fileInName << " not found";
        return 1;
    }

    // number of cases
    getline (fileIn,line);
    int T = atoi(line.c_str());
    cout << "T=" << T << endl;

    // for each case
    while ( fileIn.good() and currentCase < T)
    {
        ++currentCase;
        cout << "----- Case #"<<currentCase<<" -----"<<endl;

        getline (fileIn,line);
        int N = atoi(line.c_str());

//        getline (fileIn,line);
//        stringstream stream(line);

        int* di = new int[N](); // day first attack
        int* ni = new int[N](); // number of attacks
        int* wi = new int[N](); // position w of first attack
        int* ei = new int[N](); // position e of first attack
        int* si = new int[N](); // strength
        int* delta_di = new int[N](); // attack every X days
        int* delta_pi = new int[N](); // move between each attack (+east, -west)
        int* delta_si = new int[N](); // change strength

        cout <<"N:"<<N<<endl;

        for(int i=0;i<N;i++)
        {
//            cout <<"Reading tribe "<<i<<endl;
            getline (fileIn,line);
            stringstream stream(line);
            stream >> di[i] >> ni[i] >> wi[i] >> ei[i] >> si[i] >> delta_di[i] >> delta_pi[i] >> delta_si[i];
//            cout << "i "<<i << " di[i]" << di[i] <<" ni[i]" << ni[i] << " wi[i]" << wi[i] << " ei[i]" << ei[i] << " si[i]" << si[i] << " delta_di[i]" << delta_di[i] << " delta_pi[i]" << delta_pi[i] <<endl;
        }

        vector<int> wall (1000,0);
        int middle = 500;

        int day = 0;
        int successfulAttackCount = 0;


        while(true)
        {
            vector<int> newWall (wall);
            bool toContinue = false;
            for(int i=0;i<N;i++)
            {
//                cout << "i "<<i << "ni[i]" << ni[i] << "si[i]" << si[i] <<endl;
                if(ni[i] > 0 &&  si[i] > 0)
                {
//                    cout << "continue"<<endl;
                    toContinue = true;
                    break;
                }
            }
            if(! toContinue)
                break;

            cout << "Day "<<day<<endl;



            for(int i=0;i<N;i++)
            {
                // attack
                if(ni[i] > 0 && di[i] == day && si[i]>0)
                {
                    cout << "Tribe "<<i<<" attack on day "<<day<<" on interval "<<wi[i]<<":"<<ei[i]<<endl;

                    // check we are not out of the wall

                    // check if attack successful
                    bool successfulAttack = false;
                    for(int x=wi[i]+middle; x<ei[i]+middle; x++)
                    {
                        if(wall[x] < si[i])
                        {
                            // attack successful
                            successfulAttack = true;
                        }
                        if(newWall[x] < si[i])
                        {
                            newWall[x] = si[i];
                        }
                    }
                    if(successfulAttack)
                    {
                        cout << "Attack successful"<<endl;
                        successfulAttackCount++;
                    }

                    wi[i] += delta_pi[i];
                    ei[i] += delta_pi[i];

                    si[i] += delta_si[i];
                    di[i] += delta_di[i];
                    ni[i]--;
                }
            }

            wall = newWall;


            int next_day = 1000000;
            for(int i=0;i<N;i++)
            {
                if(ni[i] > 0 && si[i]>0 && di[i] < next_day)
                    next_day = di[i];
            }
            day = next_day;


        }

        all_done:

//        vector<int> wallE (1000,0);


//        stream >> L >> D >> N;
//        cout << "L " << L << " D " << D << " N " << N << endl;

//        for (int i=0;i<X;i++)
//        {
//        }


        cout << "Case #"<<currentCase<<": "<<successfulAttackCount<<endl;
        fileOut << "Case #"<<currentCase<<": "<<successfulAttackCount<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
