#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int sgn(int n)
{
    if (n == 0)
        return 0;
    else if (n > 0)
        return 1;
    else
        return -1;
}

bool Colinear(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (sgn(p1.first) != sgn(p2.first) || sgn(p1.second) != sgn(p2.second))
        return false;

    return p1.first * p2.second == p1.second * p2.first;
}

int Square(int n)
{
	return n * n;
}

int main()
{
	ofstream cout("E:/out.txt");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int H, W, D;
        cin >> H >> W >> D;
        int height = H - 2, width = W - 2;
        int x0, y0;
        char graph[30][30];

        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                cin >> graph[i][j];

                if (graph[i][j] == 'X')
                {
                    x0 = 2 * i - 1;
                    y0 = 2 * j - 1;
                }
            }
        }

        vector<pair<int, int>> dir;

        for (int i = -D / (2 * height); i <= D / (2 * height); ++i)
        {
            for (int j = -D / (2 * width); j <= D / (2 * width); ++j)
            {
                if (Square(2 * i * height) + Square(2 * j * width) <= D * D)
                {
                    const pair<int, int> p(2 * i * height, 2 * j * width);
                    bool crash = false;

					for (const auto &x: dir)
                    {
                        if (Colinear(x, p))
                        {
                            crash = true;
                            break;
                        }
                    }

                    if (!crash)
                        dir.push_back(p);
                }
            }
        }

        for (int i = (x0 - D) / (2 * height); i <= (x0 + D) / (2 * height); ++i)
        {
            for (int j = (y0 - D) / (2 * width); j <= (y0 + D) / (2 * width); ++j)
            {
                if (Square(2 * i * height - x0) + Square(2 * j * width - y0) <= D * D)
                {
                    const pair<int, int> p(2 * i * height - x0, 2 * j * width - y0);
                    bool crash = false;

					for (const auto &x: dir)
                    {
                        if (Colinear(x, p))
                        {
                            crash = true;
                            break;
                        }
                    }

                    if (!crash)
                        dir.push_back(p);
                }
            }
        }

        for (int i = -D / (2 * height); i <= D / (2 * height); ++i)
        {
            for (int j = (y0 - D) / (2 * width); j <= (y0 + D) / (2 * width); ++j)
            {
                if (Square(2 * i * height) + Square(2 * j * width - y0) <= D * D)
                {
                    const pair<int, int> p(2 * i * height, 2 * j * width - y0);
                    bool crash = false;

					for (const auto &x: dir)
                    {
                        if (Colinear(x, p))
                        {
                            crash = true;
                            break;
                        }
                    }

                    if (!crash)
                        dir.push_back(p);
                }
            }
        }

        for (int i = (x0 - D) / (2 * height); i <= (x0 + D) / (2 * height); ++i)
        {
            for (int j = -D / (2 * width); j <= D / (2 * width); ++j)
            {
                if (Square(2 * i * height - x0) + Square(2 * j * width) <= D * D)
                {
                    const pair<int, int> p(2 * i * height - x0, 2 * j * width);
                    bool crash = false;

					for (const auto &x: dir)
                    {
                        if (Colinear(x, p))
                        {
                            crash = true;
                            break;
                        }
                    }

                    if (!crash)
                        dir.push_back(p);
                }
            }
        }

        cout << "Case #" << cases << ": " << dir.size() - 1 << endl;
    }

    cout.close();
}
