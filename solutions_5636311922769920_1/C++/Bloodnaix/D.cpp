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
    ifstream f1("D-large.in");
    ofstream f2("D-large.out");
    int T;
    int K, C, S;
    int need;
    long long int step = 0;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ":";
        f1 >> K >> C >> S;
        need = K / C;
        if(K % C)
            ++need;
        if(need > S)
        {
            f2 << " IMPOSSIBLE" << endl;
            continue;
        }
        for(int i = 0; i < need; ++i)
        {
            step = C * i + 1;
            for(int j = 2; j <= C; ++j)
                if(j + C * i <= K)
                    step = (step-1) * K + j + C * i;
            f2 << ' ' << step;
        }
        f2 << endl;
    }
    return 0;
}

