#include <iostream>
#include <cmath>
#include <vector>

int main () {

	std::vector<std::vector<uint64_t> > graph;
	uint64_t T;
	std::cin >> T;
	for (uint64_t t = 1; t <= T; ++t) {
		uint64_t B, M;
		std::cin >> B >> M;

		bool possible = M <= std::pow(2,B-2);
		std::cout << "Case #" << t << ": " << (possible? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
		if (possible) {
			graph.clear();
			graph.resize(B);
			for (auto& element : graph) {
				element.resize(B);
			}

			uint64_t count = 0;

			//length greater than 1
			for (int j = 0; j <= B-2; ++j) {
				if (count < M && j < B-1-j) {
					graph[j][B-1-j] = 1;
					++count;
				}
				for (int i = j+1; i <= B-2-j; ++i) {
					if (std::abs(B-2-j -(j+1)) >= 1) {
						if (count < M) {
							graph[j][i] = 1;
							graph[i][B-1-j] = 1;
							++count;
						}
					} else {
						if (count < M) {
							graph[i][B-1-j] = 1;
							++count;
						}
						if (count < M) {
							graph[j][i] = 1;
							++count;
						}
					}
				}
			}

			for (auto row : graph) {
				for (auto element : row) {
					std::cout << element;
				}
				std::cout << std::endl;
			}
		}
	}

	return 0;
}