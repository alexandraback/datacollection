
#include <iostream>
#include <fstream>
#include <vector>

struct pair
{
	int id;
	long long num;
};


int N, M;
std::vector<pair> boxes;
std::vector<pair> toys;

long long max(long long a, long long b)
{
	return (a > b) ? a : b;
}

long long solve(int box, int toy, long long currentBoxRemaining, long long currentToyRemaining, long long produced)
{
	if (box >= N || toy >= M) {
		return produced;
	}
	
	if (currentBoxRemaining == -1) {
		currentBoxRemaining = boxes[box].num;
	}
	if (currentToyRemaining == -1) {
		currentToyRemaining = toys[toy].num;
	}

	if (boxes[box].id == toys[toy].id) {
		if (currentBoxRemaining > currentToyRemaining) {
			return solve(box, toy + 1, currentBoxRemaining - currentToyRemaining, -1, produced + currentToyRemaining);
		} else if (currentBoxRemaining < currentToyRemaining) {
			return solve(box + 1, toy, -1, currentToyRemaining - currentBoxRemaining, produced + currentBoxRemaining);
		} else {
			return solve(box + 1, toy + 1, -1, -1, produced + currentToyRemaining);
		}
	}
	
	return max(
		solve(box, toy + 1, currentBoxRemaining, -1, produced),
		solve(box + 1, toy, -1, currentToyRemaining, produced)
		);
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " inputfile" << std::endl;
		return 1;
	}
	
	std::ifstream in(argv[1]);
	
	// Get the number of test cases
	unsigned int T;
	in >> T;
	
	// Iterate through all test cases
	for (unsigned int i = 1; i <= T; i++) {
		in >> N;
		in >> M;
		
		boxes.resize(N);
		for (int n = 0; n < N; n++) {
			in >> boxes[n].num;
			in >> boxes[n].id;
		}

		toys.resize(M);
		for (int m = 0; m < M; m++) {
			in >> toys[m].num;
			in >> toys[m].id;
		}
		
		// Ouput the result
		long long result = solve(0, 0, -1, -1, 0);
		std::cout << "Case #" << i << ": " << result << std::endl;
	}
	
	return 0;
}
