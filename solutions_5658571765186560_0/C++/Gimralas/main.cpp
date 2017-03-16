#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

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
        unsigned int X, R, C;
        inStream >> X;
        inStream >> R;
        inStream >> C;

        string solution = "GABRIEL";

        bool cannotFit = ((R*C) % X != 0);
        for(unsigned int i = 1 ; i <= X ; i++) {
            unsigned int a = i, b = X+1-i;
            if(!((a <= R && b <= C) || (a <= C && b <= R)))
                cannotFit = true;
        }
        if(X == 4 && (R <= 2 || C <= 2 || (R <= 3 && C <= 3)))
            cannotFit = true;

        if(cannotFit)
            solution = "RICHARD";

        // Output the test case result
        outStream << "Case #" << t << ": " << solution << endl;
    }

    // Close input and output files and leave
    outStream.close();
    inStream.close();
    return 0;
}
