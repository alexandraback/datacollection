#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		long double C, F, X;
		cin >> C >> F >> X;

		long double time = 0.0;
		long double rate = 2.0;
		long double best = X / rate;
		for(int i = 0; i < 1000000; i++)
		{
			time += C / rate;
			if(time > best) break;
			rate += F;
			if(time + X / rate < best) best = time + X / rate;
		}
		printf("%.9f\n", (double)best);
	}
}
