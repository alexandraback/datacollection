#include <cstdio>
#include <vector>

int main() {
    bool flag;
    unsigned tests;
    unsigned a, b, l[10][10];
    std::vector<unsigned> probRows, probCols;

    scanf("%u", &tests);
    for(int t = 0; t < tests; ++t) {
        probRows.clear();
        probCols.clear();

        scanf("%u %u", &a, &b);
        for(int x = 0; x < a; ++x) {
            for(int y = 0; y < b; ++y) {
                scanf("%u", *(l+x)+y);
                if(l[x][y] == 2) {
                    probRows.push_back(x);
                    probCols.push_back(y);
                }
            }
        }

        flag = true;
        for(int i = 0; i < probRows.size() && flag; ++i)
            for(int j = 0; j < probCols.size() && flag; ++j)
                flag = (l[probRows[i]][probCols[j]] != 1);

        if(flag)        printf("Case #%u: YES\n", t+1);
        else            printf("Case #%u: NO\n", t+1);
    }
    return 0;
}
