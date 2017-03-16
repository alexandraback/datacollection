#include <cstdio>
#include <algorithm>
#include <cassert>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 55;
const int INF = 1e9;
const int MR[] = { 1, 1, 1, 0, 0, -1, -1 , -1 };
const int MC[] = { -1, 0, 1, -1, 1, -1, 1, 0 };

bool mine[MAXN][MAXN], tmptab[MAXN][MAXN];
int r, c, m;
int visited[MAXN][MAXN], cast;

bool validate();
void print();

bool brute(int field, int chosen) {
    if (field >= r*c) {
        if (chosen == m && validate()) {
            print();
            return true;
        }
        return false;
    }
    if (chosen < m) {
        mine[field/c][field%c] = true;
        if (brute(field+1, chosen+1))
            return true;
    }
    
    mine[field/c][field%c] = false;
    if (brute(field+1, chosen))
        return true;
    return false;
}

int degree(int row, int col) {
    int d = mine[row][col];
    for (int i=0; i<8; i++) {
        int nr = row+MR[i], nc = col+MC[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
            if (mine[nr][nc])
                d++;
        }
    }
    return d;
}

bool find() {
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            if (degree(i, j) == 0)
                return true;
    return false;
}

void dfs(int row, int col) {
    if (visited[row][col] == cast)
        return;
    visited[row][col] = cast;
    if (degree(row, col) > 0)
        return;

    for (int i=0; i<8; i++) {
        int nr = row+MR[i], nc = col+MC[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
            dfs(nr, nc);
        }
    }
}

bool validate() {
    cast++;

    bool firedDfs = false;
    for (int i=0; i<r; i++)
        for (int j=0; j<c && !firedDfs; j++)
            if (degree(i, j) == 0)
                firedDfs = true, dfs(i, j);
    
    int count = 0;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            count += (visited[i][j] == cast);
    return count == r*c-m;

}

void print() {
    bool putC = false;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (!putC && degree(i, j) == 0)
                putC = true, printf("c");
            else
                printf("%c", mine[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        scanf("%d%d%d", &r, &c, &m);

        printf("Case #%d: \n", test);
        if (r*c-1 == m) {
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) 
                    printf("%c", i == 0 && j == 0 ? 'c' : '*');
                printf("\n");
            }
        }
        else if (!brute(0, 0))
            printf("Impossible\n");
    }
}
