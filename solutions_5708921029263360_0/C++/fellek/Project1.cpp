
#include<iostream>
#include<string>
#include<map>
using namespace std;



int comboJPWeared[11][11];
int comboJSWeared[11][11];
int comboPSWeared[11][11];


int main()
{
	std::ios_base::sync_with_stdio(true);



	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {

		int j, p, s, KA;

		cin >> j >> p >> s >> KA;

		for (int c1 = 1; c1 <= 10; c1++) {
			for (int c2 = 1; c2 <= 10; c2++) {
				comboJPWeared[c1][c2] = 0;
				comboJSWeared[c1][c2] = 0;
				comboPSWeared[c1][c2] = 0;
			}
		}

		int result = 0;

		for (int c1 = 1; c1 <= j; c1++) {
			for (int c2 = 1; c2 <= p; c2++) {
				for (int c3 = 1; c3 <= s; c3++) {

					if (comboJPWeared[c1][c2] < KA && comboJSWeared[c1][c3] < KA && comboPSWeared[c2][c3] < KA) {
						result++;
						comboJPWeared[c1][c2]++;
						comboJSWeared[c1][c3]++;
						comboPSWeared[c2][c3]++;
					}

				}
			}
		}

		cout << "Case #" << k << ": " << result << endl;

		for (int c1 = 1; c1 <= 10; c1++) {
			for (int c2 = 1; c2 <= 10; c2++) {
				comboJPWeared[c1][c2] = 0;
				comboJSWeared[c1][c2] = 0;
				comboPSWeared[c1][c2] = 0;
			}
		}

		for (int c1 = 1; c1 <= j; c1++) {
			for (int c2 = 1; c2 <= p; c2++) {
				for (int c3 = 1; c3 <= s; c3++) {

					if (comboJPWeared[c1][c2] < KA && comboJSWeared[c1][c3] < KA && comboPSWeared[c2][c3] < KA) {
						
						cout << c1 << " " << c2 << " " << c3 << endl;
						comboJPWeared[c1][c2]++;
						comboJSWeared[c1][c3]++;
						comboPSWeared[c2][c3]++;
					}

				}
			}
		}

	}

	return 0;
}

