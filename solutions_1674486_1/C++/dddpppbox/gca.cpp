#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
bool dfs(vector<vector<int> >&g, int n)
{
    stack <int> open;
    set<int> closed;
    open.push(n + 1);
    while (!open.empty())
    {
        int value = open.top();
        open.pop();
        if (closed.count(value) == 1) return true;
        closed.insert(value);
        for (int i = 0; i < g[value - 1].size(); i++)
        {
            open.push(g[value - 1][i]);
        }
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    int n, cnt, tmp;
    for (int t = 0; t < T; t++)
    {
        vector<vector<int> > g;
        cout<<"Case #"<<t + 1<<": ";
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>cnt;
            vector<int> v;
            for (int j = 0; j < cnt; j++)
            {
                cin>>tmp;
                v.push_back(tmp);
            }
            g.push_back(v);
        }
        bool result = false;
        for (int i = 0; i < g.size(); i++)
        {
            if (true == dfs(g, i))
            {
                result = true;
                break;
            }
        }
        if (result == true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
