#include<iostream>

using namespace std;

void main()
{
	int T, A, B, K, i, j, k, count;
	cin >> T;
	for (i = 1; i <= T; i++)
	{
		count = 0;
		cin >> A >> B >> K;
		for (j = 0; j < A; j++)
		for (k = 0; k < B; k++)
		if ((j&k) < K)
			count++;
		cout << "Case #" << i << ": " << count << endl;
	}
}