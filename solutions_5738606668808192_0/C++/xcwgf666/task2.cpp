#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

class CoinJam {
private:
    
    const int MAX_DIVISOR_TO_FIND = 500;
    const int NO_DIVISOR_FOUND = -1;
    
    int findDivisorInBase (std::vector<int> jamCoin, int base) {
        for(int i = 2; i <= MAX_DIVISOR_TO_FIND; ++i) {
            int currentRemainder = 0;
            for(size_t j = 0; j < jamCoin.size(); ++j)
                currentRemainder = (currentRemainder * base + jamCoin[j]) % i;
            if (currentRemainder == 0)
                return i;
        }
        return NO_DIVISOR_FOUND;
    }
    
public:
    void generate (int n, int soughtAmount, std::ostream& outputStream) {
        
        std::vector<std::pair<std::vector<int>, std::vector<int> > > legalJamCoins;
        
        for(int i = 0; i < (1 << (n - 2)); ++i) {
            
            std::vector<int> jamCoin;
            jamCoin.resize(n);
            
            jamCoin[0] = 1;
            for(int j = 0; j < (n - 2); ++j)
                if (i & (1 << j))
                    jamCoin[j + 1] = 1;
                else
                    jamCoin[j + 1] = 0;
            
            jamCoin[n - 1] = 1;
            
            bool isLegalJamcoin = true;
            std::vector<int> divisors;
            
            for(int base = 2; base <= 10; ++base) {
                int divisor = findDivisorInBase(jamCoin, base);
                if (divisor == NO_DIVISOR_FOUND) {
                    isLegalJamcoin = false;
                    break;
                } else
                    divisors.push_back(divisor);
            }
            
            if (isLegalJamcoin) {
                legalJamCoins.push_back(make_pair(jamCoin, divisors));
            }
            
            if (legalJamCoins.size() == soughtAmount)
                break;
            
        }
        
        std::cerr << legalJamCoins.size() << std::endl;
     
        outputStream << "Case #1:" << std::endl;
        for(size_t i = 0; i < soughtAmount; ++i) {
            for(size_t j = 0; j < legalJamCoins[i].first.size(); ++j)
                outputStream << legalJamCoins[i].first[j];
            for(size_t j = 0; j < legalJamCoins[i].second.size(); ++j)
                outputStream << " " << legalJamCoins[i].second[j];
            outputStream << std::endl;
        }
    }
};

int main () {
    
    CoinJam solver;
    
    solver.generate(16, 50, std::cout);
    
    return 0;
}