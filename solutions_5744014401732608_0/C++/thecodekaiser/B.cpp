// Author: thecodekaiser
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mat[55][55];

void solve(int CS)
{
	int B, M;

	cin >> B >> M;

	if(M > (((B-2) * (B-1) / 2) + 1))
	{
		printf("Case #%d: IMPOSSIBLE\n", CS);
	}
	else
	{
		printf("Case #%d: POSSIBLE\n", CS);

		memset(mat, 0, sizeof(mat));

		for(int i = 1; i <= B-1; i++)
			mat[i][i+1] = 1;

		M -= 1;
		int cur = B;

		while(M > 0)
		{
			for(int i = cur-2; i >= 1 and M > 0; i--)
			{
				mat[i][cur] = 1;
				M--;
			}

			cur -= 1;
		}


		for(int i = 1; i <= B; i++)
		{
			for(int j = 1; j <= B; j++)
			{
				cout << mat[i][j] ;
			}
			cout << endl;
		}


	}
	return;
}

int main()
{
	int t, CS = 1;
	cin >> t;

	while(t--)
		solve(CS++);

	return 0;
}