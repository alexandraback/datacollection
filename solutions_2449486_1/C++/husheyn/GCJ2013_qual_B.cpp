#include <iostream>
#include <string.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int T, N, M;
int a[100][100];
int b[100][100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N >> M; 
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				cin >> a[i][j];
		memset(b, 0, sizeof(b));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
			{
				bool flag = 1;
				for(int k = 0; k < N; k++)
					if (a[i][j] < a[k][j])
						flag = 0;
				if (flag) b[i][j] = 1;
				flag = 1;
				for(int k = 0; k < M; k++)
					if (a[i][j] < a[i][k])
						flag = 0;
				if (flag) b[i][j] = 1;
			}
		bool flag = 1;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if (!b[i][j])
					flag = 0;
		if (flag) printf("Case #%d: YES\n", t);
		else printf("Case #%d: NO\n", t);
	}
	return 0;
}
