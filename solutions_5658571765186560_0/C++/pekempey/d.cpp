#include <iostream>
#include <cstdio>
using namespace std;

int ans[4][4][4] = {
    {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
    },
    {
        { 0, 1, 0, 1 },
        { 1, 1, 1, 1 },
        { 0, 1, 0, 1 },
        { 1, 1, 1, 1 },
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 1, 1, 1 },
        { 0, 0, 1, 0 },
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 1 },
        { 0, 0, 1, 1 },
    },
};

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int X, R, C;
        cin >> X >> R >> C;
        X--;
        R--;
        C--;

        printf("Case #%d: %s\n", i, ans[X][R][C] ? "GABRIEL" : "RICHARD");
    }
}
