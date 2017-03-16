#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

typedef long long i64;

using namespace std;

const int maxn = 9;
char a[maxn][maxn];
int n;
vector<string> q;

bool check(vector<int> &v)
{
    stack<int> st;
    st.push(v[0]);
    for (int i = 1; i < n; ++i)
    {
        while (!st.empty() && !a[st.top()][v[i]])
            st.pop();
        if (st.empty())
            return false;
        st.push(v[i]);
    }
    return true;
}

bool cmp(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < n; ++i)
    {
        if (q[a[i]] < q[b[i]])
            return true;
        else if (q[a[i]] > q[b[i]])
            return false;
    }
    return false;

}

void print(vector<int> &a)
{
    for (int i = 0; i < n; ++i)
        cout << q[a[i]];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int qw;
    cin >> qw;
    for (int qwe = 0; qwe < qw; ++qwe)
    {
        cout << "Case #" << qwe + 1 << ": ";
        memset(a, 0, sizeof(a));
        int m;
        cin >> n >> m;
        q.assign(n, "");
        for (int i = 0; i < n; ++i)
            cin >> q[i];
        for (int i = 0; i < m; ++i)
        {
            int q, w;
            cin >> q >> w;
            q--;
            w--;
            a[q][w] = a[w][q] = true;
        }
        vector<int> ans;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = i;
        do
        {
            if (check(v))
            {
                if (ans.size() == 0 || cmp(v, ans))
                    ans = v;
            }
        }
        while (next_permutation(v.begin(), v.end()));
        print(ans);
        cout << endl;

    }
    return 0;
}
