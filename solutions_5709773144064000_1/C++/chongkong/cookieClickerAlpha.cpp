#include <iostream>

using namespace std;

double C, F, X;

double calculate() {
	double result = 0;

	for (int n = 0; true; n++) {
		double a = X / (2 + n*F);
		double b = C / (2 + n*F) + X / (2 + (n + 1)*F);

		if (a < b) {
			result += X / (2 + n*F);
			break;
		}
		else result += C / (2 + n*F);
	}
	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int CaseNum;
	cin >> CaseNum;
	for (int Case = 1; Case <= CaseNum; Case++)
	{
		cout << "Case #" << Case << ": ";

		cin >> C >> F >> X;

		cout.precision(10);
		cout.setf(ios::fixed, ios::floatfield);
		cout << calculate() << endl;
	}
}