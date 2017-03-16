#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	unsigned long int repeat;
	cin >> repeat;
	for (int i = 0; i < repeat; i++)
	{
		double C, F, X, min, currTime = 0, currRate = 2;
		cin >> C >> F >> X;

		min = X / currRate;

		while (true)
		{
			double newVal;
			currTime += C / currRate;
			currRate += F;

			newVal = currTime + (X / currRate);
			if (newVal - .00000001 > min) break;

			min = newVal;
		}

		cout << "Case #" << (i + 1) << ": " << std::fixed << std::setprecision(7) << min << endl;
	}
	return 0;
}
