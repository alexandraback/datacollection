#include <stdio.h>
#include <stdlib.h>

char coin[33];
int numPlaced = 0;
int numToPlace = 0;

void place(int oddLeft, int evenLeft, int ind, int lastInd) {
    if (ind == lastInd + 1 && !oddLeft && !evenLeft) {
        printf("%s 3 4 5 6 7 8 9 10 11\n", coin);
        numPlaced++;
        if (numPlaced == numToPlace) {
            exit(0);
        }
        return;
    }

    if (ind % 2 == 1) {
        if (oddLeft) {
            coin[ind] = '1';
            place(oddLeft - 1, evenLeft, ind + 1, lastInd);
        }
        if ((lastInd - ind) / 2 + 1 > oddLeft) {
            coin[ind] = '0';
            place(oddLeft, evenLeft, ind + 1, lastInd);
        }
    } else {
        if (evenLeft) {
            coin[ind] = '1';
            place(oddLeft, evenLeft - 1, ind + 1, lastInd);
        }
        if ((lastInd - ind) / 2 + 1 > evenLeft) {
            coin[ind] = '0';
            place(oddLeft, evenLeft, ind + 1, lastInd);
        }
    }
}

void solve(int digits, int count) {
    coin[digits] = '\0';
    coin[0] = '1';
    coin[digits - 1] = '1';

    numPlaced = 0;
    numToPlace = count;
    for (int i = 0; i <= (digits - 2) / 2; ++i) {
        place(i, i, 1, digits - 2);
    }
}

int main(void) {
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        printf("Case #%d:\n", cC + 1);
        int digits, count;
        scanf("%d%d", &digits, &count);
        solve(digits, count);
    }

    return 0;
}