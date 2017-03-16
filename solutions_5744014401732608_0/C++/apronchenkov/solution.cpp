#include <iostream>
#include <set>
#include <map>

using Arc = std::pair<int, int>;
using Graph = std::set<Arc>;

/*
x00000
 x0000
  x000
   x00
    x0
*/

void PrintGraph(int number_of_vertices, const Graph& graph) {
    for (int i = 0; i < number_of_vertices; ++i) {
        for (int j = 0; j < number_of_vertices; ++j) {
            if (graph.count(Arc(i, j)) == 0) {
                std::cout << '0';
            } else {
                std::cout << '1';
            }   
        }
        std::cout << '\n';
    }
}

Graph GenerateGraph(int number_of_vertices, int bitmask) {
    Graph result;
    int b = 1;
    for (int i = 0; i < number_of_vertices; ++i) {
        for (int j = i + 1; j < number_of_vertices; ++j) {
            if (bitmask & b) {
                result.emplace(i, j);
            }
            b *= 2;
        }
    }
    return result;
}

int CountPaths(int number_of_vertices, const Graph& graph) {
    for (auto arc : graph) {
        if (arc.first >= arc.second) {
            throw std::logic_error("Unexpected graph.");
        }
    }
    std::map<int, int> dp;
    dp[0] = 1;
    for (auto arc : graph) {
        dp[arc.second] += dp[arc.first];
    }
    return dp[number_of_vertices-1];
}

Graph MakeGraphWithNumberOfPaths(int number_of_vertices, int number_of_paths) {
    const int n = (number_of_vertices - 1) * number_of_vertices / 2;
    for (int bitmask = 0; (bitmask >> n) == 0; ++bitmask) {
        auto graph = GenerateGraph(number_of_vertices, bitmask);
        //PrintGraph(number_of_vertices, graph);
        //std::cout << CountPaths(number_of_vertices, graph) << '\n';
        //std::cout << '\n';
        if (CountPaths(number_of_vertices, graph) == number_of_paths) {
            return graph;
        }
    }
    return {};
}


int main() {
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int number_of_buildings, number_of_paths;
        std::cin >> number_of_buildings >> number_of_paths;
        auto graph = MakeGraphWithNumberOfPaths(number_of_buildings, number_of_paths);
        if (graph.empty()) {
            std::cout << "Case #" << (case_no + 1) << ": IMPOSSIBLE\n";
        } else {
            std::cout << "Case #" << (case_no + 1) << ": POSSIBLE\n";
            PrintGraph(number_of_buildings, graph);
        }
    }
    return 0;
}
