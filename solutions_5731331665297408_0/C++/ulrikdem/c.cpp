#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void visit(int city, vector<int>& codes, vector<vector<int>>& flights, vector<bool>& visited, ostream& number) {
	visited[city] = true;
	number << codes[city];
	for(int next : flights[city]) {
		if(!visited[next]) {
			visit(next, codes, flights, visited, number);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int cities, count;
		cin >> cities >> count;
		vector<int> codes(cities);
		for(int& code : codes) {
			cin >> code;
		}
		vector<vector<int>> flights(cities);
		for(int counter = 0; counter < count; ++counter) {
			int from, to;
			cin >> from >> to;
			flights[from - 1].push_back(to - 1);
			flights[to - 1].push_back(from - 1);
		}
		for(auto& city : flights) {
			sort(city.begin(), city.end(), [&codes](int left, int right) {
				return codes[left] < codes[right];
			});
		}
		int first = 0;
		for(int index = 1; index < cities; ++index) {
			if(codes[index] < codes[first]) {
				first = index;
			}
		}
		vector<bool> visited(cities);
		ostringstream number;
		visit(first, codes, flights, visited, number);
		cout << "Case #" << test << ": " << number.str() << '\n';
	}
	return 0;
}
