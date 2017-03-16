#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int queueSize = 100000;
const int pathSize = 1000;

typedef struct {
    int x, y, step;
    char path[pathSize];
} node;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dn[] = {'N', 'E', 'S', 'W'};
map<string, bool> hhh;

int dstX, dstY;
node que[queueSize];

char resultpath[pathSize];

bool check(int x, int y) {
    if (x == dstX && y == dstY) return true;
    else return false;
}

void work() {
    hhh.clear();
    que[0].x = 0;
    que[0].y = 0;
    que[0].step = 0;
    int qH = 0;
    int eqH = 0;
    int eqT = 1;
    int qT = 1;
    bool found = false;
    char tmps[100];
    while (eqT > eqH) {
        if (que[qH].step >= 500) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            que[qT].step = que[qH].step + 1;
            que[qT].x = que[qH].x + dx[i] * que[qT].step;
            que[qT].y = que[qH].y + dy[i] * que[qT].step;
            memcpy(que[qT].path, que[qH].path, que[qH].step);
            que[qT].path[que[qT].step - 1] = dn[i];
            sprintf(tmps, "%d,%d", que[qT].x, que[qT].y);
            //printf("%s\n", tmps);
            if (check(que[qT].x, que[qT].y)){
                found = true;
                break;
            } else if (hhh.find(tmps) == hhh.end()) {
                hhh[tmps] = true;
                eqT++;
                qT = eqT % queueSize;
            }
        }
        eqH++;
        qH = eqH % queueSize;
        if (found) break;
    }
    if (found) {
        que[qT].path[que[qT].step] = 0;
        strcpy(resultpath, que[qT].path);
    } else {
        strcpy(resultpath, "NOT FOUND");
    }
}

int main() {
    FILE * fout = fopen("output.txt", "w");;
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d%d", &dstX, &dstY);
        work();
        printf("Case #%d: %s\n", tc, resultpath);
        fprintf(fout, "Case #%d: %s\n", tc, resultpath);
    }
    
    return 0;
}
