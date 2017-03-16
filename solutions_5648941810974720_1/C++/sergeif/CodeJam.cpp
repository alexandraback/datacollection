// CodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::string s;
		std::cout << "Case #" << t << ": ";
		std::cin >> s;
		std::vector<int> number;
		std::map<char, int> ms;
		for (int i = 0; i < s.length(); ++i) {
			if (ms.find(s[i]) != ms.end()) ms[s[i]]++;
			else ms[s[i]] = 1;
			//std::cout << ms[s[i]] << std::endl;
		}
		if (ms.find('Z') != ms.end()) {
			int k = ms['Z'];
			for (int i = 0; i < k; ++i) number.push_back(0);
			ms['Z'] -= k;
			ms['E'] -= k;
			ms['R'] -= k;
			ms['O'] -= k;
		}
		if (ms.find('X') != ms.end()) {
			int k = ms['X'];
			for (int i = 0; i < k; ++i) number.push_back(6);
			ms['S'] -= k;
			ms['I'] -= k;
			ms['X'] -= k;
		}
		if (ms.find('U') != ms.end()) {
			int k = ms['U'];
			for (int i = 0; i < k; ++i) number.push_back(4);
			ms['F'] -= k;
			ms['O'] -= k;
			ms['U'] -= k;
			ms['R'] -= k;
		}
		if (ms.find('W') != ms.end()) {
			int k = ms['W'];
			for (int i = 0; i < k; ++i) number.push_back(2);
			ms['T'] -= k;
			ms['W'] -= k;
			ms['O'] -= k;
		}
		if (ms.find('O') != ms.end()) {
			int k = ms['O'];
			for (int i = 0; i < k; ++i) number.push_back(1);
			ms['O'] -= k;
			ms['N'] -= k;
			ms['E'] -= k;
		}
		if (ms.find('G') != ms.end()) {
			int k = ms['G'];
			for (int i = 0; i < k; ++i) number.push_back(8);
			ms['E'] -= k;
			ms['I'] -= k;
			ms['G'] -= k;
			ms['H'] -= k;
			ms['T'] -= k;
		}
		if (ms.find('S') != ms.end()) {
			int k = ms['S'];
			for (int i = 0; i < k; ++i) number.push_back(7);
			ms['S'] -= k;
			ms['E'] -= k;
			ms['V'] -= k;
			ms['E'] -= k;
			ms['N'] -= k;
		}
		if (ms.find('N') != ms.end()) {
			int k = ms['N'] / 2;
			for (int i = 0; i < k; ++i) number.push_back(9);
			ms['N'] -= 2 * k;
			ms['E'] -= k;
			ms['I'] -= k;
		}
		if (ms.find('V') != ms.end()) {
			int k = ms['V'];
			for (int i = 0; i < k; ++i) number.push_back(5);
			ms['F'] -= k;
			ms['I'] -= k;
			ms['V'] -= k;
			ms['E'] -= k;
		}
		if (ms.find('T') != ms.end()) {
			int k = ms['T'];
			for (int i = 0; i < k; ++i) number.push_back(3);
		}
		std::sort(number.begin(), number.end());
		for (auto i = number.begin(); i != number.end(); ++i) std::cout << *i;
		std::cout << std::endl;
	}
	return 0;
}

