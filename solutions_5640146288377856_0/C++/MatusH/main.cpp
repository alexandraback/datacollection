#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

unsigned long long int howMany(unsigned long long int C, unsigned long long int W){
    if (W == 1)
        return C;
    if (C % W == 0)
        return C/W+1+W-2;
    else
        return C/W+1+W-1;
}


int main()
{
    ifstream in ("A-small-attempt0.in");
    ofstream out ("output.out");
    //string number;
    unsigned long long int T, R, C, W, result;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (int i = 1; i <= T; i++){
            in >> R >> C >> W;
            result = howMany(C, W);
            result *= R;
            out << "Case #" << i << ": " << result << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
