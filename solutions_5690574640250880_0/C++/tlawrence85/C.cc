#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char output[50][51];

void placeEmpties(int empties, int rows, int cols)
{
    // First, place pairs along the top two rows;
    for (int i = 3; i < cols && empties >= 2; ++i) {
        output[0][i] = output[1][i] = '.';
        empties -= 2;
    }
    // Place pairs along the leftmost 2 cols;
    for (int i = 3; i < rows && empties >= 2; ++i) {
        output[i][0] = output[i][1] = '.';
        empties -= 2;
    }

    for (int i = 2; i < rows && empties; ++i) {
        for (int j = 2; j < cols && empties; ++j) {
            output[i][j] = '.';
            --empties;
        }
    }
}

int main(void) {
    int nC;

    scanf("%d", &nC);

    for (int cC = 1; cC <= nC; ++cC) {
        int rows, cols, mines;

        scanf("%d %d %d", &rows, &cols, &mines);

        printf("Case #%d:\n", cC);

        int empties = rows * cols - mines;
        if (empties == 1) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (i == 0 && j == 0) printf("c");
                    else printf("*");
                }
                printf("\n");
            }
        } else if (rows == 1 && cols == 1) {
            if (mines == 0)
                printf("c\n");
            else 
                printf("Impossible\n");
        } else if (rows == 1) {
            if (mines <= cols - 2) {
                printf("c.");
                for (int i = 0; i < cols - 2 - mines; ++i) printf(".");
                for (int i = 0; i < mines; ++i) printf("*");
                printf("\n");
            } else {
                printf("Impossible\n");
            }
        } else if (cols == 1) {
            if (mines <= rows - 2) {
                printf("c\n.\n");
                for (int i = 0; i < rows - 2 - mines; ++i) printf(".\n");
                for (int i = 0; i < mines; ++i) printf("*\n");
            } else {
                printf("Impossible\n");
            }
        } else if (rows == 2) {
            if (empties % 2 != 0 || empties < 4) {
                printf("Impossible\n");
            } else {
                printf("c");
                int rowE = empties / 2 - 1;
                int rowM = mines / 2;
                for (int i = 0; i < rowE; ++i) printf(".");
                for (int i = 0; i < rowM; ++i) printf("*");
                printf("\n.");
                for (int i = 0; i < rowE; ++i) printf(".");
                for (int i = 0; i < rowM; ++i) printf("*");
                printf("\n");
            }
        } else if (cols == 2) {
            if (empties % 2 != 0 || empties < 4) {
                printf("Impossible\n");
            } else {
                printf("c.\n");
                int rowE = empties / 2 - 1;
                int rowM = mines / 2;
                for (int i = 0; i < rowE; ++i) printf("..\n");
                for (int i = 0; i < rowM; ++i) printf("**\n");
            }
        } else {
            if (empties < 4 || empties == 5 || empties == 7) {
                printf("Impossible\n");
            } else {
                memset(output, '*', sizeof(output));
                for (int i = 0; i < rows; ++i) output[i][cols] = 0;
                output[0][0] = 'c';
                output[1][0] = output[1][1] = output[0][1] = '.';
                empties -= 4;

                if (empties) {
                    output[0][2] = output[1][2] = '.';
                    empties -= 2;
                    if (empties) {
                        output[2][0] = output[2][1] = '.';
                        empties -= 2;
                        if (empties) {
                            placeEmpties(empties, rows, cols);
                        }
                    }
                }

                for (int i = 0; i < rows; ++i) printf("%s\n", output[i]);
            }
        }
    }
    return 0;
}
