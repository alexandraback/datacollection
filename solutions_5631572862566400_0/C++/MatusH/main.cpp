#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;


unsigned int compute(unsigned long long int N){
    unsigned int maxN = 10;
    unsigned int big = 0;
    unsigned int plus = 0;

    unsigned int F[N+1];
    bool kid[N+1];
    bool start[N+1];
    bool end[N+1];
    unsigned int endPlus[N+1];
    bool pair = true;

    for (unsigned int i = 1; i < N+1; i++) {
        in >> F[i];
        kid[i] = true;
        start[i] = true;
        end[i] = true;
        endPlus[i] = 0;
    }

    for (unsigned int i = 1; i < N+1; i++) {
        if (start[i]) {
            for (unsigned int j = 1; j < N+1; j++) {
                kid[j] = true;
            }
            unsigned int count = 1;
            unsigned int kido = i;
            kid[i] = false;
            while (true) {
                //kido = F[kido];
                if (kid[F[kido]]) {
                    kido = F[kido];
                    kid[kido] = false;
                    start[kido] = false;
                    count++;
                } else {
                    if (kido == F[F[kido]]) {
                        if (end[kido]) {
                            endPlus[kido] = count-1;
                            plus += count-1;
                            end[kido] = false;
                        } else {
                            if (endPlus[kido] < count-1) {
                                plus += count-1 - endPlus[kido];
                                endPlus[kido] = count-1;
                            }
                        }
                    } else {
                        count = 1;
                        unsigned int kidoo = F[kido];
                        while (kido != kidoo) {
                            kidoo = F[kidoo];
                            count++;
                            if (count == maxN){
                                count = 0;
                                break;
                            }
                        }
                        big = max(big, count);
                    }
                    break;
                }
            }
        }
    }

    unsigned int result = max(big, plus);
    return result;
}

int main()
{
    in.open("C-small-attempt0.in");
    out.open("output.out");
    unsigned long long int T, N;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> N;
            out << "Case #" << i << ": " << compute(N) << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
