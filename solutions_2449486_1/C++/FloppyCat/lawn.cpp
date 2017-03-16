#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> Lawn;

bool possible(const Lawn &lawn) {
	std::vector<int> rowMax(lawn.size(), 0);
	std::vector<int> colMax(lawn.front().size(), 0);
	for (size_t y=0; y<lawn.size(); y++) {
		for (size_t x=0; x<lawn.front().size(); x++) {
			rowMax[y] = std::max(rowMax[y], lawn[y][x]);
			colMax[x] = std::max(colMax[x], lawn[y][x]);
		}
	}
	for (size_t y=0; y<lawn.size(); y++)
		for (size_t x=0; x<lawn.front().size(); x++)
			if (lawn[y][x]!=std::min(rowMax[y], colMax[x]))
				return false;
	return true;
}

int main() {
	try {
		int T;
		std::string line;
		std::cin.exceptions(std::ios::failbit|std::ios::badbit);
		{
			std::getline(std::cin, line);
			std::istringstream fT(line);
			fT.exceptions(std::ios::failbit|std::ios::badbit);
			fT >> T;
		}
		for (int testIndex=1; testIndex<=T; testIndex++) {
			size_t height, width;
			{
				std::getline(std::cin, line);
				std::istringstream f(line);
				f.exceptions(std::ios::failbit|std::ios::badbit);
				f >> height >> width;
			}
			Lawn lawn(height, std::vector<int>(width));
			for (auto &row : lawn) {
				std::getline(std::cin, line);
				std::istringstream f(line);
				f.exceptions(std::ios::failbit|std::ios::badbit);
				for (size_t x=0; x<width; x++)
					f >> row[x];
			}
			std::cout << "Case #" << testIndex << ": " << (possible(lawn) ? "YES" : "NO") << std::endl;
		}
	} catch (const std::exception &ex) {
		std::cerr << "exception: " << ex.what() << std::endl;
	}
}
