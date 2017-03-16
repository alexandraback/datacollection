#include <iostream>

using namespace std;

void calculate(int m, int n, int **enclosed, int **requirement)
{
        for(int i = 3; i <= m; i++)
        {
                for(int j = 3; j <= n; j++)
                {
			enclosed[i][j] = (i * j - 4);
			requirement[i][j] = (2 * i - 4 + 2 * j - 4);
                }
        }
        return;
}

int main()
{
	int cases;
	cin >> cases;
	
	int** enclosed = new int*[351];
	for(int i = 0; i < 351; ++i)
	{
		enclosed[i] = new int[351];
	}
	int** requirement = new int*[351];
	for(int i = 0; i < 351; ++i)
	{
		requirement[i] = new int[351];
	}

	calculate(350, 350, enclosed, requirement);

	for(int i = 0; i < cases; i++)
	{
		int n, m, k;
		cin >> n;
		cin >> m;
		cin >> k;

		if((n <= 2) || (m <= 2))
		{
			cout << "Case #" << (i + 1) << ": " << k << endl;
			continue;
		}

		if(k <= 4)
		{
			cout << "Case #" << (i + 1) << ": " << k << endl;
			continue;
		}

		int min_req = k;
		for(int a = 3; a <= n; a++)
		{
			for(int b = 3; b <= m; b++)
			{
				if(k >= enclosed[a][b] && min_req > k - enclosed[a][b] + requirement[a][b])
				{
					min_req =  k - enclosed[a][b] + requirement[a][b];
				}
				if(k < enclosed[a][b] && min_req > requirement[a][b])
				{
					min_req = requirement[a][b];
				}
			}
		}
		cout << "Case #" << (i + 1) << ": " << min_req << endl;
	}

	return 0;
}
