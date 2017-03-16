#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <math.h>       /* pow */

using namespace std;

ifstream in;
ofstream out;

void count(unsigned long long int B, unsigned long long int M){
    if (M > pow(2, B-2)) {
        out << "IMPOSSIBLE" << endl;
        return;
    }

    out << "POSSIBLE" << endl;

    unsigned int P[B][B];
    //cout << pow(2, B-2) << endl;

    for (unsigned int i = 0; i < B-1; i++) {
        for (unsigned int j = 0; j < B-1; j++) {
            if (i < j)
                P[i][j] = 1;
            else
                P[i][j] = 0;
        }

        if ((i == 0) && (M == pow(2, B-2))) {
            P[i][B-1] = 1;
            M--;
        }
        else {
            P[i][B-1] = 0;
        }
        if (i != 0) {
            P[i][B-1] = M % 2;
            M /= 2;
        }
    }


    for (unsigned int j = 0; j < B; j++) {
       P[B-1][j] = 0;
    }

    for (unsigned int i = 0; i < B; i++) {
        for (unsigned int j = 0; j < B; j++) {
            out << P[i][j];
        }
        out << endl;
    }

    return;
}


int main()
{
    in.open("B-large.in");
    out.open("output.out");
    string S;
    unsigned long long int T, B, M;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> B >> M;

            out << "Case #" << i << ": ";

            count(B, M);

            //out << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
