/* Code Jam 2014
 * Task: Reordering Train Cars
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef long long int lli;

const lli MOD = 1000000007;

lli fac(int n)
{
    lli sol = 1;
    for(int i = 2; i <= n; i++)
    {
        sol = (sol * i) % MOD;
    }

    return sol;
}

lli getSol()
{
    int sc;
    cin >> sc;
    vector<string> sets(sc);
    for(int i = 0; i < sc; i++)
    {
        cin >> sets[i];
    }

    // check for illegal chars
    vector<bool> illegalChar(26, false);
    vector<int> char2set(26);
    for(int i = 0; i < sc; i++)
    {
        for(int j = 1; j < sets[i].length() - 1; j++)
        {
            if(illegalChar[sets[i][j] - 'a'])
            {
                if(char2set[sets[i][j] - 'a'] != i)
                    return 0;
            }
            else
            {
                illegalChar[sets[i][j] - 'a'] = true;
                char2set[sets[i][j] - 'a'] = i;

                bool b = true;
                for(int k = j; k < sets[i].length(); k++)
                {
                    if(b)
                    {
                        if(sets[i][k] != sets[i][j])
                        {
                            b = false;
                        }
                    }
                    else
                    {
                        if(sets[i][k] == sets[i][j])
                        {
                            return 0;
                        }
                    }
                }
                if(b || j == 1 && sets[i][0] == sets[i][1])
                {
                    illegalChar[sets[i][j] - 'a'] = false;
                    char c = sets[i][j];
                    while(j < sets[i].length() && sets[i][j] == c)
                        j++;
                }
            }
        }
    }

    for(int i = 0; i < sc; i++)
    {
        if(illegalChar[sets[i][0] - 'a'])
        {
            if(char2set[sets[i][0] - 'a'] != i || sets[i][1] != sets[i][0])
                return 0;
        }
        if(illegalChar[sets[i][sets[i].length() - 1] - 'a'])
        {
            if(char2set[sets[i][sets[i].length() - 1] - 'a'] != i)
                return 0;
        }
    }

    for(int i = 0; i < sc; i++)
    {
        string ns = "";
        ns += sets[i][0];
        ns += sets[i][sets[i].length() - 1];
        sets[i] = ns;

        //cout << ns << endl;
    }

    vector<vector<int> > graph(sc);
    vector<vector<int> > graph2w(sc);

    for(int i = 0; i < sc; i++)
    {
        for(int j = 0; j < sc; j++)
        {
            if(i == j)
            {
                continue;
            }

            if(sets[i][1] == sets[j][0])
            {
                graph[i].push_back(j);
                graph2w[i].push_back(j);
                graph2w[j].push_back(i);
            }
        }
    }

/*
    for(int i = 0; i < sc; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << ", ";
        }
        cout << endl;
    }
*/

    int cc = 0;
    vector<set<int> > comps;
    vector<bool> visited(sc);
    queue<int> q;

    // check for loops
    for(int i = 0; i < sc; i++)
    {
        for(int j = 0; j < sc; j++)
            visited[j] = false;
        q.push(i);
        visited[i] = true;
        while(!q.empty())
        {
            int an = q.front();
            q.pop();
            //cout << an << endl;
            if(sets[an][0] == sets[an][1])
                continue;

            for(int j = 0; j < graph[an].size(); j++)
            {
                if(visited[graph[an][j]])
                {
                    if(sets[graph[an][j]][0] != sets[graph[an][j]][1])
                    {
                        return 0;
                    }
                }
                else
                {
                    visited[graph[an][j]] = true;
                    q.push(graph[an][j]);
                }
            }
        }
    }

    for(int i = 0; i < sc; i++)
        visited[i] = false;
    for(int i = 0; i < sc; i++)
    {
        if(!visited[i])
        {
            cc++;
            comps.push_back(set<int>());
            visited[i] = true;
            q.push(i);
            while(!q.empty())
            {
                int an = q.front();
                q.pop();
                comps[cc-1].insert(an);
                for(int j = 0; j < graph2w[an].size(); j++)
                {
                    if(!visited[graph2w[an][j]])
                    {
                        q.push(graph2w[an][j]);
                        visited[graph2w[an][j]] = true;
                    }
                }
            }
        }
    }

    lli sol = fac(cc);

    for(int i = 0; i < sc; i++)
        visited[i] = false;
    for(int i = 0; i < sc; i++)
    {
        if(visited[i])
            continue;

        if(sets[i][0] == sets[i][1])
        {
            visited[i] = true;
            int n = 1;
            for(int j = 0; j < sc; j++)
            {
                if(visited[j])
                    continue;

                if(sets[j][0] == sets[j][1] && sets[j][0] == sets[i][0])
                {
                    visited[j] = true;
                    n++;
                }
            }
            sol = (sol * fac(n)) % MOD;
        }
    }

    return sol;
}

int main()
{
    int tcn;
    cin >> tcn;
    for(int tc = 1; tc <= tcn; tc++)
    {
        lli sol = getSol();
        cout << "Case #" << tc << ": " << sol << endl;
    }

    return 0;
}
