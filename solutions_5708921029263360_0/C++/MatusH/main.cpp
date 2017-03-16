#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;


void count(unsigned int J, unsigned int P, unsigned int S, unsigned int K){
    unsigned int JPS = J*P*S;
    unsigned int JPK = J*P*K;

    if (JPS < JPK) {
        out << JPS << endl;
        for (unsigned int j = 1; j < J+1; j++)
            for (unsigned int p = 1; p < P+1; p++)
                for (unsigned int s = 1; s < S+1; s++) {
                    out << j << " " << p << " " << s << endl;
                }
    } else {
        unsigned int s = 1;
        out << JPK << endl;
        for (unsigned int j = 1; j < J+1; j++)
            for (unsigned int p = 1; p < P+1; p++) {
                for (unsigned int k = 1; k < K+1; k++) {
                    out << j << " " << p << " " << s << endl;
                    s = s % S;
                    s++;
                }
            }
    }


    return;
}


int main()
{
    in.open("C-small-attempt0.in");
    out.open("output.out");
    //string S;
    unsigned long long int T;
    unsigned int J, P, S, K;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> J >> P >> S >> K;

            out << "Case #" << i << ": ";

            count(J, P, S, K);

            //out << endl;
        }
        in.close();
    }else {
        cout << "fuck";
    }
    out.close();
    return 0;
}
