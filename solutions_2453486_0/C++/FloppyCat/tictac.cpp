#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <stdexcept>
#include <algorithm>

namespace {
	typedef std::array<std::array<char, 4>, 4> Board;
	bool mine(char who, char cell) {
		return cell==who || cell=='T';
	}
	bool won(char who, const Board &b) {
		bool diag0 = true;
		bool diag1 = true;
		for (int i=0; i<4; i++) {
			bool col = true;
			bool row = true;
			for (int j=0; j<4; j++) {
				if (!mine(who, b[i][j]))
					row = false;
				if (!mine(who, b[j][i]))
					col = false;
			}
			if (row || col)
				return true;
			if (!mine(who, b[i][i]))
				diag0 = false;
			if (!mine(who, b[i][3-i]))
				diag1 = false;
		}
		return diag0 || diag1;
	}

	bool gameOver(const Board &b) {
		for (auto &&row : b)
			if (std::find(row.begin(), row.end(), '.')!=row.end())
				return false;
		return true;
	}
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
		Board b;
		for (int testIndex=1; testIndex<=T; testIndex++) {
			for (int y=0; y<4; y++) {
				std::getline(std::cin, line);
				if (line.size()!=4)
					throw std::runtime_error("line.size()!=4\n" + line);
				for (int x=0; x<4; x++) {
					if (line[x]!='X' && line[x]!='O' && line[x]!='T' && line[x]!='.')
						throw std::runtime_error("wrong character\n" + line);
					b[y][x] = line[x];
				}
			}
			std::getline(std::cin, line);
			if (!line.empty())
				throw std::runtime_error("!empty\n" + line);
			bool xwon = won('X', b);
			bool owon = won('O', b);
			std::cout << "Case #" << testIndex << ": ";
			if (xwon) {
				std::cout << "X won\n";
				if (owon)
					std::cerr << "both won\n";
			} else if (owon)
				std::cout << "O won\n";
			else if (gameOver(b))
				std::cout << "Draw\n";
			else
				std::cout << "Game has not completed\n";
		}
	} catch (const std::exception &ex) {
		std::cerr << "exception: " << ex.what() << std::endl;
	}
}
