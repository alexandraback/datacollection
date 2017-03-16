#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> multTable
{
	{"1", "i", "j", "k"},
	{"i", "-1", "k", "-j"},
	{"j", "-k", "-1", "i"},
	{"k", "j", "-i", "-1"}
};

std::size_t convert(char input)
{
	switch(input) {
		case '1':
			return 0;
		case 'i':
			return 1;
		case 'j':
			return 2;
		case 'k':
			return 3;
	}
}

std::string multiply(const std::string &lhs, const std::string &rhs)
{
	std::string answer;
	if ((lhs[0] == '-' && rhs[0] != '-') || (lhs[0] != '-' && rhs[0] == '-')) {
		answer += '-';
	}
	std::size_t l = convert(lhs.size() == 2 ? lhs[1] : lhs[0]);
	std::size_t r = convert(rhs.size() == 2 ? rhs[1] : rhs[0]);
	answer += multTable[l][r];
	if (answer.size() <= 2) return answer;
	else return std::string(1, answer[2]);
}

int main()
{
	int testCases;
	std::cin >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		std::string unit;
		std::string::size_type unitSize, repetitions;
		std::cin >> unitSize >> repetitions >> unit;
		std::string unitMult("1");
		for (std::size_t i = 0, sz = unit.size(); i != sz; ++i) {
			unitMult = multiply(unitMult, std::string(1, unit[i]));
		}
		//This might not hold for repetitions % 4 == 0?
		std::string wholeStringMult = "1";
		for (std::size_t i = 0, sz = repetitions % 4; i != sz; ++i) {
			wholeStringMult = multiply(wholeStringMult, unitMult);
		}
		
		if (wholeStringMult != "-1") {
			std::cout << "Case #" << t << ": " << "NO" << std::endl;
			continue;
		}
		
		std::size_t iLocation = -1, jLocation = -1;
		std::string allPoss;
		for (int i = 0; i < 8; ++i) {
			allPoss += unit;
		}

		std::string current = "1";
		for (std::size_t i = 0, sz = allPoss.size() / 2; i != sz; ++i) {
			current = multiply(current, std::string(1, allPoss[i]));
			if (current == "i") {
				iLocation = i;
				break;
			}
		}
		if (iLocation == -1 || iLocation >= unitSize * repetitions) {
			std::cout << "Case #" << t << ": " << "NO" << std::endl;
			continue;
		}
		current = "1";
		for (std::size_t i = iLocation + 1, sz = allPoss.size(); i != sz; ++i) {
			current = multiply(current, std::string(1, allPoss[i]));
			if (current == "j") {
				jLocation = i;
				break;
			}
		}
		if (jLocation == -1 || jLocation >= unitSize * repetitions) {
			std::cout << "Case #" << t << ": " << "NO" << std::endl;
			continue;
		}
		std::cout << "Case #" << t << ": " << "YES" << std::endl;
	}
}
