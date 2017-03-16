#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;

void howMany(unsigned long long int N){
    //int maxN = 10;

    bool num[2500];

    for (unsigned int i = 0; i < 2500; i++) {
        num[i] = false;
    }


    for (unsigned int i = 0; i < 2*N - 1; i++) {
        for (unsigned int j = 0; j < N; j++) {
            int n;
            in >> n;
            num[n-1] = !num[n-1];
        }
    }

    for (unsigned int i = 0; i < 2500; i++) {
        if (num[i])
            out << " " << i+1;
    }

    return;
}


int main()
{
    in.open("B-large.in");
    out.open("output.out");
    unsigned long long int T, N;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> N;
            out << "Case #" << i << ":";
            howMany(N);
            out << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
