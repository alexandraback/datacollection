#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

const int maxn = 200;

int N;
int J[maxn];
int X;
double M[maxn];

void input() {

	memset(J,0,sizeof(J));
	memset(M,0,sizeof(M));

	cin >> N;
	X = 0;
	for (int i=0;i<N;i++) {
		cin >> J[i];
		X += J[i];
	}

	double tmp = X * 2 / N;
	//cout << tmp << " " << X << "\n";

	int N2 = N;
	int X2 = X;
	double tmp2 = X2 * 2;

	for (int i=0;i<N;i++) {
		if (tmp < J[i]) {
			tmp2 -= J[i];
			M[i] = 0.0;
			N2 -= 1;
		}
	}

	tmp2 /= N2;

	for (int i=0;i<N;i++) {
		if (tmp >= J[i])
			//cerr << tmp << " " << X << "\n";
			M[i] = (double(tmp2 - J[i]) / (double)X) * 100.0;
	}

}

void output(int tcase) {
	cout << "Case #" << tcase << ": ";
	for (int i=0;i<N;i++)
		cout << fixed << setprecision(6) << M[i] << " ";
	cout << "\n";
}

int main() {

	int T,tcase=0;

	cin >> T;

	while (T--) {
		tcase++;
		input();
		output(tcase);
	}

	return 0;

}