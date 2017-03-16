#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

struct D {
    int step;
    int x, y;
    string log;
    int dir;
};

void calc(int x, int y) {
    map<pair<int, pair<int, pair<int, int> > >, int> used;

    const int dd[][2] = {
        { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 },
    };
    const string dds[] = { "E", "W", "N", "S", };

    queue<D> q;
    D d;
    d.step = 1;
    d.x = d.y = 0;
    d.dir = -1;
    q.push(d);
    while (!q.empty()) {
        // printf("size:%d\n", (int)q.size());
        D d = q.front(); q.pop();

        if (used[make_pair(d.x, make_pair(d.y, make_pair(d.step, d.dir)))]++) {
            // puts("skip");
            continue;
        }
        
        if (d.x == x && d.y == y) {
            printf("%s\n", d.log.c_str());
            return;
        }

        for (int i = 0; i < 4; i++) {
            int dx = dd[i][0] * d.step;
            int dy = dd[i][1] * d.step;

            D d2;
            d2.x = d.x + dx;
            d2.y = d.y + dy;
            d2.step = d.step + 1;
            d2.log = d.log + dds[i];
            d.dir = i;            
            q.push(d2);
        }
    }
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("Case #%d: ", cc+1);
        calc(x, y);
    }
}

