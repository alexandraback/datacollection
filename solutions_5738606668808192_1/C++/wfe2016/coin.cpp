#include <iostream>
using namespace std;

int main()
{
	cout << "Case #1:" << endl;

	for (int i = 0; i < 500; i++)
	{
		cout << "11";
		int number = i;

		for (int j = 0; j < 9; j++)
		{
			int mod = number % 2;
			number /= 2;
			cout << mod << mod;
		}

		cout << "111111111111";

		cout << " 3 4 5 6 7 8 9 10 11" << endl;
	}

}