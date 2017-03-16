#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>


std::string solve (int _x, int _y)
{
	std::string result;
	if (_x < 0) { // right
		for (int i = _x; i < 0; ++i) {
			result += "EW";
		}
	} else { // left
		for (int i = _x; i > 0; --i) {
			result += "WE";
		}
	}
	if (_y < 0) { // down
		for (int i = _y; i < 0; ++i) {
			result += "NS";
		}
	} else { // up
		for (int i = _y; i > 0; --i) {
			result += "SN";
		}
	}
	return result;
}


int main()
{
	// for small input
	int T; std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int x, y;
		std::cin >> x >> y;
		std::cout << "Case #" << t << ": " << solve (x, y) << '\n';
	}


	return 0;
}