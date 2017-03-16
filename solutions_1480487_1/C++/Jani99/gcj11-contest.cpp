//============================================================================
// Name        : gcj11-contest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>


void printvector(std::vector<unsigned> J) {
    for (unsigned i=0;i<J.size();++i) {
        printf("%u ",J[i]);
    }
    printf("\n");
}

bool isFavorit(unsigned j, unsigned n, unsigned sum) {
    return (j*(n-1)) >= (2*sum-j);
}

std::vector<double> solve (std::vector<unsigned> J) {

    unsigned n = J.size();
    unsigned sum = 0;
    unsigned favn = 0;
    unsigned favsum = 0;

    for (unsigned i=0;i<J.size();++i) {
        sum += J[i];
    }

    for (unsigned i=0;i<J.size();++i) {
        if (isFavorit(J[i],n,sum)) {
            ++favn;
            favsum+=J[i];
        }
    }

    double avgLoser = (double)(sum*2-favsum)/(double)(n-favn);

    std::vector<double> Q;

    for (unsigned i=0;i<J.size();++i) {

        double q;

        if (isFavorit(J[i],n,sum)) {
            q = 0;
        } else {
            q = (avgLoser-(double)J[i])/((double)sum);
        }
        Q.push_back(q * 100.0);
    }

    return Q;
}

void print5(unsigned t, std::vector<double> Q) {
    printf("Case #%u:",t+1);
    for (unsigned i=0;i<Q.size();++i) {
        printf(" %.6f", Q[i]);
    }
    printf("\n");
}

int main() {

    unsigned T;

    std::cin >> T;

    for (unsigned t=0;t<T;++t) {
        unsigned N;
        std::cin >> N;
        std::vector<unsigned> J;
        for (unsigned n=0;n<N;++n) {
            unsigned Jn;
            std::cin >> Jn;
            J.push_back(Jn);
        }
        //printvector(J);
        std::vector<double> Q = solve(J);
        print5(t,Q);
    }

	return 0;
}
