//
//  main.cpp
//  Fashion Police
//
//  Created by Rugen Heidbuchel on 08/05/16.
//  Copyright © 2016 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include "codingmacros.h"
#include <sstream>

size_t T, J, P, S;
int K;

int main(int argc, const char * argv[]) {

    #ifdef USE_INPUT_FILE
    freopen("example_input.txt", "r", stdin);
    #endif
    
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        
        std::cout << "Case #" << caseNumber + 1 << ": ";
        
        std::cin >> J >> P >> S >> K;
        
        std::vector<std::vector<int>> JP(J, std::vector<int>(P, K));
        std::vector<std::vector<int>> JS(J, std::vector<int>(S, K));
        std::vector<std::vector<int>> PS(P, std::vector<int>(S, K));
        std::vector<std::vector<std::vector<bool>>> JPS(J, std::vector<std::vector<bool>>(P, std::vector<bool>(S, false)));
        
        std::ostringstream output;
        size_t count = 0;
        
        for (size_t j = 0; j < J; j++) {
            for (size_t p = 0; p < P; p++) {
                for (int s = S-1; s >= 0; s--) {
                    if (JP[j][p] == 0) {
                        continue;
                    }
                    if (PS[p][s] == 0) {
                        continue;
                    }
                    if (JS[j][s] == 0) {
                        continue;
                    }
                    if (JPS[j][p][s]) {
                        continue;
                    }
                    count++;
                    output << j+1 << " " << p+1 << " " << s+1 << "\n";
                    JP[j][p]--;
                    PS[p][s]--;
                    JS[j][s]--;
                    JPS[j][p][s] = true;
                }
            }
        }
        
        std::cout << count << "\n" << output.str();
    }
    
    return 0;
}