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

int* chests_opening_key; // [N]
int** chests_contains_keys; // [N][201]
int* solution; // [N]
int depth;
int K, N;
int* keys;
bool* chests_opened;

bool global_all_opened;
//bool global_impossible;

int* available_keys;
bool* chests_opened2;

int currentCase;

bool possible()
{
    for(int j=0;j<201;j++)
    {
        available_keys[j] = keys[j];
    }

    for(int i=0;i<N;i++)
    {
        if(chests_opened[i] == false)
        {
            available_keys[chests_opening_key[i]]--;

            for(int j=0;j<201;j++)
            {
                available_keys[j] += chests_contains_keys[i][j];
            }
        }
    }

    for(int j=0;j<201;j++)
    {
        if(available_keys[j]<0)
            return false;
    }


    // smarter heuristic

    for(int j=0;j<201;j++)
    {
        available_keys[j] = keys[j];
    }

    for(int i=0;i<N;i++)
    {
        chests_opened2[i] = chests_opened[i];
    }

    bool incrementing = true;
    while(incrementing)
    {
        incrementing = false;
        for(int i=0;i<N;i++)
        {
            if(chests_opened2[i] == false)
            {
                if( available_keys[chests_opening_key[i]] > 0)
                {
                    chests_opened2[i] = true;
                    incrementing = true;
//                    available_keys[chests_opening_key[i]]--;

                    for(int j=0;j<201;j++)
                    {
                        available_keys[j] += chests_contains_keys[i][j];
                    }
                }
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        if(chests_opened2[i] == false)
        {
            cout << "Heuristic 2 filter" << endl;
            return false;
        }

    }

    return true;
}

void solve()
{
    bool all_opened = true;
    bool impossible = true;

    cout <<currentCase<<" solution=";
    for(int i=0;i<depth;i++)
    {
        cout << " " << solution[i]+1;
    }
    cout << endl;

    for(int i=0;i<N;i++)
//    for(int i=N-1;i>=0;i--)
    {
//        cout << "depth="<<depth << " i="<<i<<" solution=";

        if(chests_opened[i] == false)
        {
            all_opened = false;
//            cout << i <<" is not open " << endl;

            if( keys[chests_opening_key[i]] > 0)
            {
//                cout << " and we have the key " << endl;
                impossible = false;

                for(int j=0;j<201;j++)
                {
                    keys[j] += chests_contains_keys[i][j];
                }
                chests_opened[i] = true;
                keys[chests_opening_key[i]]--;

                solution[depth] = i;
                depth++;

                if(possible())
                    solve();
                else
                    cout << "CUT" << endl;

                if(global_all_opened)
                    return;

                depth--;
                chests_opened[i] = false;
                keys[chests_opening_key[i]]++;
                for(int j=0;j<201;j++)
                {
                    keys[j] -= chests_contains_keys[i][j];
                }

            }
//            else
//                cout << " and we DONT have the key " << endl;
        }
    }

    if(all_opened == true)
    {
        global_all_opened = true;

    }
    else if(impossible)
    {
//        cout << "IMPOSSIBLE!"<<endl;
    }
}

int main()
{
    string fileName = "D-small-attempt1";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    currentCase=0;

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

        stringstream stream(line);
//        int K, N;
        stream >> K >> N;
        cout << "K " << K << " N " << N << endl;

        // line containing K keys
        getline (fileIn,line);
        stringstream stream2(line);
        keys = new int[201]();
        for(int i=0;i<K;i++)
        {
            int key;
            stream2 >> key;
            keys[key]++;
        }

        // N chests
        chests_opening_key = new int[N]();
        chests_contains_keys = new int*[N]();
        for(int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream3(line);
            stream3 >> chests_opening_key[i];

            int number_of_keys;
            stream3 >> number_of_keys;
            chests_contains_keys[i] = new int[201]();
            for(int j=0;j<number_of_keys;j++)
            {
                int key;
                stream3 >> key;
                chests_contains_keys[i][key]++;
            }
        }

        chests_opened = new bool[N]();
        chests_opened2 = new bool[N]();
        for(int i=0;i<N;i++)
        {
            chests_opened[i] = false;
        }

        solution = new int[N];
        depth = 0;

        available_keys = new int[201]();

        global_all_opened = false;
        solve();

        if(global_all_opened == false)
        {
            cout << "Case #"<<currentCase<<": IMPOSSIBLE"<<endl;
            fileOut << "Case #"<<currentCase<<": IMPOSSIBLE"<<endl;
        }
        else
        {
            cout << "Case #"<<currentCase<<":";
            for(int i=0;i<N;i++)
            {
                cout << " " << solution[i]+1;
            }
            cout << endl;

            fileOut << "Case #"<<currentCase<<":";
            for(int i=0;i<N;i++)
            {
                fileOut << " " << solution[i]+1;
            }
            fileOut << endl;
        }


        for(int i=0;i<N;i++)
        {
            delete[] chests_contains_keys[i];
        }
        delete[] chests_contains_keys;
        delete[] chests_opening_key;
        delete[] keys;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
