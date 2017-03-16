#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int data[1001][1001];
int cache[1001][1001];

int dfs(int x, int y)
{
    if(x == y) return 1;
    if(cache[x][y] > -1) return cache[x][y];
    int ret = 0;
    for(int i = 1; i <= data[x][0]; i++)
    {
        ret += dfs(data[x][i], y);
    }
    cache[x][y] = ret;
    return ret;
}

void func()
{
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++)
    {
        cin >> data[i][0];
        for(int j = 1; j <= data[i][0]; j++)
        {
            cin >> data[i][j];
            data[i][j]--;
        }
    }
    int find = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(dfs(i, j) > 1)
            {
                cout << "Yes" << endl;
                find = 1;
            }
            if(find) break;
        }
        if(find) break;
    }
    if(find == 0) cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++)
    {
        cout << "Case #" << ti << ": ";
        func();
    }
}
