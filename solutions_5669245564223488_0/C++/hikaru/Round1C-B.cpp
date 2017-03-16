#include <fstream>
#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <algorithm>

struct Car
{
	char B;
	char E;
	std::string s;
	Car(const std::string& s_) : s(s_), B(*s_.begin()), E(*s_.rbegin())
	{
	}
};

int solve(std::vector<Car>& cars, std::vector<bool>& used, int used_count, char c, int length)
{
	if (used_count == used.size()) {
		return length >= 2 ? 1 : 0;
	}

	int result = 0;
	for (int i=0; i<cars.size(); i++) {
		if (used[i]) continue;
		used[i]=true;
		if (c != -1 && c == cars[i].B) {
			result += solve(cars, used, used_count + 1, cars[i].E, length + 1);
		} else {
			if (length == 0 || length >= 2) {
				result += solve(cars, used, used_count + 1, cars[i].E, 1);
			}
		}
		used[i]=false;
	}
	return result;
}

int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);

	int T;
	fin >> T;
	for (int t=1; t<=T; t++) {
		int N;
		fin >> N;
		std::string s;
		std::vector<Car> cars;
		for (int n=0; n<N; n++) {
			fin >> s;
			cars.push_back(Car(s));
		}

		std::vector<bool> used(cars.size(), false);
		int result = solve(cars, used, 0, -1, 0);
		printf("Case #%d: %d\n", t, result);
	}

	return 0;
}
