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
        
        unsigned long long sizes[c];
        for(int j = 1; j <= c; j++){
            sizes[j-1] = std::pow(k,c-j);
        }
        
        if (k/(double)c > s){
            std::cout << "IMPOSSIBLE";
        } else {
            unsigned int count = 0;
            
            while (count+c <= k){
                unsigned long long ind = 1;
                for (int j = 0; j < c; j++){
                    ind += sizes[j]*(count+j);
                }
                std::cout << ind <<' ';
                count += c;
            }
            if (count != k){
                int j = 0;
                unsigned long long ind = 0;
                while (count +j <= k){
                    ind += sizes[j]*(count+j);
                    j+=1;
                }
                std::cout << ind <<' ';
                
            }
        }
        std::cout << '\n';
    } 
}  