#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T, t;
	cin >> T;
	t = 1;
	while (T >= t)
	{
		int N;
		cin >> N;

		int list[2501] = { 0, };

		for (int i = 0; i < (N * 2 - 1) * N; i++)
		{
			int inpT;
			cin >> inpT;
			if (list[inpT] == 0)
				list[inpT] = 1;
			else
				list[inpT] = 0;
		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < 2501; i++)
		{
			if (list[i] == 1)
				cout << i << " ";
		}

		cout << endl;
		t++;
	}
}