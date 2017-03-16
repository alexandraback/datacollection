#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		
		unsigned long long int r,t;
		cin >> r >> t;
		
		unsigned long long int cantCircles = 0;
		unsigned long long int pInicial = ((r+1)*2) - 1;
		unsigned long long int pd = pInicial;
		unsigned long long int k = 0;
		bool haySolucion = false;
		for (k = 0; k <= 10000; ++k)
		{
			pd = (k+1)*pInicial+2*((k+1)*k);
			if (pd > t)
			{
				haySolucion = true;
				break;
			}
		}
		if (!haySolucion)
		{
			while (pd <= t)
			{
				k+=10000;
				pd = (k+1)*pInicial+2*((k+1)*k);
			}
			for (unsigned long long int i = k-10000; i <= k; ++i)
			{
				pd = (i+1)*pInicial+2*((i+1)*i);
				if (pd > t)
				{
					k = i;
					break;
				}
			}
		}
		cout << k << endl;
	}
	return 0;
}
