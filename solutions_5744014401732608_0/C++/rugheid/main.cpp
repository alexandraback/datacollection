//
//  main.cpp
//  Slides!
//
//  Created by Rugen Heidbuchel on 08/05/16.
//  Copyright © 2016 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include "codingmacros.h"
#include <cmath>

size_t T, B, M;
std::vector<int> M_bits;

int main(int argc, const char * argv[]) {

    #ifdef USE_INPUT_FILE
    freopen("example_input.txt", "r", stdin);
    #endif
    
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        
        std::cout << "Case #" << caseNumber + 1 << ": ";
        
        std::cin >> B >> M;
        
        std::vector<std::vector<int>> matrix(B, std::vector<int>(B, 0));
        for (size_t i = 0; i < B - 1; i++) {
            matrix[i][i+1] = 1;
        }
        
        if (M > pow(2.0, B-2)) {
            std::cout << "IMPOSSIBLE\n";
            continue;
        }
        
        std::cout << "POSSIBLE\n";
        
        M_bits.clear();
        while (M) {
            if (M&1)
                M_bits.push_back(1);
            else
                M_bits.push_back(0);
            M >>= 1;
        }
        std::reverse(M_bits.begin(), M_bits.end());
        
        for (size_t i = (B - M_bits.size() - 1); i < B; i++) {
            for (size_t j = i + 1; j < B; j++) {
                matrix[i][j] = 1;
            }
        }
        
        if (M_bits.size() < B - 1) {
            for (size_t j = 1; j < M_bits.size(); j++) {
                matrix[B - 2 - M_bits.size()][j + B - 1 - M_bits.size()] = M_bits[j];
            }
        }
        
        for (size_t i = 0; i < B; i++) {
            for (size_t j = 0; j < B; j++) {
                std::cout << matrix[i][j];
            }
            std::cout << "\n";
        }
    }
    
    return 0;
}