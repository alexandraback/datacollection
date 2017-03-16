
#include<iostream>

using namespace std;

int col[2000];
int inher[2000][20];

bool colorup(int c, int start)
{
	if (col[start] == c)
	{
		//cout << "base met in " << start << endl;
		return true;
	}
	col[start] = c;
	for (int i = 0; i < inher[start][0]; i++)
	{
		if (colorup(c, inher[start][i+1]))
		{
			//cout << "met in " << start << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cout << "Case #" << (t+1) << ": ";

		int N;

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> inher[i][0];
			for (int j = 0; j < inher[i][0]; j++)
			{
				cin >> inher[i][j+1];
			}
			col[i] = -1;
		}

		bool is = false;
		for (int i = 1; i <= N; i++)
		{
			if (colorup(i, i))
			{
				is = true;
				break;
			}
			for (int j = 1; j < N+1; j++)
			{
				if (col[j] == i)
				{
					//cout << i << "'s family: " << j << endl;
				}
			}
		}

		if (is) cout << "Yes"; else cout << "No";
		cout << endl;
	}

	return 0;

}
