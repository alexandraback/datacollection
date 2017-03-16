#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void test(int num)
{
	int n;
	cin >> n;
	vector<int> s(n);
	int x = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		x += s[i];
	}
	vector<double> y(n);
	for(int i = 0;i < n; i++)
		y[i] = double(2 * x - s[i] * n)/double(x*n);
	cout << "Case #" << num << ":";
	for(int i = 0; i < n; i++)
		cout << " " << max(0.0, y[i]);
	cout << "\n";
}


int main()
{
	int t;
	cin >> t;
	cout << fixed << setprecision(6);
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}

