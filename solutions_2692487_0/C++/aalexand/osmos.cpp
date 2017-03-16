
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int solve(int A, vector<int> motes)
{
    if (A == 1) {
        return motes.size(); // The best we can is remove all motes
    }
    int moves_so_far = 0;
    int moves_min = INT_MAX;
    sort(motes.begin(), motes.end());
    for (int i = 0; i < motes.size(); ++i) {
        if (A > motes[i]) {
            A += motes[i];
        } else {
            moves_min = min(moves_min, moves_so_far + (int)motes.size() - i);
            while (A <= motes[i]) {
                A += A-1;
                moves_so_far += 1;
            }
            A += motes[i];
        }
    }
    moves_min = min(moves_min, moves_so_far);
    return moves_min;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {

        int A;
        scanf("%d", &A);
        int N;
        scanf("%d", &N);

        vector<int> motes;
        for (int j = 0; j < N; ++j) {
            motes.push_back(0);
            scanf("%d", &motes.back());
        }

        printf("Case #%d: %d\n", i+1, solve(A, motes));
    }
}

