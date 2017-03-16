#include <cstdio>
#include <vector>
#include <queue>
#define FREE 0
#define BOMB 1

using namespace std;

struct point
{
    int lin, col;

    point(int lin = 0, int col = 0): lin(lin), col(col)
    {

    }

    point operator+(point p)
    {
        return point(lin + p.lin, col + p.col);
    }
};


int a[100][100];
int r, c, m, t;
point directions[] = { point(-1, -1), point(-1, 0), point(-1, +1),
                     point(0, -1),                point(0, +1),
                     point(+1, -1), point(+1, 0), point(+1, +1)};


vector<point> getNeighbors(point current)
{
    int k;
    point neighbor;
    vector<point> neighbors;

    for (k = 0; k < 8; k++)
    {
        neighbor = current + directions[k];

        if (neighbor.lin >= 1 && neighbor.lin <= r && neighbor.col >= 1 && neighbor.col <= c)
            neighbors.push_back(neighbor);
    }

    return neighbors;
}

int countTiles(vector<point> points, int tileType)
{
    int i, cnt = 0;

    for (i = 0; i < points.size(); i++)
        if (a[points[i].lin][points[i].col] == tileType)
            cnt++;

    return cnt;
}

struct cmp
{
    bool operator()(const point & a, const point & b)
    {
        return countTiles(getNeighbors(a), BOMB) > countTiles(getNeighbors(b), BOMB);
    }
};

priority_queue<point, vector<point>, cmp> heap;
bool fillBoard(point start)
{
    int i, j;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            a[i][j] = BOMB;

    point current, neighbor;
    int freeSpots;
    int cnt;

    vector<point> neighbors;

    while (!heap.empty())
        heap.pop();

    a[start.lin][start.col] = FREE;
    heap.push(start);
    freeSpots = 1;

    while (!heap.empty() && freeSpots < r * c - m)
    {
        current = heap.top();
        heap.pop();

        neighbors = getNeighbors(current);

        cnt = countTiles(neighbors, BOMB);
        if (freeSpots + cnt <= r * c - m)
        {
            for (i = 0; i < neighbors.size(); i++)
            {
                neighbor = neighbors[i];
                if (a[neighbor.lin][neighbor.col] == BOMB)
                {
                    a[neighbor.lin][neighbor.col] = FREE;
                    heap.push(neighbor);
                }
            }
            freeSpots += cnt;
        }
    }

    return freeSpots == r * c - m;

}

void print(point p)
{
    int i, j;

    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
            if (i == p.lin && j == p.col)
                printf("c");
            else if (a[i][j] == FREE)
                printf(".");
            else if (a[i][j] == BOMB)
                printf("*");
        printf("\n");
    }
}
int main()
{
    freopen("ms.in", "r", stdin);
    freopen("ms.out", "w", stdout);

    int i, j, k;
    bool ok;

    scanf("%d", &t);

    for (k = 1; k <= t; k++)
    {
        scanf("%d%d%d", &r, &c, &m);

        printf("Case #%d:\n", k);


        ok = 0;
        for (i = 1; i <= r && !ok; i++)
            for (j = 1; j <= c && !ok; j++)
                if (fillBoard(point(i, j)))
                {
                    print(point(i, j));
                    ok = 1;
                    break;
                }
        if (!ok)
            printf("Impossible\n");
    }
    return 0;
}
