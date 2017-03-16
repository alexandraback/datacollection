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

bool isPalindrome(unsigned long long i)
{
    string number;
    stringstream strstream;
    strstream << i;
    strstream >> number;

    for(int j=0; j<number.length()/2; j++)
    {
        if(number[j] != number[number.length()-1-j])
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    string fileName = "C-large-1";
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

    cout << "----- generate palindrome vector -----"<<endl;
    vector<unsigned long long> vectorLong;
    for(unsigned long long i=1; i <= 10000000 ; i++)
    {
        if(i%1000000==0)
            cout << "i="<<i<<endl;

        if(isPalindrome(i))
        {
            vectorLong.push_back(i);
        }

        if(isPalindrome(i*i))
        {
            vectorLong.push_back(i*i);
        }
    }

    cout << "----- finding square -----"<<endl;
    map<unsigned long long,bool> mymap;
    for(int i=0;i<vectorLong.size();i++)
    {
        if(mymap.find(vectorLong[i]) == mymap.end())
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

    // for each case
    while ( fileIn.good() and currentCase < T)
    {
        ++currentCase;
        cout << "----- Case #"<<currentCase<<" -----"<<endl;

        getline (fileIn,line);

        stringstream stream(line);
        unsigned int A, B;
        stream >> A >> B;
        cout << "A " << A << " B " << B << endl;

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
