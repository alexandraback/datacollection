#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int T;
int B, M;

vector< vector<int> > gr;
vector<bool> visited;

vector<int> path;
vector< vector<int> > pathes;
int total;

void dfs(int start)
{
    visited[start] = true;
    path.push_back(start + 1);

    for (int i = 0; i < B; ++i)
    {
        if (gr[start][i] == 1 && !visited[i])
        {
            if (i == B - 1 && total < M)
            {
                pathes.push_back(path);
                total++;
            }
            else dfs(i);
        }
    }

    path.pop_back();
    visited[start] = false;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T;

    for (int t = 0; t < T; ++t)
    {
        in >> B >> M;

        visited.resize(B);
        gr.assign(B, vector<int>(B, 0));

        pathes.clear();
        path.clear();
        total = 0;

        for (int i = 0; i < B; ++i)
        {
            visited[i] = false;
            for (int j = i + 1; j < B; ++j)
            {
                gr[i][j] = 1;
            }
        }

        dfs(0);

        out << "Case #" << t + 1 << ": ";

        if (total == M)
        {
            out << "POSSIBLE\n";

            vector< vector<int> > r;
            r.assign(B, vector<int>(B, 0));

            for (int i = 0; i < pathes.size(); ++i)
            {
                for (int j = 0; j < pathes[i].size() - 1; ++j)
                {
                    r[pathes[i][j] - 1][pathes[i][j + 1] - 1] = 1;
                }
                if (pathes[i].back() != B) r[pathes[i].back() - 1][B - 1] = 1;
            }

            for (int i = 0; i < B; ++i)
            {
                for (int j = 0; j < B; ++j)
                {
                    out << r[i][j];
                }
                out << endl;
            }
        }
        else
            out << "IMPOSSIBLE\n";
    }

    in.close();
    out.close();
}