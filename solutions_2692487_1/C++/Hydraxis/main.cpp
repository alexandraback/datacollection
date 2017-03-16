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
    string fileName = "A-large";
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
        stringstream stream(line);
        long long int player_size, N;
        stream >> player_size >> N;
        cout << "player_size " << player_size << " N " << N << endl;

        vector<long long int> motes_size;
        vector<bool> motes_eaten;

        getline (fileIn,line);
        stringstream stream2(line);
        for (int i=0;i<N;i++)
        {
            int tmp;
            stream2 >> tmp;
            motes_size.push_back(tmp);
            motes_eaten.push_back(false);
        }

        sort (motes_size.begin(), motes_size.end());

        bool eat = true;
        while(eat)
        {
            eat = false;
            for (int i=0;i<N;i++)
            {
                if(motes_eaten[i] == false && player_size > motes_size[i])
                {
                    eat = true;
                    motes_eaten[i] = true;
                    player_size += motes_size[i];
                    cout << "size: "<<player_size<<endl;
                }
            }
        }

        for (int i=0;i<N;i++)
        {
            cout << "i: "<<i<<" "<<motes_eaten[i]<<" "<<motes_size[i]<<endl;
        }

        int not_eaten=0;
        for (int i=0;i<N;i++)
        {
            if(motes_eaten[i] == false)
                    not_eaten++;
        }
        cout << "not_eaten: "<<not_eaten<<endl;

        int best_count = N;

        for(int to_remove=0;to_remove<=not_eaten;to_remove++)
        {
            vector<bool> motes_eaten_copy(motes_eaten);
            long long int player_size_copy = player_size;

//            cout << "to_remove: "<<to_remove<<endl;
            int operation_count = 0;

            for (int i=N-1;i>=N-to_remove;i--)
            {
//                cout << "i: "<<i<<endl;
                if(motes_eaten_copy[i] == false)
                {
                    motes_eaten_copy[i] = true;
                    operation_count++;
                }
                else
                    cout << "Should not happen" << endl;
            }

            bool all_found = false;
            while(all_found == false)
            {
                bool eat = true;
                while(eat)
                {
                    eat = false;
                    for (int i=0;i<N;i++)
                    {
                        if(motes_eaten_copy[i] == false && player_size_copy > motes_size[i])
                        {
                            eat = true;
                            motes_eaten_copy[i] = true;
                            player_size_copy += motes_size[i];
//                            cout << "size: "<<player_size_copy<<endl;
                        }
                    }
                }

                all_found = true;
                for (int i=0;i<N;i++)
                {
                    if(motes_eaten_copy[i] == false)
                        all_found = false;
                }

                // add a new one
                if(!all_found)
                {
                    if(player_size_copy>1)
                    {
                        player_size_copy += player_size_copy-1;
                        operation_count++;
                    }
                    else
                    {
                        operation_count = N;
//                        cout << "breaking cause player too small"<<endl;
                        break;
                    }
                }
            }
//            cout<<"operation_count "<<operation_count<<endl;
            if(best_count>operation_count)
                best_count=operation_count;
        }


        cout << "Case #"<<currentCase<<": "<<best_count<<endl;
        fileOut << "Case #"<<currentCase<<": "<<best_count<<endl;
        cout <<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
