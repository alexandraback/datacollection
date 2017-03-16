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
    string fileName = "B-small-attempt0";
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
        int N,M;
        stream >> N >> M;
        cout << "N " << N << " M " << M << endl;

        int* matrix = new int[N*M];

        for (int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream(line);
            for (int j=0;j<M;j++)
            {
                stream >> matrix[i + j*N];
            }
        }

        bool possible = true;

        // for each line, check if it is possible
        int max;
        for (int i=0;i<N;i++)
        {
            max = 0;
            for (int j=0;j<M;j++)
            {
                if(matrix[i + j*N]>max)
                    max = matrix[i + j*N];
            }

            // for each value in the row which is less than max, we check if it is possible to cut it vertically (ie there is nothing > vertically)
            for (int j=0;j<M;j++)
            {
                if(matrix[i + j*N]<max)
                {
                    for (int i2=0;i2<N;i2++)
                    {
                        if(matrix[i + j*N] < matrix[i2 + j*N])
                        {
                            possible = false;
                            goto end_loop;
                        }
                    }
                }
            }
        }

        end_loop:

        if(possible)
        {
            cout << "Case #"<<currentCase<<": YES"<<endl;
            fileOut << "Case #"<<currentCase<<": YES"<<endl;
        }
        else
        {
            cout << "Case #"<<currentCase<<": NO"<<endl;
            fileOut << "Case #"<<currentCase<<": NO"<<endl;
        }

        delete[] matrix;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
