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
        c--;
        std::cout << "Case #" << t-c << ": ";
        
        char prev = ' ';
        int count = 0;
        std::string str;
        std::cin >> str;
        
        for (auto cake: str){
            if (cake != prev){
                count += 1;
                prev = cake;
            }
        }
        if (prev == '+'){
            count -= 1;
        }
        std::cout << count;
        std::cout << '\n';
    } 
}