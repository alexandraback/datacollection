#include <iostream>
#include <iomanip>
using namespace std;

void sort(double* data, int size) {
	double temp = 0;
	for (int i = 1; i < size; i++) {
		int j = i;
		while (data[j] < data[j - 1] && j > 0) {
			temp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = temp;
			j--;
		}
	}
}

int main() {
	int num;
	cin >> num;
	cout << fixed;

	for (int i = 0; i < num; i++) {
		int size, ans = 0;
		double c_two, c_one, t_one;
		cin >> size;
		double* data1 = new double[size]; double* data2 = new double[size];
		for (int j = 0; j < size; j++) { cin >> data1[j]; }
		for (int j = 0; j < size; j++) { cin >> data2[j]; }

		sort(data1, size);
		sort(data2, size);

		/////////////
		// OPTIMUM //
		/////////////

		int index11 = 0, index12 = size - 1, index21 = 0, index22 = size - 1;

		while (true) {
			while (data1[index11] < data2[index21] && index11 < size) {
				index11++;
			}
			// LIE, REMOVE index11 && index21
			if (index11 >= size) { break; }
			ans++;
			index11++; index21++;
		}

		cout << "Case #" << i + 1 << ": " << ans << " ";

		/////////////////
		// NON-OPTIMUM //
		/////////////////

		index11 = 0; index12 = size - 1; index21 = 0; index22 = size - 1; ans = 0;

		while (true) {
			if (data1[index12] > data2[index22]) {
				index12--;
				index21++;
				ans++;
			}
			else {
				index12--;
				index22--;
			}
			if (index12 < 0) { break; }
		}

		cout << ans << "\n";

		/*for (int j = 0; j < size; j++) { cout << std::setprecision(4) << data1[j] << ' '; }
		cout << "\n";
		for (int j = 0; j < size; j++) { cout << std::setprecision(4) << data2[j] << ' '; }
		cout << "\n";*/
	}


	return 0;
}