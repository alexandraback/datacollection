#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
using namespace std;

#define P pair<int,int>

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << "Case #" << i << ": ";
		// result ? 
		int A, B;
		cin >> A >> B;
		set < P > S;
		for (int j = A; j <= B; j++)
		{
			int J = j, d = 0, f = 1, C = j, t = 1;
			while (C > 0)	t *= 10, C /= 10;
			while (1)
			{
				d += f * (J % 10), f *= 10, t /= 10;
				J /= 10;
				if (J == 0)	break;
				int K = d*t + J;
				if (K >= A && K <= B && j != K)
					S.insert(P(j,K)), S.insert(P(K,j));
			}
		}
		cout << (S.size()>>1) << endl;
		S.clear();
	}
	return 0;
}
