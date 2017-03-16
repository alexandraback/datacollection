#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

char buf[100];
string w[100];
bool g[100][100];

string ans;

void solve(vector<int> v)
{

    stack<int> s;
    s.push(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && !g[s.top()][v[i]])
        {
            s.pop();
        }

        if (s.empty())
        {
            return;
        }

        s.push(v[i]);
    }

    //cout << "Survived" << endl;
    string tmp;
    for (int i = 0; i < v.size(); i++)
    {
        tmp = tmp + w[v[i]];
    }

    if (ans.compare(tmp) > 0)
    {
        ans = tmp;
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++)
    {
        int N, M;
        scanf("%d %d\n", &N, &M);

        ans.clear();
        for (int i = 0; i < 5 * (N + 1); i++)
        {
            ans = ans + "9";
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                g[i][j] = false;
            }
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%s", buf);
            w[i] = buf;
        }

        for (int i = 0; i < M; i++)
        {
            int x, y;
            scanf("%d %d\n", &x, &y);
            x--; y--;
            g[x][y] = g[y][x] = true;
        }


        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            v.push_back(i);
        }

        do
        {
            solve(v);
        } while (next_permutation(v.begin(), v.end()));

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
