
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int realPoints(int N, set<double> naomi, set<double> ken) {
	int points = 0;
	for (int i = 0; i < N; ++i) {
		double n = *naomi.begin();
		auto it = ken.lower_bound(n);
		if (it == ken.end()) {
			ken.erase(ken.begin());
			++points;
		}
		else {
			ken.erase(it);
		}
		naomi.erase(naomi.begin());
	}
	return points;
}

int cheatPoints(int N, set<double> naomi, set<double> ken) {
	int point = 0;
	for (int i = 0; i < N; ++i) {
		double ln = *naomi.rbegin();
		double lk = *ken.rbegin();
		if (ln > lk) {
			naomi.erase(--naomi.end());
			ken.erase(--ken.end());
			++point;
		}
		else {
			naomi.erase(naomi.begin());
			ken.erase(--ken.end());
		}
	}
	return point;
}

int main(int argc, char* argv[])
{
	ifstream input("C:/users/sebastien/Downloads/D-large.in");
//	ifstream input("C:/users/sebastien/Downloads/example.in");
	ofstream output("C:/users/sebastien/Downloads/output.txt");

	output.precision(16);

	int T;
	input >> T;

	for (int test = 1; test <= T; ++test) {
		cout << "test " << test << "\n";
		output << "Case #" << test << ": ";

		int N;
		input >> N;
		set<double> naomi, ken;
		for (int i = 0; i < N; ++i) {
			double d;
			input >> d;
			naomi.insert(d);
		}
		for (int i = 0; i < N; ++i) {
			double d;
			input >> d;
			ken.insert(d);
		}
		int realpoints = realPoints(N, naomi, ken);
		int cheatpoints = cheatPoints(N, naomi, ken);
		output << cheatpoints << " " << realpoints << "\n";
	}

	output.close();

	{
		cout << "DONE\n";
		int _;
		cin >> _;
	}

	return 0;
}
