#include <cstdio>

bool makeNonSuprising(int sum, int p)
{
    int ans = (sum / 3) + (sum % 3 != 0);
    return ans >= p && ans <= 10;
}

bool makeSuprising(int sum, int p)
{
    if(sum % 3 == 2) return (sum / 3) + 2 >= p && (sum / 3) + 2 <= 10;
    if(sum % 3 == 0) return (sum / 3) + 1 >= p && (sum / 3) - 1 >= 0 && (sum / 3) + 1 <= 10;
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i)
    {
        int N, S, p, answer = 0;
        scanf("%d%d%d", &N, &S, &p);

        for(int k = 0; k < N; ++k)
        {
            int sum;
            scanf("%d", &sum);

            if(makeNonSuprising(sum, p)) ++answer;
            else if(S > 0 && makeSuprising(sum, p)) --S, ++answer;
        }

        printf("Case #%d: %d\n", i + 1, answer);
    }

    return 0;
}
