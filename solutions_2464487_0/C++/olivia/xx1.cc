#include <stdexcept>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <set>
using namespace std;


long long solve(long long r, long long t){
    long long r2 = 2 * r + 1;
    long long i = 1;
    while(t>=0){
        t = t - (r2 + (i-1)*4);
        i++;
    }
    return i-2;
}

void read_line(string iName, string oName){
    ifstream inFile(iName.c_str());
    ofstream outFile(oName.c_str());
    int nTest;
    inFile>>nTest;
    for(int i = 0; i < nTest; i++){
        cout << "TESTCASE #" << (i+1) << endl;
        long long r, t;
        inFile >> r >> t;
        long long ret = solve(r,t);
        outFile << "Case #" << (i+1) << ": " << ret << endl;
    }
}

int main(){
    string iName = "./data1.dat";
    string oName = "./result1.dat";
    read_line(iName,oName);
}
