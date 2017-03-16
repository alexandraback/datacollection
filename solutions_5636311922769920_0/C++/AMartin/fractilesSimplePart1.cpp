#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

int main(){
    std::cout.sync_with_stdio(false);
    unsigned int t, c, k, s;
    
    std::cin >> t;
    unsigned int i = t;
    while (i > 0){
        std::cin >> k >> c >> s;
        i--;
        std::cout << "Case #" << t-i << ": ";
        for(int j = 1; j < k; j++){
            std::cout << j << " ";
        }
        std::cout << k << '\n';
    } 
}  