#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>

typedef std::vector<int> V;

int best[50];
int res[50];
int zip[50];
int n, m;
bool f[50][50];
bool r[50][50];
bool used[50];
int num;

void find(int c, V v)
{
    bool u = used[c];
    if (!u)
    {
        res[n - num] = c;
        --num;
    }
    used[c] = true;
    if (num == 0)
    {
        int i = 0;
        if (best[0] >= 0)
            for ( ; i < n && zip[best[i]] == zip[res[i]] ; ++i)
                ;
        if (best[0] < 0 || (i < n && zip[best[i]] > zip[res[i]]))
            for (int i = 0 ; i < n ; ++i)
                best[i] = res[i];
    }
    else
    {
        for (int i = 0 ; i < n ; ++i)
            if (!used[i] && f[c][i])
            {
                v.push_back(i);
                find(i, v);
                v.pop_back();
            }
        // try return
        if (v.size() > 1)
        {
            v.pop_back();
            find(v.back(), v);
            v.push_back(c);
        }
    }
    used[c] = u;
    if (!u)
    {
        ++num;
    }
}

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        std::cin >> n >> m;
        num = n;
        for (int i = 0 ; i < n ; ++i)
        {
            std::cin >> zip[i];
            used[i] = false;
            best[i] = -1;
            for (int j = 0 ; j < n ; ++j)
                f[i][j] = r[i][j] = false;
        }
        for (int i = 0 ; i < m ; ++i)
        {
            int x, y;
            std::cin >> x >> y;
            f[x - 1][y - 1] = true;
            f[y - 1][x - 1] = true;
        }
        for (int i = 0 ; i < n ; ++i)
        {
            V v(1, i);
            find(i, v);
        }
        std::cout << "Case #" << t << ": ";
        for (int i = 0 ; i < n ; ++i)
            std::cout << zip[best[i]];
        std::cout << "\n";
	}
	return 0;
}

