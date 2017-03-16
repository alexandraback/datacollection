#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 102;
int motes[MAXN];
int init_m, motes_n;

int solve(int gr)
{
    int res = gr;
    long long curr = init_m;
    for (int pos = 0; pos < motes_n - gr; ++pos) {
        if (curr > motes[pos]) {
            curr += motes[pos];
        } else {
            curr += curr - 1;
            ++res;
            --pos;
        }
    }
    return res;
}

int solve()
{
    scanf("%d%d", &init_m, &motes_n);
    for (int i = 0; i < motes_n; ++i) {
        scanf("%d", motes + i);
    }

    if (init_m == 1) {
        return motes_n;
    }

    sort(motes, motes + motes_n);

    int res = -1, tmp_res;
    for (int gotrid = 0; gotrid <= motes_n; ++gotrid) {
        tmp_res = solve(gotrid);
        if (res == -1 || tmp_res < res)
            res = tmp_res;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: %d\n", i, solve());
    }
}
