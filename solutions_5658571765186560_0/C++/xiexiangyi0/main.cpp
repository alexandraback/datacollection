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




static const char * RI = "RICHARD";
static const char * GI = "GABRIEL";




int main(int argc, const char* argv[]){
    ifstream infile;
    long testcasenum;
    ofstream outfile;
    
    infile.open("D-small-attempt1.in");
    outfile.open("D-small-attempt1.out");
    
    infile >> testcasenum;
    for(long i=0; i< testcasenum; ++i) {
        int X, R, C;
        infile >> X >> R >> C;
        
        if(R > C) {
            int tmp = R;
            R = C;
            C = tmp;
        }
        
        const char * res = nullptr;
        
        if(X == 1) {
            res = GI;
        }
        else if(X >= 7) {
            res = RI;
        }
        else if(R*C % X != 0) {
            res = RI;
        }
        else if(X == 2) {
            res = GI;
        }
        else if(X == 3) {
            if(R == 1) {
                res = RI;
            }
            else {
                res = GI;
            }
        }
        else if(X == 4) {
            if(R <= 2) {
                res = RI;
            }
            else {
                res = GI;
            }
        }
        else {
            res = GI;
        }
        
        outfile << "Case #" << i+1 << ": " << res << endl;
    }
    
    infile.close();
    outfile.close();
    return 0;
}
