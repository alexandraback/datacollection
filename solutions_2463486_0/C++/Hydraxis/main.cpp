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
    string fileName = "C-small-attempt0";
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

        vector<unsigned long long> vectorLong;



        stringstream stream(line);
        unsigned int A, B;
        stream >> A >> B;
        cout << "A " << A << " B " << B << endl;

        // finding palindromes
        for(unsigned long long i=1; i <= B ; i++)
        {
            string number;
            stringstream strstream;
            strstream << i;
            strstream >> number;

            bool palindrome = true;

            for(int j=0; j<number.length()/2; j++)
            {
                if(number[j] != number[number.length()-1-j])
                {
                    palindrome = false;
                    break;
                }
            }

            if(palindrome)
            {
//                cout << "Pal # "<<i<<endl;
                vectorLong.push_back(i);
            }
        }

        // finding square
        map<unsigned long long,bool> mymap;
        for(int i=0;i<vectorLong.size();i++)
        {
            mymap[vectorLong[i]] = false;
        }
        for(int i=0;i<vectorLong.size();i++)
        {
            unsigned long long val = vectorLong[i] * vectorLong[i];

            if(mymap.find(val) != mymap.end())
            {
                mymap[val] = true;
                cout << "Square # "<<vectorLong[i]<<" = "<< val << " palidrome! "<<endl;
            }

        }

        int count = 0;
        for(map<unsigned long long,bool>::iterator it = mymap.begin(); it != mymap.end(); it++) {
            if(it->second && it->first >= A &&  it->first <= B)
                count++;
        }



        cout << "Case #"<<currentCase<<": "<<count<<endl;
        fileOut << "Case #"<<currentCase<<": "<<count<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
