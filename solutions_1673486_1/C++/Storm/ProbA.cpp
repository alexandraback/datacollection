#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);
	int z;
	cin >> z;

	for (int q=0;q<z;q++) {
		int a,b;
		cin >> a >> b;

		vector<long double> p(a);
		for (int i=0;i<a;i++) {
			cin >> p[i];
		}

		long double correct = 1.0;
		long double res = 1 + b + 1;
		for (int i=0;i<=a;i++) {
			long double steps = correct * (a - i + b - i + 1) + (1.0 - correct) * (a - i + b + 1 + b - i + 1);
			if (i < a) {
				correct *= p[i];
			}
			if (steps < res) res = steps;
		}

		cout << setprecision(10) << "Case #" << (q+1) << ": " << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}