#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <parallel/algorithm>
#include <assert.h>

struct Case {
    long unsigned A;
    std::vector<long unsigned> M;
};

std::vector<Case> readTestCases(std::istream& in)
{
    size_t T;
    in >> T;
    std::vector<Case> cases;
    for (size_t t = 0; t < T; ++t) {
        long unsigned A;
        in >> A;
        size_t N;
        in >> N;
        std::vector<long unsigned> M;
        for (size_t i = 0; i < N; ++i) {
            long unsigned m;
            in >> m;
            M.push_back(m);
        }
        cases.push_back(Case{A, M});
    }
    return cases;
}

static const size_t Inf = size_t(-1); 

std::pair<size_t, long unsigned> countNecessaryAdds(long unsigned A, long unsigned X)
{
    assert(1 <= A);
    assert(A <= X);
    if (A == 1) {
        return { Inf, 0 };
    } else {
        size_t v = 0;
        while (A <= X) {
            A = (2 * A - 1);
            ++v;
        }
        A += X;
        assert(v >= 1);
        return { v, A };
    }
}

size_t solve(const Case& c)
{
    size_t counter = 0;
    size_t A = c.A;
    std::vector<long unsigned> m = c.M;
    std::sort(m.begin(), m.end());
    std::vector<size_t> o; // o[i] = minimal number of operations if we throw out everything after i and i itself
    o.assign(m.size() + 1, Inf);
    o[0] = m.size(); 
    for (size_t i = 1; i <= m.size(); ++i) {
        size_t j = i - 1;
        if (A > m[j]) {
            A += m[j];
            o[i] = counter + (m.size() - i);
        } else {
            /*
            std::cerr << "A = " << A << " i = " << i << " m[i - 1] = " << m[i - 1] << std::endl;
            */
            size_t addsNumber;
            size_t newA;
            std::tie(addsNumber, newA) = countNecessaryAdds(A, m[j]);
            if (addsNumber == Inf) {
                break;
            } else {
                counter += addsNumber;
                A = newA;
                o[i] = counter + (m.size() - i);
            }
        }
    }
    /*
    std::cerr << "---------\n";
    for (size_t j = 0; j < o.size(); ++j) {
        std::cerr << o[j] << " ";
    }
    std::cerr << "\n---------!";
    */
    return *std::min_element(o.begin(), o.end()); 
}

int main()
{
    auto cases = readTestCases(std::cin);
    for (size_t i = 0; i < cases.size(); ++i) {
        std::cout << "Case #" << (i + 1) << ": " << solve(cases[i]) << std::endl;
    }
    return 0;
}


