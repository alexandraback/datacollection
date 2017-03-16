//
//  main.cpp
//  GCJ
//
//  Created by taskie on 2013/04/13.
//  Copyright (c) 2013 alprosys.com. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>
#include <boost/multi_array.hpp>

int main(int argc, const char * argv[])
{
	using boost::irange;
	using Table = boost::multi_array<int, 2>;
	std::string s;
	
	int numOfTestCase;
	std::cin >> numOfTestCase;
	for (int testCase : irange(1, numOfTestCase + 1)) {
		int n, m;
		std::cin >> n >> m;
		Table field(boost::extents[n][m]);
		Table::index_gen indices;
		using Range = Table::index_range;
		
		for (int i : irange(0, n)) {
			for (int j : irange(0, m)) {
				std::cin >> field[i][j];
			}
		}
		
		bool isOK = true;
		for (int i : irange(0, n)) {
			for (int j : irange(0, m)) {
				isOK = false;
				const int val = field[i][j];
				auto row = field[indices[i][Range(0, m)]];
				isOK = isOK || std::all_of(row.begin(), row.end(), [&](int x){
					return x <= val;
				});
				auto col = field[indices[Range(0, n)][j]];
				isOK = isOK || std::all_of(col.begin(), col.end(), [&](int x){
					return x <= val;
				});
				if (!isOK) break;
			}
			if (!isOK) break;
		}
		
		std::cout << "Case #" << testCase << ": ";
		std::cout << (isOK ? "YES" : "NO");
		std::cout << "\n";
	}
	std::cout << std::flush;
	
    return 0;
}

