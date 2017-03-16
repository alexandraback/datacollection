#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    ifstream cin("input");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int n, m;
        vector<string> ZIP;
        vector<set<int> > G;
        cin >> n >> m;
        ZIP.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> ZIP[i];
        G.resize(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u - 1].insert(v - 1);
            G[v - 1].insert(u - 1);
        }
        string answer = "";
        vector<int> order;
        for (int i = 0; i < n; ++i)
            order.push_back(i);
        do
        {
            bool is_good = true;
            stack<int> STACK;
            STACK.push(order[0]);
            for (int i = 1; i < n; ++i)
            {
                int current = order[i];
                bool found = false;
                while (!STACK.empty() && !G[STACK.top()].count(current))
                    STACK.pop();
                if (STACK.empty())
                {
                    is_good = false;
                    break;
                }
                STACK.push(current);
            }
            if (is_good)
            {
                string current_answer = "";
                for (int i = 0; i < n; ++i)
                    current_answer += ZIP[order[i]];
                if (answer == "" || answer > current_answer)
                    answer = current_answer;
            }
        } while (next_permutation(order.begin(), order.end())) ;
        cout << "Case #" << q + 1 << ": " << answer << endl;
    }
}