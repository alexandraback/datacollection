#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input-file>" << endl;
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        cerr << "Couldn't open file" << endl;
        return 2;
    }
    int T = 0;
    if (!fscanf(fp, "%d", &T))
        cerr << "File not valid" << endl;

    for (int case_no = 0; case_no < T; ++case_no) {
        int N, M;
        fscanf(fp, "%d %d", &N, &M);
        int heights[N][M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                fscanf(fp, "%d", &heights[i][j]);
            }
        }

        int max_row_heights[N];
        int max_column_heights[M];

        memset(max_row_heights, 0, sizeof(int) * N);
        memset(max_column_heights, 0, sizeof(int) * M);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (heights[i][j] > max_row_heights[i]) {
                    max_row_heights[i] = heights[i][j];
                }
                if (heights[i][j] > max_column_heights[j]) {
                    max_column_heights[j] = heights[i][j];
                }
            }
        }

        bool possible = true;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if ((heights[i][j] != max_column_heights[j]) && (heights[i][j] != max_row_heights[i])) {
                    possible = false;
                    break;
                }
            }
            if (!possible)
                break;
        }
        printf("Case #%d: ", case_no + 1);
        if (possible){
            printf("YES");
        } else {
            printf("NO");
        }
        printf("\n");
    }

    return 0;
}
