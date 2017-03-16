#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int height[100][100];
    int maxInRow[100];
    int maxInCol[100];
    for (int counter = 1; counter <= T; counter++) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < 100; i++) {
            maxInRow[i] = 0;
            maxInCol[i] = 0;
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cin  >> height[r][c];
                maxInRow[r] = max(maxInRow[r], height[r][c]);
                maxInCol[c] = max(maxInCol[c], height[r][c]);
            }
        }

        bool canCut = true;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (height[r][c] < maxInRow[r] && height[r][c] < maxInCol[c]) {
                    canCut = false;
                    break;
                }
            }
            if (!canCut) {
                break;
            }
        }

        cout << "Case #" << counter << ": ";
        if (canCut){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}

