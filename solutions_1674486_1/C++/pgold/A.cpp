#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int mat[1010][1010];

int main()
{
	int T;

	scanf(" %d", &T);

	for( int _42 = 1; _42 <= T; ++_42) {
		int N;

		scanf(" %d", &N);

		memset(mat, 0, sizeof(mat));

		for(int i = 0; i < N; ++i) {
			int M;

			scanf(" %d", &M);

			for(int j = 0; j < M; ++j) {
				int f;
				scanf(" %d", &f);

				f--;

				mat[i][f]++;
			}
		}

		for(int k = 0; k < N; ++k) {
			for(int j = 0; j < N; ++j) {
				for(int i = 0; i < N; ++i) {
					mat[i][j] += mat[i][k]*mat[k][j];
				}
			}
		}

		bool diamond = false;

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(mat[i][j] > 1) diamond = true;
			}
		}

		printf("Case #%d: %s\n", _42, diamond?"Yes":"No");
	}

	return 0;
}
