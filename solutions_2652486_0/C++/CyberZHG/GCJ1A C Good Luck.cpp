#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, N, M, K;
bool findAns;
int ans[20];
double dist;
int path[20];
int pathProduct[20];
double pathProbability[20];
int product[20];
double probability[20];
bool visit[20];

void dfs1(int start, int depth)
{
    if (depth >= N)
    {
        memset(visit, false, sizeof(visit));
        double totalProbability = 0.0;
        for (int i = 0; i < (1 << N); ++i)
        {
            int temp = 1;
            for (int j = 0; j < N; ++j)
            {
                if (i & (1 << j))
                {
                    temp *= path[j];
                }
            }
            pathProduct[i] = temp;
            for (int j = 0; j < K; ++j)
            {
                if (temp == product[j])
                {
                    visit[j] = true;
                }
            }
        }
        for (int i = 0; i < K; ++i)
        {
            if (!visit[i])
            {
                return;
            }
        }
        for (int i = 0; i < (1 << N); ++i)
        {
            bool appear = false;
            for (int j = 0; j < i; ++j)
            {
                if (pathProduct[i] == pathProduct[j])
                {
                    pathProbability[j] = pathProbability[i];
                    appear = true;
                    break;
                }
            }
            if (!appear)
            {
                int cnt = 1;
                for (int j = i + 1; j < (1 << N); ++j)
                {
                    if (pathProduct[j] == pathProduct[i])
                    {
                        ++cnt;
                    }
                }
                pathProbability[i] = 1.0 * cnt / (1 << N);
            }
        }
        double pathDist = 0.0;
        for (int i = 0; i < K; ++i)
        {
            bool appear = false;
            for (int j = 0; j < i; ++j)
            {
                if (product[i] == product[j])
                {
                    appear = true;
                    break;
                }
            }
            if (!appear)
            {
                for (int j = 0; j < (1 << N); ++j)
                {
                    if (product[i] == pathProduct[j])
                    {
                        double temp = probability[i] - pathProbability[j];
                        pathDist += temp * temp;
                    }
                }
            }
        }
        if (!findAns || pathDist < dist)
        {
            findAns = true;
            for (int i = 0; i < N; ++i)
            {
                ans[i] = path[i];
                dist = pathDist;
            }
        }
        return;
    }
    for (int i = start; i <= M; ++i)
    {
        path[depth] = i;
        dfs1(i, depth + 1);
    }
}

int main()
{
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        printf("Case #%d:\n", t);
        scanf("%d%d%d%d", &R, &N, &M, &K);
        while (R--)
        {
            for (int i = 0; i < K; ++i)
            {
                scanf("%d", &product[i]);
            }
            for (int i = 0; i < K; ++i)
            {
                bool appear = false;
                for (int j = 0; j < i; ++j)
                {
                    if (product[i] == product[j])
                    {
                        probability[j] = probability[i];
                        appear = true;
                        break;
                    }
                }
                if (!appear)
                {
                    int cnt = 1;
                    for (int j = i + 1; j < K; ++j)
                    {
                        if (product[j] == product[i])
                        {
                            ++cnt;
                        }
                    }
                    probability[i] = 1.0 * cnt / (1 << N);
                }
            }
            findAns = false;
            dfs1(2, 0);
            for (int i = 0; i < N; ++i)
            {
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
