#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

double prob[100000];
double cumProb[100000];
int hasInput, total;
double result;

double getProb(int n) {
	int cor = total + hasInput - n - n + 1;
	int wro = cor + total + 1;

	return (double)cor * cumProb[n - 1] + (double)wro * (1 - cumProb[n - 1]);
}

int main() {
	ifstream cin("A-small-attempt1.in");
	ofstream cout("a-small.out");
	//ifstream cin("a-large.in");
	//ofstream cout("a-large.out");

	cout << fixed << setprecision(6);

	int cases;
	cin >> cases;
	
	for (int cnt = 1; cnt <= cases; cnt++) {
		cin >> hasInput >> total;

		for (int i = 0; i < hasInput; i++) {
			cin >> prob[i];
		}

		result = total + 2;

		double temp;
		cumProb[0] = prob[0];
		temp = hasInput + total + 1;
		result = min(result, temp);

		for (int i = 1; i <= hasInput; i++) {
			cumProb[i] = prob[i] * cumProb[i - 1];
			result = min(result, getProb(i));
		}

		cout << "Case #" << cnt << ": " << result << endl;
	}

	return 0;
}