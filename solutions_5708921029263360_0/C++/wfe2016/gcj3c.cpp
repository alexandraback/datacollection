#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		cout << "Case #" << i+1 << ": ";
		if (K == 1)
		{
			if (J == 1 && P == 1 && S == 1)
			{
				cout << 1 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
			}
			if (J == 1 && P == 1 && S == 2)
			{
				cout << 1 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
			}
			if (J == 1 && P == 2 && S == 2)
			{
				cout << 2 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
			}
			if (J == 2 && P == 2 && S == 2)
			{
				cout << 4 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
				cout << 2 << " " << 1 << " " << 2 << endl;
				cout << 2 << " " << 2 << " " << 1 << endl;
			}
			if (J == 1 && P == 1 && S == 3)
			{
				cout << 1 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
			}
			if (J == 1 && P == 2 && S == 3)
			{
				cout << 2 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
			}
			if (J == 1 && P == 3 && S == 3)
			{
				cout << 3 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
				cout << 1 << " " << 3 << " " << 3 << endl;
			}
			if (J == 2 && P == 2 && S == 3)
			{
				cout << 4 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
				cout << 2 << " " << 1 << " " << 2 << endl;
				cout << 2 << " " << 2 << " " << 1 << endl;
			}
			if (J == 2 && P == 3 && S == 3)
			{
				cout << 6 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
				cout << 1 << " " << 3 << " " << 3 << endl;
				cout << 2 << " " << 1 << " " << 2 << endl;
				cout << 2 << " " << 2 << " " << 3 << endl;
				cout << 2 << " " << 3 << " " << 1 << endl;
			}
			if (J == 3 && P == 3 && S == 3)
			{
				cout << 9 << endl;
				cout << 1 << " " << 1 << " " << 1 << endl;
				cout << 1 << " " << 2 << " " << 2 << endl;
				cout << 1 << " " << 3 << " " << 3 << endl;
				cout << 2 << " " << 1 << " " << 2 << endl;
				cout << 2 << " " << 2 << " " << 3 << endl;
				cout << 2 << " " << 3 << " " << 1 << endl;
				cout << 3 << " " << 1 << " " << 3 << endl;
				cout << 3 << " " << 2 << " " << 1 << endl;
				cout << 3 << " " << 3 << " " << 2 << endl;
			}
		}
		else if (K >= S)
		{
			cout << J * P * S << endl;
			for (int j = 1; j <= J; j++)
			{
				for (int p = 1; p <= P; p++)
				{
					for (int s = 1; s <= S; s++)
					{
						cout << j << " " << p << " " << s << endl;
					}
				}
			}
		}
		else if (J == 1 && P == 1 && S == 3 && K == 2)
		{
			cout << 2 << endl; 
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
		}
		else if (J == 1 && P == 2 && S == 3 && K == 2)
		{
			cout << 4 << endl;
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 2 << " " << 2 << endl;
		}
		else if (J == 1 && P == 3 && S == 3 && K == 2)
		{
			cout << 6 << endl;
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << " " << 3 << endl;
			cout << 1 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 3 << " " << 2 << endl;
			cout << 1 << " " << 3 << " " << 3 << endl;
		}
		else if (J == 2 && P == 2 && S == 3 && K == 2)
		{
			cout << 8 << endl;
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 2 << " " << 2 << endl;
			cout << 2 << " " << 1 << " " << 2 << endl;
			cout << 2 << " " << 1 << " " << 1 << endl;
			cout << 2 << " " << 2 << " " << 2 << endl;
			cout << 2 << " " << 2 << " " << 1 << endl;
		}
		else if (J == 2 && P == 3 && S == 3 && K == 2)
		{
			cout << 12 << endl;
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << " " << 3 << endl;
			cout << 1 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 3 << " " << 2 << endl;
			cout << 1 << " " << 3 << " " << 3 << endl;
			cout << 2 << " " << 1 << " " << 2 << endl;
			cout << 2 << " " << 1 << " " << 3 << endl;
			cout << 2 << " " << 2 << " " << 1 << endl;
			cout << 2 << " " << 2 << " " << 2 << endl;
			cout << 2 << " " << 3 << " " << 3 << endl;
			cout << 2 << " " << 3 << " " << 1 << endl;

		}
		else
		{
			cout << 18 << endl;
			cout << 1 << " " << 1 << " " << 1 << endl;
			cout << 1 << " " << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << " " << 3 << endl;
			cout << 1 << " " << 2 << " " << 1 << endl;
			cout << 1 << " " << 3 << " " << 2 << endl;
			cout << 1 << " " << 3 << " " << 3 << endl;
			cout << 2 << " " << 1 << " " << 2 << endl;
			cout << 2 << " " << 1 << " " << 3 << endl;
			cout << 2 << " " << 2 << " " << 1 << endl;
			cout << 2 << " " << 2 << " " << 2 << endl;
			cout << 2 << " " << 3 << " " << 3 << endl;
			cout << 2 << " " << 3 << " " << 1 << endl;
			cout << 3 << " " << 1 << " " << 3 << endl;
			cout << 3 << " " << 1 << " " << 1 << endl;
			cout << 3 << " " << 2 << " " << 2 << endl;
			cout << 3 << " " << 2 << " " << 3 << endl;
			cout << 3 << " " << 3 << " " << 1 << endl;
			cout << 3 << " " << 3 << " " << 2 << endl;

		}
		
	}
}