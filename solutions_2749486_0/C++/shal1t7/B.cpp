#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

typedef long long LL;

class TestCase {
public:
    void load(std::istream& in)
    {
        in >> x >> y;
    }
    
    void moveRight(std::stringstream& cmd) { cmd << "WE"; }
    void moveLeft(std::stringstream& cmd) { cmd << "EW"; }
    void moveUp(std::stringstream& cmd) { cmd << "SN"; }
    void moveDown(std::stringstream& cmd) { cmd << "NS"; }

    std::string solve() 
    {
        std::stringstream cmd;
        if (x > 0) {
            for (size_t i = 0; i < x; ++i) {
                moveRight(cmd);
            }
        } else if (x < 0) {
            for (size_t i = 0; i < -x; ++i) {
                moveLeft(cmd);
            }
        }
        
        if (y > 0) {
            for (size_t i = 0; i < y; ++i) {
                moveUp(cmd);
            }
        } else if (y < 0) {
            for (size_t i = 0; i < -y; ++i) {
                moveDown(cmd);
            }
        }
        auto str =  cmd.str();
        assert(str.size() < 500);
        std::cerr << str.size() << std::endl;
        return str;
    }    

private:
    LL x;
    LL y;
};

int main()
{
    size_t T;
    std::cin >> T;
    
    for (size_t t = 0; t < T; ++t) {
        TestCase testCase;
        testCase.load(std::cin);
        std::cout << "Case #" << t + 1 << ": " << testCase.solve() << std::endl;          
    }
    return 0;
}

