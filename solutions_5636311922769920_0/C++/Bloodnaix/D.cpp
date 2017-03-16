#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;


int main()
{
    ifstream f1("D-small-attempt0.in");
    ofstream f2("D-small-attempt0.out");
    int T;
    int K, C, S;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ":";
        f1 >> K >> C >> S;
        if(K == S)
        {
            for(int i = 0; i < K; ++i)
                f2 << ' ' << i+1;
            f2 << endl;
            continue;
        }
        f2 << " IMPOSSIBLE\n";
    }
    return 0;
}

