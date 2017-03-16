#include <iostream>
#include <vector>
using namespace std;

long long int ipow(long long int e, long long int a) {
    if (e == 0) return 1;
    if (e == 1) return a;
    if (e & 1) return ((ipow(e - 1, a) * a));
    long long v = ipow(e / 2, a);
    return v * v;
}

long long int max(long long int a, long long int b) {
	if (a>b) {return a;}
		else
		{
			return b;
		}
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

		if (S*C<K)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			long long int sleft = S;
			long long int checking = 0;
			vector<long long int> studentnum;
			for (long long int j = 0; j < K / C; j++)
			{
				long long int number = 0;
				for (long long int k = 1; k <= C; k++)
				{
					number += min(checking, K-1) * ipow(C-k, K);
					checking += 1;
				}

				studentnum.push_back(number + 1);

				sleft -= 1;
			}

			if (K % C != 0)
			{
				sleft -= 1;
				// K, C, S is 2, 3, 2
				long long int number = 0;
				for (long long int k = 1; k <= C; k++)
				{
					number += min(checking, K - 1) *ipow(C-k, K);
					checking += 1;
				}

				studentnum.push_back(number + 1);
			}

			int index = 0;
			int number = 1;


			for (int j = 0; j < studentnum.size(); j++)
			{
				cout << studentnum[j] << " ";
			}

			cout << endl;
		}
		

	}


}