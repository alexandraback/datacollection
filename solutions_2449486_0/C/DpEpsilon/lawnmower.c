#include <stdio.h>
#define MAX_DIM 110

#define TRUE  1
#define FALSE 0

#define MAX(A,B) ((A) > (B) ? (A) : (B))

int n_cases;

int grass[MAX_DIM][MAX_DIM];
int is_possible[MAX_DIM][MAX_DIM];

void clear_possible_array();

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "r");
    
    fscanf(fin, "%d", &n_cases);
    int test;
    for (test = 0; test < n_cases; test++) {
        int num_rows, num_cols;
        fscanf(fin, "%d %d", &num_rows, &num_cols);
        int r,c;
        for (r = 0; r < num_rows; r++) {
            for (c = 0; c < num_cols; c++) {
                fscanf(fin, "%d", &grass[r][c]);
            }
        }

        for (r = 0; r < num_rows; r++) {
            int max_num = 0;
            for (c = 0; c < num_cols; c++) {
                max_num = MAX(max_num, grass[r][c]);
            }
            for (c = 0; c < num_cols; c++) {
                if (grass[r][c] == max_num) {
                    is_possible[r][c] = TRUE;
                }
            }
        }

        for (c = 0; c < num_cols; c++) {
            int max_num = 0;
            for (r = 0; r < num_rows; r++) {
                max_num = MAX(max_num, grass[r][c]);
            }
            for (r = 0; r < num_rows; r++) {
                if (grass[r][c] == max_num) {
                    is_possible[r][c] = TRUE;
                }
            }
        }

        int possible = TRUE;
        
        for (r = 0; r < num_rows; r++) {
            for (c = 0; c < num_cols; c++) {
                if (!is_possible[r][c]) {
                    possible = FALSE;
                    break;
                }
            }
            if (!possible) {
                break;
            }
        }

        printf("Case #%d: ", test+1);
        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        clear_possible_array();
    }
    
    return 0;
}

void clear_possible_array() {
    int i,j;
    for (i = 0; i < MAX_DIM; i++) {
        for (j = 0; j < MAX_DIM; j++) {
            is_possible[i][j] = FALSE;
        }
    }
}
