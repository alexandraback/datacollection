#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int n, m, k;
int cx, cy;
bool a[1000][1000];

struct P
{
    int x, y;
    P(int a, int b) : x(a), y(b) {}

    bool operator<(const P &p) const
    {
        int d1 = (x - cx) * (x - cx) + (y - cy) * (y - cy);
        int d2 = (p.x - cx) * (p.x - cx) + (p.y - cy) * (p.y - cy);
        return d1 < d2;
    }
};

int calc()
{
    int res = 0;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            if (!a[i][j])
            {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                for (int d = 0 ; d < 4 ; ++d)
                {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y])
                    {
                        ++res;
                        break;
                    }
                }
            }

    return res;
}

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        int res = 0;
        std::cin >> n >> m >> k;
        if (k < 5)
        {
            res = k;
        }
        else if (n <= 2 || m <= 2)
        {
            res = k;
        }
        else if (k >= n * m - 4)
        {
            res = (n - 2) * 2 + (m - 2) * 2 + (k - (n * m - 4));
        }
        else
        {
            cx = n / 2;
            cy = m / 2;
            std::vector<P> v;
            for (int i = 0 ; i < n ; ++i)
                for (int j = 0 ; j < m ; ++j)
                {
                    a[i][j] = false;
                    if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
                        v.push_back(P(i, j));
                }

            std::sort(v.begin(), v.end());
            int add = 0;
            for (int i = 0 ; i < (int)v.size() ; ++i)
            {
                a[v[i].x][v[i].y] = true;
                int kk = i + 1 + calc();
                if (kk >= k)
                    break;
                if (k - kk <= 1)
                {
                    add = k - kk;
                    break;
                }
            }
            res = calc() + add;
        }
        std::cout << "Case #" << t << ": " << res << "\n";
	}
	return 0;
}

