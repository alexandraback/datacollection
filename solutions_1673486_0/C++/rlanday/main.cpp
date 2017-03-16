#include <iostream>
#include <stdio.h>

using namespace std;

double min(double a, double b) {
    return a < b ? a : b;
}

double expected(int numSoFar, double *probs, int length, int numBackspaces) {
    double probCorrect = 1;
    
    for (int i = 0; i < numSoFar - numBackspaces; i++) {
        probCorrect *= probs[i];
    }
    
    return numBackspaces + (length - numSoFar + numBackspaces + 1) +
    (1 - probCorrect) * (length + 1);
}

int main(int argc, const char * argv[])
{
    int numCases;
    cin >> numCases;
    
    for (int i = 0; i < numCases; i++) {
        int numSoFar;
        cin >> numSoFar;
        
        int numChars;
        cin >> numChars;
        
        double *probs = new double[numSoFar];
        
        for (int i = 0; i < numSoFar; i++) {
            cin >> probs[i];
        }
        
        double expectedVal = 2 + numChars;
        
        for (int i = 0; i <= numSoFar; i++) {
            expectedVal = min(expectedVal, expected(numSoFar, probs, numChars, i));
        }
        
        delete[] probs;

        printf("Case #%d: %.6f\n", i + 1, expectedVal);
    }
}

