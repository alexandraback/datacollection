#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>

template <class T>
void print(const std::vector<T>& v, std::ostream& out)
{
    out << "{ ";
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i] << " ";
    }
    out << "}";
}

class TestCase {
public:
    void load(std::istream& in)
    {
        in >> s >> n;
    }
    
    int solve() 
    {
        std::vector<bool> cons(s.size(), true);
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||  s[i] == 'o' || s[i] == 'u') {
                cons[i] = false;
            }
        }
        
        //std::cerr << s << std::endl;

        //std::cerr << "Cons: "; print(cons, std::cerr); std::cerr << std::endl;

        std::vector<size_t> consecCons(s.size(), 0);
        size_t counter = 0;
        for (size_t i = 0; i < cons.size(); ++i) {
            if (cons[i]) {
                consecCons[i] = ++counter;
            } else {
                counter = 0;
            }
        }
            
        //std::cerr << "consecCons: "; print(consecCons, std::cerr); std::cerr << std::endl;         
        std::vector<size_t> f(cons.size(), 0);
        size_t nv = 0;
        static const size_t Inf(-1);
        size_t last = Inf;
        for (size_t i = 0; i < cons.size(); ++i) {
            if (consecCons[i] >= n) {
                last = i;
            }
            if (last != Inf) {
                nv += (last + 2 - n);    
            }
        }
        return nv;
    }    
private:
    std::string s;
    size_t n;
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

