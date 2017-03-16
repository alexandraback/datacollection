#define MAXN      2000000
#define MILLION   1000000
#define TOLERANCE 10

#include <cstdio>
#include <cstring>
#include <cstdlib>

bool hash[MAXN + TOLERANCE];

int Solve( )
{
    int lo, hi;
    int ans = 0;

    scanf("%d%d", &lo, &hi);
    memset(hash, false, sizeof(hash));

    for (int i = lo; i <= hi; ++i) {
        int cnt = 1;
        int num = i;
        int bound = MILLION;

        for (int j = 7; j >= 0; --j) {
            if (num / bound != 0) {
                break;
            } else {
                bound /= 10;
            }
        }

        while(true) {
            if (num <= MAXN) {
                hash[num] = true;
            }
            num = num % 10 * bound + num / 10;
            if (num > MAXN) {
                continue;
            } else if (!hash[num] && num >= lo &&
                    num <= hi) {
                ++cnt; 
            } else if (hash[num]) {
                break;
            }
        }
        ans += cnt * (cnt - 1) / 2;
    }

    return ans;
}

void InputAndSolve( ) 
{
    int nCase;

    scanf("%d", &nCase);

    for (int caseCnt = 1; caseCnt <= nCase; ++caseCnt) {
        printf("Case #%d: %d\n", caseCnt, Solve( ));
    }
}

int main( ) 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    InputAndSolve( );

    return 0;
}
