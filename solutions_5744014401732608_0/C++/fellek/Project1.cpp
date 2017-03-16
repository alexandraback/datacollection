
#include<iostream>
#include<string>
#include<map>
using namespace std;


bool resultMatrix[50][50];

long long value[50];


int main()
{
	std::ios_base::sync_with_stdio(true);


	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {

		for (int l = 0; l < 50; l++) {
			for (int g = 0; g < 50; g++) {
				resultMatrix[l][g] = false;
			}
			value[l] = 0;
		}

		int b;
		long long m;
		cin >> b;
		cin >> m;


		long long result = 1;
		resultMatrix[0][b - 1] = true;

		value[0] = 1;


		for (int l = 0; l < b-1; l++) {
			for (int g = l+1; g < b - 1; g++) {

				if (result >= m) {
					break;
				}

				if (l != g) {

					//cout << l<<" "<< g<<" "<<value[l] << endl;

					result += value[l];
					value[g] += value[l];

					resultMatrix[l][g] = true;
					resultMatrix[g][b - 1] = true;
				}
			}
		}


		cout << "Case #" << k << ": ";

		if (result == m) {

			cout << "POSSIBLE" << endl;

			for (int l = 0; l < b; l++) {
				for (int g = 0; g < b; g++) {
					cout << resultMatrix[l][g];
				}
				cout << endl;
			}

		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}


	}

	return 0;
}

