#include <iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;

string s[20];
int edges[20][20];
int a[20];
stack<int> st;
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            a[i] = i;
        }
        memset(edges, 0, sizeof edges);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u][v] = edges[v][u] = 1;
        }
        string ans = "";
        do
        {
            while (!st.empty())
                st.pop();
            st.push(a[0]);
            bool good = true;
            string tmp = s[a[0]];
            for (int i = 1; i < n; i++)
            {
                while (!st.empty() && !edges[st.top()][a[i]])
                    st.pop();
                if (st.empty())
                {
                    good = false;
                    break;
                }
                st.push(a[i]);
                tmp += s[a[i]];
            }
            //cout << tmp << endl;
            if (good)
                if (ans == "")
                    ans = tmp;
                else
                    ans = min(ans, tmp);
        }while(next_permutation(a, a + n));
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
