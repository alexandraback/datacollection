#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, const char* argv[]){
    ifstream infile;
    int testcasenum;
    ofstream outfile;
    
    infile.open("A-large.in");
    outfile.open("A-large.out");

    infile >> testcasenum;
    for(int i=0; i<testcasenum; ++i) {
        int smax;
        infile >> smax;
        
        char numchar = '0';
        int curova = 0;
        int gap = 0;
        
        for(int j=0; j<=smax; ++j) {
            infile >> numchar;
            int num = numchar - '0';
            
            if(num == 0) {
                continue;
            }
            
            if(curova < j) {
                gap += (j - curova);
                curova = j;
            }
            curova += num;
        }
        
        outfile << "Case #" << i+1 << ": " << gap << endl;
    }
    
    infile.close();
    outfile.close();
    return 0;
}

