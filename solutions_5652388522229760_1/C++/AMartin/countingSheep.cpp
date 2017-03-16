#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::cout.sync_with_stdio(false);
    unsigned int t, c, n;
    std::string::size_type sz;
    
    std::cin >> t;
    c = t;
    while (c > 0){
        char counts[10] = {0,0,0,0,0,0,0,0,0,0};
        int matches = 0;
        unsigned long long total = 0;

        std::cin >> n;
        c--;
        std::cout << "Case #" << t-c << ": ";
        
        if (n == 0){
            std::cout << "INSOMNIA";
        } else {
            while (matches < 10){
                total += n;
                std::ostringstream stringStream;
                stringStream << total;
                for (auto digit: stringStream.str()){
                    int i = digit - '0';
                    if (counts[i] == 0){
                        matches+= 1;
                        counts[i] = 1;
                    }
                }
                
            }
            std::cout << total;
        }
        std::cout << '\n';
    } 
}