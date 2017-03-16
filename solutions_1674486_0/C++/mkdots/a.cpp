#include <set>
#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

vector< vector<int> > g;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        int n;
        cin >> n;
        g.resize(n+1);
        vector<int> incoming(n+1);
        for (int i=0; i<n; i++)
        {
            int k;
            cin >> k;
            g[i+1].clear();
            for (int j=0; j<k; j++)
            {
                int tmp;
                cin >> tmp;
                g[i+1].push_back(tmp);                
                incoming[tmp]++;
            }
        }


        vector<int> index(n+1);
        int ind=0;
        for (int i=1; i<=n; i++)
        {
            if (incoming[i] == 0)
            {
                ind++;
                index[i]=ind;

                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (int j=0; j<g[curr].size(); j++)
                    {
                        int next = g[curr][j];
                        if (index[next] == ind)
                        {
                            goto found;
                        }

                        index[next] = ind;
                        q.push(next);
                    }

                }

            }
        }

        cout << "Case #" << t << ": No" << endl;
        continue;

found:
        cout << "Case #" << t << ": Yes" << endl;

    }
    return 0;
}
