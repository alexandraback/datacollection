// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream in;
	in.open("B-large.in");

	ofstream out;
	out.open("B-large.out");

	int aantal;
	in >> aantal;

	for (int oef = 1; oef <= aantal; oef++) {
		int height; int width;
		in >> height; in >> width;

		vector<vector<int> > vec(height);
		for (int i = 0; i < height; i++) {
			vec[i].resize(width);

			for (int j = 0; j < width; j++) {
				in >> vec[i][j];
			}
		}

		vector<int> maxHorizontaal(width);
		for (int j = 0; j < width; j++) {
			int lowest = vec[0][j];
			for (int i = 1; i < height; i++) {
				lowest = max(lowest, vec[i][j]);
			}
			maxHorizontaal[j] = lowest;
		}

		vector<int> maxVerticaal(height);
		for (int i = 0; i < height; i++) {
			int lowest = vec[i][0];
			for (int j = 1; j < width; j++) {
				lowest = max(lowest, vec[i][j]);
			}
			maxVerticaal[i] = lowest;
		}

		//Nu controleren of ze er allemaal aan voldoen.
		bool possible = true;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (vec[i][j] < maxVerticaal[i] && vec[i][j] < maxHorizontaal[j])
					possible = false;
			}
		}

		out << "Case #" << oef << ": " << (possible ? "YES" : "NO") << endl;

	}

	in.close();
	out.close();


	return 0;
}