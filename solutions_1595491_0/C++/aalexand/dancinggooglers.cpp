
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>

typedef std::vector<int> int_list_t;
typedef std::pair<int, int> int_pair_t;

// Given the score sum, return the 2-element tuple where first
// element is the maximum possible individual score for not surprising
// result and the second element is maximum possible score for a surprising
// result
int_pair_t get_scores(int x)
{
    if (x == 0) return std::make_pair(0, 0);
    int p = x / 3;
    int q = x % 3;
    switch (q) {
    case 0: return std::make_pair(p, p+1);
    case 1: return std::make_pair(p+1, p+1);
    case 2: return std::make_pair(p+1, p+2);
    default: assert(0);
    }
    return std::make_pair(-1, -1);
}



int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: dancinggooglers INPUT_FILE" << std::endl;
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
        int S;
        is >> S;
        int P;
        is >> P;

        int count = 0;
        for (int j = 0; j < N; ++j) {
            int x;
            is >> x;

            int_pair_t scores = get_scores(x);
            if (scores.first >= P) {
                // The maximum desired score is achieved even with not
                // surprising result, so no need to use the surprising count;
                count++;
            } else if (scores.second >= P && S > 0) {
                // Else if have available surprising count and can reach
                // the desired maximum count - do it.
                count++;
                S--;
            }
        }

        std::cout << "Case #" << i+1 << ": " << count << std::endl;
    }
}
