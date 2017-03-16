#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	cout << setprecision(10);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int A;//already writen
		cin >> A;
		int B;//Number of characters
		cin >> B;
		vector<double> failProbabilities;
		for (int i = 0; i < A; i++){
			double value;
			cin >> value;
			failProbabilities.push_back(1 - value);
		}
		//Seguir escribiendo
		double okProb = 1;
		for (int i = 0; i < failProbabilities.size(); i++){
			okProb = okProb * (1 - failProbabilities[i]);
		}
		double expected = okProb * (B - A + 1) + (1 - okProb) * (B - A + 1 + B + 1);
		double maxExpected = expected;

		//Presionar enter
		expected = (1 + B + 1);
		if (expected < maxExpected){
			maxExpected = expected;
		}

		//Borrar
		for (int i = 1; i <= A; i++){
			okProb = 1;
			for (int j = 0; j < failProbabilities.size() - i; j++){
				okProb = okProb * (1 - failProbabilities[j]);
			}
			expected = okProb * (i + i + B - A + 1) + (1 - okProb) * (i + i + B - A + 1 + B + 1);
			if (expected < maxExpected){
				maxExpected = expected;
			}
		}
		cout << "Case #" << (t+1) << ": " << maxExpected << endl;
	}
}
