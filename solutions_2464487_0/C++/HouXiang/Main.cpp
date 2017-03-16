#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "wrong number of parameter" << endl;
        return -1;
    }

    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "cannot open file " << argv[1] << endl;
        return -1;
    }

    string ln;  
    inf >> ln;

    int number = atoi(ln.c_str());

    for (int cases=0; cases<number; cases++) 
    {
        __int64 r = 0, t = 0; 
        inf >> ln; sscanf(ln.c_str(), "%I64d", &r);
        inf >> ln; sscanf(ln.c_str(), "%I64d", &t);
        int res = 0; 
        do {
            __int64 sq = (r+1) * (r+1) - r * r;  
            if (t >= sq) {
                res++; 
                t -= sq; 
            }
            else 
                break;
            r += 2; 
        } while (true);

        // print result
        cout << "Case #" << (cases + 1) << ": " << res << endl;
    }

    return 0;
}
