#include <iostream>
using namespace std;

int main()
{
	long long int T;
	cin >> T;
	for (int a = 0; a < T; a++)
	{
		string mystring;
		cin >> mystring;
		int answer = 0;

		for (int i = 0; i < mystring.length() - 1; i++)
		{
			if (mystring[i] != mystring[i+1])
			{
				answer++;
			}
		}

		if (mystring[mystring.length() - 1] == '-')
		{
			answer++;
		}

		cout << "Case #" << a+1 << ": " << answer << endl;
	}
}