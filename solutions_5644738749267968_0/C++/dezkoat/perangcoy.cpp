#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

// float/double is inacurate
int block1[2000];
int block2[2000];

int readInt(char *in)
{
    int ret = 0;
    int l = 2;
    while (*(in+l) != 0) {
        ret *= 10;
        ret += *(in+l) - '0';
        l++;
    }

    for (int i = l; i < 8; i++)
        ret *= 10;

    return ret;
}

int main()
{
    int T;
    cin >> T;

    char in[10];
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> in;
            block1[j] = readInt(in);
        }
        for (int j = 0; j < N; j++) {
            cin >> in;
            block2[j] = readInt(in);
        }

        sort(block1, block1+N);
        sort(block2, block2+N);

        // deceitful war
        int score1 = 0;
        int r1 = N-1;
        int r2 = N-1;
        while (r1 >= 0 && r2 >= 0) {
            if (block1[r1] > block2[r2]) {
                r1--;
                score1++;
            }
            r2--;
        }

        // war
        int score2 = 0;
        r1 = N-1;
        r2 = N-1;
        while (r1 >= 0 && r2 >= 0) {
            if (block1[r1] < block2[r2]) {
                r2--;
            } else {
                score2++;
            }
            r1--;
        }

        cout << "Case #" << i << ": " << score1 << " " << score2 << endl;
    }

    return 0;
}
