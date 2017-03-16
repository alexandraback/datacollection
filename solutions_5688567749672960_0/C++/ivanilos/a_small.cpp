#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define pb push_back
#define MAXN 1000005
#define INF 0x3f3f3f3f
using namespace std;

vector <int> g[1000005];
int d[MAXN + 5];
char s[10];

void BFS(int s, int t) {
    int viz;

    memset(d, INF, sizeof(d));
    d[1] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            viz = g[i][j];
            d[viz] = min(d[viz], d[i] + 1);
        }
    }
    return;
}

int main(void) {
    int t;
    int n;
    int aux;

    for (int i = 1; i <= MAXN; i++) {
        g[i].pb(i + 1);
        sprintf(s, "%d%c", i, '\0');
        reverse(s, s + strlen(s));
        aux = atoi(s);
        if (aux > i) {
            g[i].pb(aux);
        }
    }

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d", &n);
        BFS(1, n);
        printf("Case #%d: %d\n", caso, d[n]);
    }
    return 0;
}
