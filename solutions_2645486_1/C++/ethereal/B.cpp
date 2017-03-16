#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>

std::vector<uint64_t> v;
uint64_t E, R, N;

uint64_t dist(uint64_t l) {
    //std::cout << "dist(" << l << "): E = " << E << ", E-l = " << E-l << std::endl;
    //uint64_t r1 = (E-l)/R;
    return (E-l + R - 1) / R;
    //return (E-l)/R;
}

uint64_t find_best() {
    uint64_t l = E;
    uint64_t i = 0;
    uint64_t sum = 0;

    uint64_t maxdist = dist(0);
    //std::cout << "maxdist: " << maxdist << std::endl;
    while(i < N) {
        // find minimum distance to job with higher valuation

        //std::cout << "N: " << N << std::endl;
        uint64_t c;
        for(c = i+1; c < N && c < i+maxdist; c ++) {
            if(v[c] > v[i]) break;
        }

        //std::cout << "closest with higher valuation: " << c << std::endl;
        //std::cout << "\tvaluation there: " << v[c] << std::endl;
        //std::cout << "\tvaluation here: " << v[i] << std::endl;
        // nothing? Then spend it all.
        if(c == N || c == i+maxdist) {
            //std::cout << "\tspending everything!" << std::endl;
            sum += l*v[i];
            l = R;
            i ++;
            continue;
        }

        // otherwise, how far do we have to travel?
        uint64_t tt = c - i;

        // want highest l such that dist(l) == tt.
        uint64_t target = E - tt*R;
        uint64_t diff = 0;
        if(target > l) target = l;
        else diff = l - target;

        sum += diff*v[i];
        l = target;
        i ++;
        l += R;
    }

    return sum;
}

int main() {
    int T;
    std::cin >> T;
    
    for(int C = 0; C < T; C ++) {
        std::cin >> E >> R >> N;

        v.assign(N, 0);
        for(int i = 0; i < N; i ++) {
            std::cin >> v[i];
        }

        uint64_t best = find_best();

        std::cout << "Case #" << (C+1) << ": " << best << std::endl;
    }

    return 0;
}
