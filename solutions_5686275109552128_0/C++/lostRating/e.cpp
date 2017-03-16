#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;
const int N = 100005;

long long f[N];
vector<int> e1[N], e2[N];
int v[N];

struct node
{
    int x, y, i;
};

node a[N];

bool cmpx(const node &a, const node &b)
{
    return a.x < b.x;
}

bool cmpy(const node &a, const node &b)
{
    return a.y < b.y;
}

void add(int a, int b, int c)
{
    e1[a].push_back(b);
    e2[a].push_back(c);
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y), a[i].i = i;
    sort(a + 1, a + n + 1, cmpx);
    for (int i = 1; i < n; ++i)
    {
        int v = a[i + 1].x - a[i].x;
        add(a[i].i, a[i + 1].i, v);
        add(a[i + 1].i, a[i].i, v);
    }
    sort(a + 1, a + n + 1, cmpy);
    for (int i = 1; i < n; ++i)
    {
        int v = a[i + 1].y - a[i].y;
        add(a[i].i, a[i + 1].i, v);
        add(a[i + 1].i, a[i].i, v);
    }
    for (int i = 1; i <= n; ++i)
        f[i] = 1LL << 60;
    f[1] = 0;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int a = Q.front(); Q.pop();
        v[a] = false;
        for (int i = 0; i < (int)e1[a].size(); ++i)
        {
            int j = e1[a][i];
            int k = e2[a][i];
            if (f[a] + k < f[j])
            {
                f[j] = f[a] + k;
                if (!v[j])
                {
                    v[j] = true;
                    Q.push(j);
                }
            }
        }
    }
    cout << f[n] << endl;
	return 0;
}
