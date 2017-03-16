#include<bits/stdc++.h>
using namespace std;

void solveTc(int tc) {
    int r, c, w;
    cin >> r >> c >> w;
    int p = w - 1,
        neededPerRow = 1;
    while(p + w < c) {
        p += w;
        neededPerRow++;
    }

    int res = 0;
    if(p < c - 1)
        res++;

    res += w - 1;
    res += r * neededPerRow;

    printf("Case #%d: %d\n", tc, res);
}
int main() {
    int z;
    cin >> z;
    for(int i = 1; i <= z; i++)
        solveTc(i);
}
