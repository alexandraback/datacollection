#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <numeric>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <set>
#include <iomanip>

typedef std::vector<int> int_list_t;
typedef std::pair<int, int> int_pair_t;

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: safety INPUT_FILE" << std::endl;
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
        is >> N; // Contestant count

        // Contestant data
        std::vector<int> points;
        for (int j = 0; j < N; ++j) {
            int x;
            is >> x;
            points.push_back(x);
        }

        std::cout << "Case #" << i+1 << ":";

        int sum = std::accumulate(points.begin(), points.end(), 0);

        double R = 2.0 * sum / points.size();

        for (int j = 0; j < points.size(); ++j) {
            double cur = points[j];
            double y = std::max(0.0, (R - cur) / sum * 100.0);
            std::cout << std::setprecision(6) << std::fixed << " " << y;
        }

        std::cout << std::endl;


    }
}

