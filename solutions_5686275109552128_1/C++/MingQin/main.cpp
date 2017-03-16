/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}

int minTime(vector<int> P, int N) {

    //forgot this
    if (N <= 2) {
        return N;
    }

    int best = INT_MAX;
    for (; N >= 2; --N) {
        int time = 0;
        for (int a : P) {
            int a2;
            if (a%N == 0) {
                a2 = a / N - 1;
            } else {
                a2 = a / N;
            }
            time += a2;
        }
        time += N;
        best = min(best, time);
    }
    return best;
}

int main(int argc, char** argv) {
    vector<string> strv;
    int D;
    int T;
    int i = 0;

    vector<int> P;


    fstream infile("in.txt");
    ofstream outfile("out.txt");

    infile >> T;
    for (int i = 0; i < T;++i){
        infile >> D;
        P.clear();
        P.reserve(D);
        int maxP = 0;
        for (int i = 0; i < D; ++i) {
            int p;
            infile >> p;
            maxP = max(maxP, p);
            P.push_back(p);
        }
        outfile << "Case #" << 1+i << ": ";
        outfile << minTime(P, maxP) << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
