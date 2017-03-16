#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <string>

using namespace std;

const int dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};

const string dir = "NESW";

pair<char, pair<int, int> > dist[600][220][220];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        for (int i = 0; i < 600; i++)
            for (int j = 0; j < 220; j++)
                for (int k = 0; k < 220; k++)
                    dist[i][j][k].first = '\0';
        queue<pair<int, pair<int, int> > > q;
        int x, y;
        cin >> x >> y;
        x += 100; y += 100;
        dist[0][100][100] = make_pair('\1', make_pair(0, 0));
        q.push(make_pair(0, make_pair(100, 100)));
        int ans;
        while (!q.empty())
        {
            pair<int, int> node = q.front().second;
            int d = q.front().first;
            if (node.first == x && node.second == y)
            {
                ans = d;
                break;
            }
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> next(node.first + dx[i] * (d + 1), node.second + dy[i] * (d + 1));
                if (dist[d + 1][next.first][next.second].first == '\0')
                {
                    dist[d + 1][next.first][next.second].first = dir[i];
                    dist[d + 1][next.first][next.second].second = node;
                    q.push(make_pair(d + 1, next));
                }
            }
        }
        stack<char> st;
        cout << "Case #" << C << ": ";
        while (ans)
        {
            st.push(dist[ans][x][y].first);
            int nx = dist[ans][x][y].second.first;
            int ny = dist[ans][x][y].second.second;
            x = nx;
            y = ny;
            ans--;
        }
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << '\n';
    }
}

