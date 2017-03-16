#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool ok(long long n, long long r, long long themax) {
     long long val = 2*r + 1 + 2*(n-1);
     return val <= (themax / n);
}

long long bsearch(long long r, long long themax) {
     long long upper = ((long long)1000000000) * 10;
     long long lower = 1;
     
     if (!ok(2,r,themax)) return 1;
     
     while (lower < upper - 1) {
           long long mid = (lower + upper)/2;
           if (ok(mid,r,themax)) lower = mid;
           else upper = mid;                                 
     }
     if (ok(upper,r,themax)) return upper;
     return lower;
     
}

int main() {
 
    ifstream infile("C:/a.in");
    ofstream outfile("C:/a.out");
    int numCases = 0;
    infile >> numCases;
    for (int i = 0; i < numCases; i++) {
        long long r, themax;
        infile >> r >> themax;
        long long count = bsearch(r, themax);
        outfile << "Case #" << (i+1) << ": " << count << endl;
    }    
    outfile.close();
    //system("PAUSE");
    return 0;   
    
}
