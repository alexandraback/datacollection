#include <cstring>
#include <iostream>
using namespace std;

void solve(int t)
{
	int i, j, k, n, m, field[100][100], use[100][100], comp[100][100];

	cin >> n >> m;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin >> field[i][j];

	for(i = 1; i <= 100; i++) {
		memset(use, 0, sizeof(use));
		memset(comp, 0, sizeof(comp));

		for(j = 0; j < n; j++)
			for(k = 0; k < m; k++)
				if(field[j][k] == i)
					use[j][k] = 1;

		for(j = 0; j < n; j++) {
			for(k = 0; k < m; k++)
				if(!use[j][k])
					break;
			if(k == m)
				for(k = 0; k < m; k++)
					comp[j][k] = 1;
		}

		for(j = 0; j < m; j++) {
			for(k = 0; k < n; k++)
				if(!use[k][j])
					break;
			if(k == n)
				for(k = 0; k < n; k++)
					comp[k][j] = 1;
		}

		for(j = 0; j < n; j++) {
			for(k = 0; k < m; k++)
				if(use[j][k] != comp[j][k])
					break;
			if(k < m)
				break;
		}
		if(j < n)
			break;

		for(j = 0; j < n; j++)
			for(k = 0; k < m; k++)
				if(use[j][k])
					field[j][k] = i + 1;
	}

	if(i <= 100)
		cout << "Case #" << t << ": NO" << endl;
	else
		cout << "Case #" << t << ": YES" << endl;
}

int main(void)
{
	int i, t;
	cin >> t;
	for(i = 0; i < t; i++)
		solve(i + 1);
	return 0;
}
