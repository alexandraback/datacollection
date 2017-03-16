#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
	{
		int A;
		int B;
		int K;
		cin >> A >> B >> K;
		
		cout << "Case #" << i << ": ";
			int ways = 0;
			for (int a = 0; a < A; a++)
			{
				for (int b = 0; b < B; b++)
				{
					if ((a & b) < K)
						ways++;
				}
			}
			cout << ways << "\n";
	}
}