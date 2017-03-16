#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int fact(int n)
{
	int k = 1;
	for (int i = 2; i <= n; i++) k *= i;
	return k;
}

int combination(int n, int k)
{
	return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, X, Y;
		cin >> N >> X >> Y;

		int base = 0.5 * sqrt(8.0 * N + 1.0) - 0.5;
		if ((base & 1) == 0) base--;

		int inner = base * (base + 1) / 2;
		int outer = N - inner;
		int layers = (base - 1) / 2 + 1;

		//cout << endl;
		//cout << N << endl;
		//cout << "Base: " << base << endl;
		//cout << "Inner: " << inner << endl;
		//cout << "Outer: " << outer << endl;
		//cout << "Layers: " << layers << endl;

		double probability = 0.0;

		int distance = abs(X) + abs(Y);
		if ((distance & 1) == 1)
			probability = 0.0;
		else if (distance < layers * 2)
			probability = 1.0;
		else if (distance > layers * 2)
			probability = 0.0;
		else if (outer == 0)
			probability = 0.0;
		else 
		{
			int options = outer + 1;

			int mx = base + 2;
			int mn = std::max(options - mx, 0);
			if (options > mx)
				options = mx - (options - mx);

			//cout << "mx: " << mx << endl;
			//cout << "mn: " << mn << endl;

			if (mn > Y)
				probability = 1.0;
			else
			{
				//cout << "Options: " << options << endl;
				int top = options - Y - 1 + mn;

				int totalTop = 0, totalBottom = 0;

				for (int i = 0; i < options; i++)
				{
					int c = combination(options - 1, i);
					if (i < top) totalTop += c;
					totalBottom += c;
				}

				probability = (double)totalTop / (double)totalBottom;
				//cout << top << " / " << options << endl;
				//cout << totalTop << " / " << totalBottom << endl;
			}
		}

		cout << "Case #" << t << ": " << probability << endl;
	}
}
