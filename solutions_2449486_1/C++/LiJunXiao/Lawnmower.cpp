#include <fstream>
#include <iostream>

using namespace std;

void Lawnmower(char * fileInput, char * fileOutput) {
	ifstream input(fileInput);
	ofstream output(fileOutput);

	char buffer[10000];
	input.getline(buffer, 10000);
	int testcaseCount = atoi(buffer);

	for (int i = 0; i < testcaseCount; i++) {
		input.getline(buffer, 10000);
		int n, m;
		int height[100][100];

		n = atoi(strtok(buffer, " "));
		m = atoi(strtok(NULL, " "));

		for (int j = 0; j < n; j++) {
			input.getline(buffer, 10000);
			height[j][0] = atoi(strtok(buffer, " "));
			
			for (int k = 1; k < m; k++) {
				height[j][k] = atoi(strtok(NULL, " "));
			}
		}

		bool valid = true;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int num = height[j][k];
				bool large1 = false, large2 = false;
				for (int l = 0; l < n; l++) {
					if (height[l][k] > num) {
						large1 = true;
						break;
					}
				}
				for (int l = 0; l < m; l++) {
					if (height[j][l] > num) {
						large2 = true;
						break;
					}
				}
				if (large1 && large2) {
					valid = false;
					break;
				}
			}

			if (valid == false) {
				break;
			}
		}

		if (valid) {
			output << "Case #" << (i + 1) << ": YES" << endl;
		} else {
			output << "Case #" << (i + 1) << ": NO" << endl;
		}
	}
	
	input.close();
	output.close();
}

int main() {
	Lawnmower("B-small-attempt0.in", "Qualification Round 2013/B-test.out");
	
}
