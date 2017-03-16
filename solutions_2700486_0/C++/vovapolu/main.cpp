#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<pair<int, int> > points;
int n, x, y;
int val = 0;
int allval = 0;
int nowy = 2;

bool getp(pair <int, int> p)
{
    return points.count(p);
}

void insert(pair <int, int> p)
{
    points.insert(p);
}

bool erase(pair <int, int> p)
{
    points.erase(p);
}

pair<int ,int> slice(int x, int y)
{
    for(;;)
    {
        if (y == 0)
        {
            return make_pair(x, y);
        }

        if (!getp(make_pair(x + 1, y - 1)))
        {
            x = x + 1;
            y = y - 1;
        }
        else if (!getp(make_pair(x - 1, y - 1)))
        {
            x = x - 1;
            y = y - 1;
        }
        else
        {
            return make_pair(x, y);
        }
    }
}

void Go(int num)
{
    if (num >= n)
    {
        if (getp(make_pair(x, y)))
            val++;
        allval++;
        return;
    }
    bool ok = false;

    if (!getp(make_pair(-1, nowy - 1)))
    {
        ok = true;
        pair<int ,int> newp = slice(-1, nowy - 1);
        insert(newp);
        Go(num + 1);
        erase(newp);
    }

    if (!getp(make_pair(1, nowy - 1)))
    {
        ok = true;
        pair<int ,int> newp = slice(1, nowy - 1);
        insert(newp);
        Go(num + 1);
        erase(newp);
    }

    if (!ok)
    {
        insert(make_pair(0, nowy));
        nowy += 2;
        Go(num + 1);
        nowy -= 2;
        erase(make_pair(0, nowy));
    }
}

void clear()
{
    val = 0;
    allval = 0;
    nowy = 2;
    points.clear();
    insert(make_pair(0, 0));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        clear();
        cin >> n >> x >> y;
        if (n == 1 && (x != 0 || y != 0))
        {
            cout << "0.0" << endl;
            continue;
        }
        if (x == 0 && y == 0)
        {
            cout << "1.0" << endl;
            continue;
        }
        else
        {
            Go(1);
            printf("%0.10lf\n", double(val) / double(allval));
        }

    }

    return 0;
}
