#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct coords
{
    int x, y;
    vector<char>* route;
    int jmplen;

    coords(int x_ = 0, int y_ = 0) { x = x_; y = y_; route = new vector<char>(); jmplen = 0; }
    coords(coords & other, char dir)
    {
        x = other.x;
        y = other.y;
        route = new vector<char>( *other.route );
        route->push_back(dir);

        int dist = other.jmplen + 1;
        jmplen = dist;

        switch (dir)
        {
            case 'N': y += dist; break;
            case 'S': y -= dist; break;
            case 'E': x += dist; break;
            case 'W': x -= dist; break;
        }
    }
    void read() { scanf("%d %d", &x, &y); }
};

bool operator==(coords const& a, coords const& b)
{
    return (a.x == b.x) && (a.y == b.y);
}

char flip(char c)
{
    switch (c)
    {
        case 'N': return 'S';
        case 'S': return 'N';
        case 'E': return 'W';
        case 'W': return 'E';
    }
    return '?';
}

int abs(int a) { return (a < 0) ? -a : a; }

coords dest;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);

        dest.read();
        char dir, oppos;

        if ( dest.x != 0 )
        {
            dir = (dest.x > 0) ? 'W' : 'E';
            oppos = flip(dir);

            int n_ = abs(dest.x);
            for (int i = 0; i < n_; ++i)
                printf("%c%c", dir, oppos);
        }

        if ( dest.y != 0 )
        {
            dir = (dest.y > 0) ? 'S' : 'N';
            oppos = flip(dir);

            int n_ = abs(dest.y);
            for (int i = 0; i < n_; ++i)
                printf("%c%c", dir, oppos);
        }

        printf("\n");

        /*queue<coords> Q;
        Q.push(coords(0, 0));
        while ( !Q.empty() )
        {
            coords q = Q.front(); Q.pop();

            if ( q == dest )
            {
                printf("Case #%d: ", t);
                for (int i = 0; i < int( q.route->size() ); ++i)
                    printf("%c", (*q.route)[i]);
                printf("\n");

                goto next_t;
            }

            Q.push( coords(q, 'N') );
            Q.push( coords(q, 'S') );
            Q.push( coords(q, 'E') );
            Q.push( coords(q, 'W') );
        }

        next_t:;*/
    }

    return 0;
}
