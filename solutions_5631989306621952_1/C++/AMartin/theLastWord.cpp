#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::cout.sync_with_stdio(false);
    unsigned int t, c;
    std::string out;
    std::string str;
    
    std::cin >> t;
    c = t;
    while (c > 0){
        c--;
        std::cout << "Case #" << t-c << ": ";
        out = "";
        str = "";
        std::cin >> str;
        char prev = ' ';
        
        for (auto next: str){
            if (prev == ' '){
                out = out + next;
                prev = next;
            } else if (prev <= next){
                out = next + out;
                prev = next;
            } else {
                out = out + next;
            }
        }
        std::cout << out << '\n';
    } 
}