#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int bigint;

size_t solve (size_t a, size_t b, size_t k) {
    size_t res = 0;
    // bruteforce for one
    for (size_t i=0; i<a; ++i)
        for (size_t j=0; j<b; ++j)
            if ((i&j) < k)
                ++res;
    return res;
}

void play () {
    size_t a, b, k;
    std::cin >> a >> b >> k;
    std::cout << solve(a, b, k) << std::endl;
}

int main () {
    size_t cases;
    std::cin >> cases;
    for (size_t i=1; i<=cases; ++i) {
        std::cout << "Case #" << i << ": ";
        play();
    }
    return 0;
}
