#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <set>

typedef std::vector<int> int_list_t;
typedef std::pair<int, int> int_pair_t;

bool aux(int_list_t& data, int_list_t& set1, int sum1, int_list_t& set2, int sum2)
{
    if (sum1 > 0 && sum1 == sum2) return true;
    if (data.empty()) return false;

    int x = data.back();
    data.pop_back();

    if (aux(data, set1, sum1, set2, sum2)) {
        return true;
    }

    set1.push_back(x);
    if (aux(data, set1, sum1 + x, set2, sum2)) {
        return true;
    }
    set1.pop_back();

    set2.push_back(x);
    if (aux(data, set1, sum1, set2, sum2 + x)) {
        return true;
    }
    set2.pop_back();

	data.push_back(x);
    return false;
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: equalsums INPUT_FILE" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream is(argv[1]);
    if (!is) {
        std::cerr << "error: the file `" << argv[1]
            << "' does not exist or is unreadable" << std::endl;
    }

    int testCount;
    is >> testCount;
    std::cerr << "processing " << testCount << " cases" << std::endl;

    for (int i = 0; i < testCount; ++i) {
        int N;
        is >> N;

        std::vector<int> data;
        for (int j = 0; j < N; ++j) {
            int x;
            is >> x;
            data.push_back(x);
        }

        int_list_t set1, set2;
        if (aux(data, set1, 0, set2, 0)) {
            std::cout << "Case #" << i+1 << ":" << std::endl;
            for (int k = 0; k < set1.size(); ++k) {
                if (k != 0) {
                    std::cout << " ";
                }
                std::cout << set1[k];
            }
            std::cout << std::endl;
            for (int k = 0; k < set2.size(); ++k) {
                if (k != 0) {
                    std::cout << " ";
                }
                std::cout << set2[k];
            }
            std::cout << std::endl;
        } else {
            std::cout << "Case #" << i+1 << ": Impossible" << std::endl;
        }
    }
}

