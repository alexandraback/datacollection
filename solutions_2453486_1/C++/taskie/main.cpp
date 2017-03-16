//
//  main.cpp
//  GCJ
//
//  Created by taskie on 2013/04/13.
//  Copyright (c) 2013 alprosys.com. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/multi_array.hpp>

enum class Player : char { Nil, X, O, Both };

int main(int argc, const char * argv[])
{
	std::unordered_map<char, Player> charToPlayer{
		{'.', Player::Nil}, {'X', Player::X}, {'O', Player::O}, {'T', Player::Both}
	};
	using Table = boost::multi_array<Player, 2>;
	Table field(boost::extents[4][4]);
	std::string s;
	
	int numOfTestCase;
	std::cin >> numOfTestCase;
	for (int testCase : boost::irange(0, numOfTestCase)) {
		for (int j : boost::irange(0, 4)) {
			std::cin >> s;
			boost::transform(s, field[j].begin(), [&](char c){ return charToPlayer[c]; });
		}
		if (testCase + 1 != numOfTestCase) {
			std::cin.ignore();
			std::cin.ignore();
		}
		
		auto winnerFlags = static_cast<char>(Player::Nil);
		bool fieldIsFilled = true;
		for (int j : boost::irange(0, 4)) {
			using Range = Table::index_range;
			Table::index_gen indices;
			{
				Table::array_view<1>::type row = field[indices[Range(0, 4)][j]];
				char flags = static_cast<char>(Player::Both);
				for (Player p : row) {
					flags &= static_cast<char>(p);
					if (p == Player::Nil) fieldIsFilled = false;
				}
				winnerFlags |= flags;
			}
			{
				Table::array_view<1>::type row = field[indices[j][Range(0, 4)]];
				char flags = static_cast<char>(Player::Both);
				for (Player p : row) {
					flags &= static_cast<char>(p);
				}
				winnerFlags |= flags;
			}
			{
				char flags = static_cast<char>(Player::Both);
				for (int k : boost::irange(0, 4)) {
					flags &= static_cast<char>(field[k][k]);
				}
				winnerFlags |= flags;
			}
			{
				char flags = static_cast<char>(Player::Both);
				for (int k : boost::irange(0, 4)) {
					flags &= static_cast<char>(field[3 - k][k]);
				}
				winnerFlags |= flags;
			}
		}
		
		std::cout << "Case #" << testCase + 1 << ": ";
		switch (static_cast<Player>(winnerFlags)) {
			case Player::Nil:
				if (fieldIsFilled) {
					std::cout << "Draw";
				} else {
					std::cout << "Game has not completed";
				}
				break;
			case Player::X:
				std::cout << "X won";
				break;
			case Player::O:
				std::cout << "O won";
				break;
			default:
				std::cerr << "reach default";
				throw "orz";
				break;
		}
		std::cout << "\n";
	}
	std::cout << std::flush;
	
    return 0;
}

