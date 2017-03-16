#include <cstdio>
#include <map>

using namespace std;

int get_sum(int* S, int i)
{
    int sum = 0;
    while (i > 0)
    {
        if (i & 1) sum += *S;
        ++S;
        i >>= 1;
    }
    return sum;
}

void print_set(int* S, int i)
{
    while (i > 0)
    {
        if (i & 1)
        {
            printf("%d", *S);
            if (i == 1) putchar('\n');
            else putchar(' ');
        }
        ++S;
        i >>= 1;
    }
}

void solve()
{
    map<int, int> sums;
    int N;
    scanf("%d", &N);
    int S[N];
    for (int i = 0; i < N; ++i) scanf("%d", S + i);
    int lim = 1 << N;
    for (int i = 1; i < lim; ++i)
    {
        int sum = get_sum(S, i);
        int& prev = sums[sum];
        if (prev == 0) prev = i;
        else
        {
            print_set(S, prev);
            print_set(S, i);
            return;
        }
    }
    printf("Impossible\n");
}

int main() {
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d:\n", t);
        solve();
    }
}
