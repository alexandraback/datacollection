#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
int T, x, y, saltoActual;
char sol[100000];
bool visited[1000][1000];
int moves[][4] = {
    {0, 1, 0, -1},
    {1, 0,-1, 0}
};

char m[] = {'N', 'E', 'S', 'W'};

class par{
    public:
    int x, y;
};

bool goal(par a) {
    return a.x == x && a.y == y;
}

bool dfsl(par inic, int d, int j, int pos) {
    bool haySol = false;
    par node;
    if (d == 0 && goal(inic)) return true;
    else if (d > 0) {
        for (int i = 0; i < 4 && !haySol; i++) {
            node.x = inic.x + moves[0][i] * j;
            node.y = inic.y + moves[1][i] * j;
            if (!visited[node.x+500][node.y+500] && abs(node.x) <= abs(x) && abs(node.y) <= abs(y)) {
                //sol[pos] = m[i];
                visited[node.x+500][node.y+500] = true;
                haySol = dfsl(node, d-1, j+1, pos+1);
                if (haySol) sol[pos] = m[i];
                visited[node.x+500][node.y+500] = false;
            }
        }
        
    } else return false;
    return haySol;
}

/*void resolver() {
    int depth = 1;
    bool esSol = false;
    par inicio;
    inicio.x = 0;
    inicio.y = 0;
    while (!esSol) {
        esSol = dfsl(inicio, depth, 1, 0);
        depth++;
        printf("Cota %d\n", depth);
    }
    printf("%s\n", sol);
}*/

void resolverX() {
    int dx = abs(x), aux = saltoActual, c = 0;
    bool isE = (x > 0);
    while (true) {
        if (dx - aux >= 0) {
            dx -= aux;
            c++;
            aux += 1;
        } else {
            break;
        }
    }
    int res = (dx)*2;
    aux += res;
    if (isE) {
        for(int i = 0; i < c; i++) {
            printf("E");
        }
        bool t = true;
        for(int i = 0; i < res; i++) {
            if (t) {
                printf("W");
                t = false;
            } else {
                printf("E");
                t = true;
            }
        }
    } else {
        for(int i = 0; i < c; i++) {
            printf("W");
        }
        bool t = true;
        for(int i = 0; i < res; i++) {
            if (t) {
                printf("E");
                t = false;
            } else {
                printf("W");
                t = true;
            }
        }
    }
    saltoActual = aux;
}

void resolverY() {
    int dy = abs(y), aux = saltoActual, c = 0;
    bool isN = (y > 0);
    while (true) {
        if (dy - aux >= 0) {
            dy -= aux;
            c++;
            aux += 1;
        } else {
            break;
        }
    }
    int res = (dy)*2;
    aux += res;
    if (isN) {
        for(int i = 0; i < c; i++) {
            printf("N");
        }
        bool t = true;
        for(int i = 0; i < res; i++) {
            if (t) {
                printf("S");
                t = false;
            } else {
                printf("N");
                t = true;
            }
        }
    } else {
        for(int i = 0; i < c; i++) {
            printf("S");
        }
        bool t = true;
        for(int i = 0; i < res; i++) {
            if (t) {
                printf("N");
                t = false;
            } else {
                printf("S");
                t = true;
            }
        }
    }
    saltoActual = aux;
}

void resolver() {
    if (abs(x) > abs(y)) {
        resolverY();
        resolverX();
    } else {
        resolverX();
        resolverY();
    }
    printf("\n");
}

main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        scanf("%d %d", &x, &y);
        saltoActual = 1;
        resolver();
        //memset(sol, 0, sizeof(sol));
        //memset(visited, 0, sizeof(visited));
    }
}
