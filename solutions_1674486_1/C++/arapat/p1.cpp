#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000 + 10;

int n, child[maxn][maxn];
bool visited[maxn];

bool dfs(int k)
{
        visited[k] = true;

        for (int i = 1; i <= child[k][0]; i++) {
                if (visited[child[k][i]])
                        return true;
                if (dfs(child[k][i]))
                        return true;
        }
        return false;
}

int main(void)
{
        int T;
        cin >> T;
        for (int loop = 1; loop <= T; loop++) {
                cin >> n;
                for (int i = 1; i <= n; i++) {
                        cin >> child[i][0];
                        for (int j = 1; j <= child[i][0]; j++)
                                cin >> child[i][j];
                }

                bool answer = false;
                for (int i = 1; !answer && i <= n; i++) {
                        memset(visited, false, sizeof(visited));
                        answer = dfs(i);
                }

                cout << "Case #" << loop << ": " << (answer ? "Yes" : "No") << endl;
        }
}
