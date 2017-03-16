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
    string fileName = "A-small-attempt0";
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
        int N;
        string nameString;
        stream >> nameString >> N;
        cout << "Name " << nameString << " N " << N << endl;

        const char* name = nameString.c_str();

        int wordFound = 0;

        for(int i=0; i < nameString.length() +1 -N; i++)
        {
            bool found = false;
            int count = 0;

//            if(name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u')
                for(int j=i;j < nameString.length(); j++)
                {
                    if(found)
                    {
                        wordFound++;
                        continue;
                    }

                    if(name[j] != 'a' && name[j] != 'e' && name[j] != 'i' && name[j] != 'o' && name[j] != 'u')
                        count++;
                    else
                        count = 0;

                    if(count >= N)
                    {
//                        cout << "found i:"<<i<<" j:"<<j<<endl;
                        found = true;
                        wordFound++;
                    }
                }
        }




        cout << "Case #"<<currentCase<<": "<<wordFound<<endl;
        fileOut << "Case #"<<currentCase<<": "<<wordFound<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
