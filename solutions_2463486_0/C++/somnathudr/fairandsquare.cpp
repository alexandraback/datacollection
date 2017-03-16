#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
 
using namespace std;
 
bool is_palindrome(int num) {
    string str;
    stringstream out;
    out << num;
    str = out.str();
    string reverse_str = string(str.rbegin(), str.rend());
    if (str == reverse_str) {
        return true;
    } else {
        return false;
    }
}
 
int main(int argc, const char * argv[])
{
    int cases = 0;
    std::cin >> cases;
    for(int run = 1; run <= cases; run ++) {
        int min = 0, max = 0;
        std::cin >> min;
        std::cin >> max;
        
        int min_sqrt = sqrt(min) > (int)sqrt(min) ? sqrt(min)+1 : sqrt(min);
        int max_sqrt = (int)sqrt(max);
        int count = 0;
        for(int i = min_sqrt; i <= max_sqrt; i ++) {
            if (is_palindrome(i) && is_palindrome(pow(i, 2))) count ++;
        }
        std::cout << "Case #" << run << ": " << count << std::endl;
    }
    return 0;
}
 
