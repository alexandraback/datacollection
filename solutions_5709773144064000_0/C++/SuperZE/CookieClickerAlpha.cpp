#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int p;
	cin >> p;
	std::cout.precision(9);
	double c, f, x, rate, t;
	for (int n = 1; n <= p; n++)
	{
		rate = 2;
		cin >> c >> f >> x;
		t = 0;
		while (x / rate > (c / rate) + x / (rate + f))
		{
			t += (c / rate);
			rate += f;
		}
		t += x / rate;
		cout << "Case #" << n << ": " << t << "\n";
	}
	return 0;
}

