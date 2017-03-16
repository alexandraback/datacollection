#include <iostream>
using namespace std;

long long int ipow(long long int e, long long int a) {
    if (e == 0) return 1;
    if (e == 1) return a;
    if (e & 1) return ((ipow(e - 1, a) * a));
    long long v = ipow(e / 2, a);
    return v * v;
}

int main()
{
	int z;
	cin >> z;
	for (int i = 0; i < z; i++)
	{
		long long int K, C, S;
		cin >> K >> C >> S;
		cout << "Case #" << i+1 << ": ";
		cout << 1 << " ";
		for (long long int j = 1; j < K; j++)
		{
			cout << (ipow(C, K) - 1) / (K - 1) * j + 1 << " ";
		}

			cout << endl;
	}


}