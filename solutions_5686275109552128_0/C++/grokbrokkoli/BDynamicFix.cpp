#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

long recursiveSolution(std::vector<long> &input, std::map<std::vector<long>, int> &moves, int depth)
{
	if (moves[input] != 0) return moves[input];
	for (std::size_t i = 2, isz = input.size(); i != isz; ++i) {
		if (input[i] == 0) continue;
		for (std::size_t j = 1, jsz = i / 2 + 1; j != jsz; ++j) {
			--input[i];
			++input[i - j];
			++input[j];
			long currMin = recursiveSolution(input, moves, depth + 1);
			//Memoize
			moves[input] = currMin;
			//Reverse steps
			++input[i];
			--input[i - j];
			--input[j];
		}
	}
	moves[input] = depth;
	return depth;
}

int main()
{
	int testCases;
	std::cin >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		std::size_t plates;
		std::cin >> plates;
		std::vector<long> pancakesPerPlate(plates);
		int input, maxPancakes = 0;
		long sum = 0;
		for (int i = 0; i < plates; ++i) {
			std::cin >> input;
			pancakesPerPlate[i] = input;
			sum += input;
			if (input > maxPancakes) maxPancakes = input;
		}

		std::vector<long> platesPerPancake(maxPancakes + 1);
		for (std::size_t i = 0; i < plates; ++i) {
			++platesPerPancake[pancakesPerPlate[i]];
		}
		
		std::map<std::vector<long>, int> uniquePos;
		//Base case
		std::vector<long> base(maxPancakes + 1);
		base[1] = sum;
		recursiveSolution(platesPerPancake, uniquePos, 0);
		long answer = maxPancakes + 1;
		for (auto it = uniquePos.begin(); it != uniquePos.end(); ++it) {
			long largest = it->first.rend() - std::find_if(it->first.rbegin(), it->first.rend(), [] (long val) { return val > 0; }) - 1;
			//(special seconds) + (normal seconds)
			long currAns = it->second + largest;
			if (currAns < answer) answer = currAns;
		}

		std::cout << "Case #" << t << ": " << answer << std::endl;
	}
}
