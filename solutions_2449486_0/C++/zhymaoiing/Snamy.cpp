#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 128;

int A[Max][Max];
int R[Max], C[Max];

void update(int& r, int d)
{
	r = max(r, d);
}

void redirectIO()
{
	string fileName;
	cin >> fileName;
	string input = fileName + ".in";
	string output = fileName + ".out";

	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
}

int main()
{
	redirectIO();

	int T;
	scanf("%d", &T);
	for (int ct = 1; ct <= T; ++ct)
	{
		int N, M;

		scanf("%d%d", &N, &M);

		memset(R, 0, sizeof(R));
		memset(C, 0, sizeof(C));

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &A[i][j]);
				update(R[i], A[i][j]);
				update(C[j], A[i][j]);
			}
		
		printf("Case #%d: ", ct);

		bool valid = true;

		//for (int i = 0; i < N; ++i)cout << R[i] << " "; cout << endl;
		//for (int i = 0; i < M; ++i)cout << C[i] << " "; cout << endl;

		for (int i = 0; i < N && valid; ++i)
			for (int j = 0; j < M && valid; ++j)
			{
				if (A[i][j] != R[i] && A[i][j] != C[j])
				{
					valid = false;
				}
			}

		puts(valid ? "YES" : "NO");
	}
}