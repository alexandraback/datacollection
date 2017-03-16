#include<iostream>

using namespace std;

void main()
{
	unsigned long long T, A, B, K, i, j, k, count, small, big;
	cin >> T;
	for (i = 1; i <= T; i++)
	{
		count = 0;
		cin >> A >> B >> K;
		if (A < B)
		{
			small = A;
			big = B;
		}
		else
		{
			small = B;
			big = A;
		}
		if (K < small)
		{
			count = K*(A + B - K);
			for (j = K; j < small; j++)
			for (k = K ; k < big; k++)
			if ((j&k) < K)
				count++;
		}
		else
		{
			count = small*big;
		}
		cout << "Case #" << i << ": " << count << endl;
	}
}