#include <iostream>
#include <vector>
#include <string>

using namespace std;

static void WriteOut(const string &binary)
{
	static int primes[] = {3, 2, 5, 2, 7, 2, 3, 2, 11};

	cout << binary;
	for (int i = 2; i <= 10; ++i)
	{
		cout << " ";
		cout << primes[i - 2];
	}
	cout << endl;
}

static void HandleCase(const int cse)
{
	cout << "Case #" << cse << ":" << endl;

	int N, J;
	cin >> N >> J;
	//N = 16;
	//J = 50;

	string str;

	const char *start[] = { "1100", "1111", "1001" };
	const char *middle[] = { "1100", "0011", "1111", "1001" };
	const char *end[] = { "0011", "1111", "1001" };
	int parts = N / 4;
	int maxMiddleIndex = 1 << (parts - 2) * 2;
	int count = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int middleBits = 0; middleBits < maxMiddleIndex; ++middleBits)
		{
			str = start[i];
			for (int p = 0; p < parts - 2; ++p)
				str += middle[(middleBits >> (p * 2)) & 3];

			string s1 = str;
			for (int j = 0; j < 3; ++j)
			{
				string s2 = s1 + end[j];
				WriteOut(s2);
				++count;
				if (count == J)
					return;
			}
		}
	}
}


int main()
{
	int T;
	cin >> T;
	//T = 1;

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


