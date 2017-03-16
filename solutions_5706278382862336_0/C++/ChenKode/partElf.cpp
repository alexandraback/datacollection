#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b);

ifstream inFile("A-small-attempt0.in");
ofstream outFile("A-small-attempt0.out");

int main()
{
	int T;
	long long P, Q;
	int caseIndex, i, j;
	int result;
	char c;

	inFile >> T;
	for (caseIndex = 1; caseIndex <= T; caseIndex++)
	{
		cout << "Case #" << caseIndex << ": ";
		outFile << "Case #" << caseIndex << ": ";

		inFile >> P >> c >> Q;
		cout << endl << P << ' ' << Q << endl;

		long long tmp = gcd(P, Q);
		 P = P / tmp;
		 Q = Q / tmp;
		 cout << P << ' ' << Q << endl;

		 tmp = Q;
		 for (i = 0; i < 64; i++)
		 {
			 if (tmp - (long long)pow((double)2, i) == 0)
			 {
				 break;
			 }
		 }
		 if (i == 64)
		 {
			 cout << "impossible\n";
			 outFile << "impossible\n";
			 continue;
		 }

		 tmp = P;
		 for (j = 1; j < 64; j++)
		 {
			 if ((tmp >> j) == 0)
			 {
				 break;
			 }
		 }
		 result = i - (j - 1);
		 cout << result << endl;
		 outFile << result << endl;

	}//for (caseindex = 1; caseindex <= T; caseindex++)


	inFile.close();
	outFile.close();

	system("pause");
	return 0;
}

/* 辗转相除求最大公约数 */
long long gcd(long long a, long long b)
{
	if (a == b)
	{
		return a;
	}

	long long tmp;
	if (a < b)
	{
		b = b % a;
	}
	while (b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}