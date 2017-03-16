#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z)
    {
        cout << "Case #" << z << ": ";
        int n, m;
        cin >> n >> m;
        vector <string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        vector <vector <int> > matr(n, vector <int> (n, 0));
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            matr[a][b] = 1;
            matr[b][a] = 1;
        }
        vector <int> p(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        string minS = "a";
        do
        {
            vector <int> stack;
            stack.push_back(p[0]);
            string curS = "";
            for (int i = 0; i < n; ++i)
                curS += s[p[i]];
            bool fll = 1;
            for (int i = 1; i < n; ++i)
            {
                bool flag = 0;
                while (stack.size() && !matr[stack.back()][p[i]])
                {
                    stack.pop_back();
                }
                if (!stack.size())
                    fll = 0;
                stack.push_back(p[i]);
            }
            if (!fll)
                continue;
            minS = min(minS, curS);
        }
        while (next_permutation(p.begin(), p.end()));
        cout << minS << "\n";
    }
    
}