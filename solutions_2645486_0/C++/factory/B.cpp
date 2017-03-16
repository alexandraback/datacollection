#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    FILE *fin, *fout;

    fin = fopen ("input.txt", "r");
    fout = fopen ( "output.txt", "w");

    int T;
    fscanf (fin, "%d", &T);
    for (int t = 1; t <= T; ++ t) {
        int E, R, N;
        fscanf (fin, "%d %d %d", &E, &R, &N);
		vector<int> data;
        for (int i = 0; i < N; ++ i) {
			int tmp;
			fscanf (fin, "%d", &tmp);
            data.push_back(tmp);
        }

        vector<vector<int> > d (N, vector<int> (E + 1, 0));
		for (int i = 0; i <= E; ++ i) {
			d[0][i] = data[0] * (E - i);
        }
		for (int i = 1; i < N; ++ i) {
			for (int j = 0; j <= E; ++ j) {
				d[i][j] = 0;
                for (int k = 0; k <= E; ++ k) {
					int rem = min(k + R, E);
					if (rem < j) continue;
					d[i][j] = max(d[i][j], d[i - 1][k] + (rem - j) * data[i]);
                }
            }
        }
        fprintf (fout, "Case #%d: %d\n", t, d[N - 1][0]);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
