#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int f[11];
int a[11];
int n;
int visited[11];
int answer = 0;
bool check(int n)
{
    for (int i = 0 ; i < n ; ++i)
        if (a[(i + n - 1) % n] == f[a[i]] || a[(i + 1) % n] == f[a[i]])
        {
            //cerr << 'ok' << endl;
        }
        else
        {
            return false;
        }
    return true;
}

bool valid(int n)
{
    for (int i = 1 ; i + 1 < n ; ++i)
        if (a[i + 1] != f[a[i]] && a[i - 1] != f[a[i]])
            return false;
    return true;
}

void dfs(int p)
{
    if (!valid(p))
        return ;
    if (check(p))
        answer = max(answer, p);
    if (p >= n)
        return ;
    for (int i = 1 ; i <= n ; ++i)
        if (!visited[i])
        {
            a[p] = i;
            visited[i] = true;
            dfs(p + 1);
            visited[i] = false;
            a[p] = 0;
        }
}

void process(int tc)
{
    cin >> n;
    answer = 0;
    for (int i = 1;  i <= n ; ++i)
        cin >> f[i];
    dfs(0);
    cout << "Case #" << tc << ": " << answer << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1 ; i <= t ; ++i)
        process(i);
    return 0;
}

