#include <iostream>
#include <string>

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; t++)
    {
        std::string s;
        std::cin >> s;
        char last = ' ';
        int count = -1;
        for(char& c : s) {
            if (c != last) {
                last = c;
                count ++;
            }
        }
        if (last == '-') count++;
        std::cout << "Case #" << t+1 << ": " << count << std::endl;
    }
    return 0;
}