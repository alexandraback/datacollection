#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void add(map<unsigned int, unsigned int>& myMap, unsigned int atValue);
unsigned int force(map<unsigned int, unsigned int> diners, unsigned int minutes = 0);

int main(int argc, char* argv[])
{
    if(argc != 2) { // Check if valid number of program arguments
        cerr << "Need only one argument : the input file name" << endl;
        return 0;
    }
    string testFilename(argv[1]);

    // Open (and check) input inStream
    ifstream inStream(testFilename);
    if(!inStream.is_open()) {
        cerr << "The input file \"" << testFilename << "\" does not exist" << endl;
        return 0;
    }

    // Get the number of test cases to process
    unsigned int T = 0;
    inStream >> T;

    // If needed : create a string to get lines and ignore the previous already read one
    // string line;
    // getline(inStream, line);

    // Open the output file
    ofstream outStream(testFilename.substr(0, testFilename.find(".in")) + ".out");

    // Process each test case one by one
    for(unsigned int t = 1 ; t <= T ; t++) {
        // Read input file & Find solution
        unsigned int D;
        inStream >> D;
        map<unsigned int, unsigned int> diners;
        unsigned int tmp;
        for(unsigned int d = 0 ; d < D ; d++) {
            inStream >> tmp;
            add(diners, tmp);
        }

        // Output the test case result
        outStream << "Case #" << t << ": " << force(diners) << endl;
    }

    // Close input and output files and leave
    outStream.close();
    inStream.close();
    return 0;
}

void add(map<unsigned int, unsigned int>& myMap, unsigned int atValue)
{
    try {
        myMap.at(atValue)++;
    }
    catch(exception& e) {
        myMap[atValue] = 1;
    }
}

unsigned int force(map<unsigned int, unsigned int> diners, unsigned int minutes)
{
    unsigned int max = (diners.rbegin())->first;
    if(max <= 1)
        return (minutes+1);

    map<unsigned int, unsigned int> wait;
    for(map<unsigned int, unsigned int>::iterator it = diners.begin() ; it != diners.end() ; it++) {
        if(it->first > 1)
            wait[it->first-1] = it->second;
    }
    unsigned int waitMinutes = force(wait, minutes+1);

    unsigned int cutPart, tmp, waitTime, cutTime = -1;
    for(unsigned int nbParts = 2 ; nbParts <= max ; nbParts++) {
        cutPart = max/nbParts;
        if(cutPart > max - (nbParts-1)*cutPart)
            waitTime = cutPart;
        else
            waitTime = max - (nbParts-1)*cutPart;
        if(nbParts-1+waitTime < cutTime) {
            cutTime = nbParts-1+waitTime;
            tmp = cutPart;
        }
    }

    map<unsigned int, unsigned int> cut = diners;
    add(cut, tmp);
    add(cut, max-tmp);
    if((--cut[max]) == 0)
        cut.erase(max);
    unsigned int cutMinutes = force(cut, minutes+1);

    if(waitMinutes < cutMinutes)
        return waitMinutes;
    else
        return cutMinutes;
}
