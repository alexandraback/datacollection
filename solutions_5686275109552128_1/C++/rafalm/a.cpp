#include <iostream>

using namespace std;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int main()
{
	int T, test, D, P[1000], i, h, time, minT, maxH, rem;

	cin>>T;

	for(test = 1; test <= T; test++)
	{
		cin>>D;

		maxH = 0;
		for (i = 0; i < D; i++)
		{
			cin>>P[i];

			maxH = MAX(maxH, P[i]);
		}

		minT = maxH;
		for (h = 1; h <= maxH; h++)
		{
			time = h;

			for (i = 0; i < D; i++)
			{
				if (h < P[i])
				{
					rem = P[i] - h;
					time += (rem%h == 0) ? (rem/h) : (rem/h)+1;
				}
			}

			minT = MIN(minT, time);
		}

		cout<<"Case #"<<test<<": "<<minT<<endl;
	}

	return 0;
}
