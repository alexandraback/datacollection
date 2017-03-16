#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define fori(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)

#define epsilon 0.0001

int main(int argc, char** argv) {

	fstream file("qualification/files/inputDlarge.txt");
	int testCases;
	file >> testCases;
	int testCase = 1;

	while (testCases--) {
		int logs;
		file >> logs;
		vector<float> naomi;
		vector<float> ken;
		float temp;
		int cheatScore = 0;
		int normalScore = 0;
		fori(i, logs) {
			file >> temp;
			naomi.push_back(temp);
		}
		fori(i, logs) {
			file >> temp;
			ken.push_back(temp);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		/*fori(i, naomi.size())
		 cout << naomi[i] << " ";
		 cout << endl;

		 fori(i, ken.size())
		 cout << ken[i] << " ";
		 cout << endl;*/

		vector<float> naomiCopy = naomi;
		vector<float> kenCopy = ken;

		fori(i, logs) {
			if (naomi[0] < ken[0]) {
				naomi.erase(naomi.begin());
				ken.erase(ken.end() - 1);
			} else {
				naomi.erase(naomi.begin());
				ken.erase(ken.begin());
				cheatScore++;
			}
		}

		fori(i, logs) {
			if (naomiCopy[0] < kenCopy[0]) {
				naomiCopy.erase(naomiCopy.begin());
				kenCopy.erase(kenCopy.begin());
			} else {
				bool found = false;
				fori(j, kenCopy.size()) {
					if (kenCopy[j] > naomiCopy[0]) {
						kenCopy.erase(kenCopy.begin() + j);
						found = true;
						break;
					}
				}
				naomiCopy.erase(naomiCopy.begin());
				if (!found) {
					kenCopy.erase(kenCopy.begin());
					normalScore++;
				}
			}
		}

		cout << "Case #" << testCase << ": " << cheatScore << " " << normalScore
				<< endl;
		testCase++;
	}

	return 0;
}

