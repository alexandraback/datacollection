#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int avail[2000000];
long long val[2000000];
int numAct = 0;
int maxE = 0;

int doit(int n, int e, int r) {
    
    if (n == numAct) return 0;
    
    int themax = 0;
    e = min(e+r, maxE);
    
    for (int i = 0; i <= e; i++) {
        int now = val[n] * i + doit(n+1, e-i, r);
        themax = max(themax, now);
    }
    return themax;
    
}

int main() {
 
    ifstream infile("C:/a.in");
    ofstream outfile("C:/a.out");
    int numCases = 0;
    infile >> numCases;
    for (int i = 0; i < numCases; i++) {
        int r;
        infile >> maxE >> r >> numAct;
        for (int j = 0; j < numAct; j++) infile >> val[j];        
        long long result = doit(0,maxE,r);
        outfile << "Case #" << (i+1) << ": " << result << endl;
    }    
    outfile.close();
    //system("PAUSE");
    return 0;   
    
}
