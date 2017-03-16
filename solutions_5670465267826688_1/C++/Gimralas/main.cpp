#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define N 0
#define I 1
#define J 2
#define K 3

int getIJKFromChar(char c)
{
    switch(c) {
        case 'i': return I;
        case 'j': return J;
        case 'k': return K;
    }
    return N;
}

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

    unsigned int values[4][4] = {{N, I, J, K}, {I, N, K, J}, {J, K, N, I}, {K, J, I, N}};
    bool signs[4][4] = {{true, true, true, true}, {true, false, true, false}, {true, false, false, true}, {true, true, false, false}};

    // Process each test case one by one
    for(unsigned int t = 1 ; t <= T ; t++) {
        double L, X;
        inStream >> L;
        inStream >> X;

        string str;
        inStream >> str;

        bool positive = true;
        int current = N;
        for(unsigned int i = 0 ; i < L ; i++) {
            positive = (positive == signs[current][getIJKFromChar(str[i])]);
            current = values[current][getIJKFromChar(str[i])];
        }

        string solution = "NO";
        if(((current == I || current == J || current == K) && fmod(X+2, 4) == 0) || (current == N && !positive && fmod(X, 2) == 1)) {
            positive = true;
            current = N;
            bool iFound = false;
            unsigned int iLength = 0;
            for(unsigned int s = 0 ; s < L*X && s < L*4 ; s++) {
                positive = (positive == signs[current][getIJKFromChar(str[fmod(s, L)])]);
                current = values[current][getIJKFromChar(str[fmod(s, L)])];

                if(current == I && positive) {
                    iFound = true;
                    iLength = s+1;
                    break;
                }
            }

            if(iFound) {
                positive = true;
                current = N;
                for(unsigned int s = 0 ; s < L*X && s < L*4 ; s++) {
                    if(iLength + s+1 >= L*X)
                        break;

                    positive = (positive == signs[getIJKFromChar(str[L-1 - fmod(s, L)])][current]);
                    current = values[getIJKFromChar(str[L-1 - fmod(s, L)])][current];

                    if(current == K && positive) {
                        solution = "YES";
                        break;
                    }
                }
            }
        }

        // Output the test case result
        outStream << "Case #" << t << ": " << solution << endl;
    }

    // Close input and output files and leave
    outStream.close();
    inStream.close();
    return 0;
}
