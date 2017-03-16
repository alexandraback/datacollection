#include <iostream>

using namespace std;

double C, F, X;

double calculate(int n) {
	double a = X / (2 + n*F);
	double b = C / (2 + n*F) + X / (2 + (n+1)*F);

	if (a < b) return a;
	else return C / (2 + n*F) + calculate(n + 1);
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
		cout << calculate(0) << endl;
	}
}