#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;

int a[200][200];
int M, N;

int mx[200];
int my[200];

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        memset(mx, 0, sizeof(mx));
        memset(my, 0, sizeof(my));
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &a[i][j]);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                mx[i] = max(mx[i], a[i][j]);
                my[j] = max(my[j], a[i][j]);
            }
        }
        string ans = "YES";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                if (a[i][j] < mx[i] && a[i][j] < my[j] )
                {
                    ans = "NO";
                    break;
                }
            if (ans == "NO") break;
        }
        printf("Case #%d: %s\n", t + 1, ans.c_str());
    }
    return 0;
}
