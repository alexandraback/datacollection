#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void fill_all(int num_rows, int num_cols) {
    char map[60][60];
    memset(map, '*', sizeof(map));
    map[0][0] = 'c';
    for (int i = 0; i < num_rows; ++i) {
        map[i][num_cols] = 0;
        puts(map[i]);
    }
}

int mark(char map[][60], int x, int y, int num_rows, int num_cols, int test) {
    int c = 0;
    static int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    static int dir_y[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    for (int i = 0; i < sizeof(dir_x) / sizeof(dir_x[0]); ++i) {
        int _x = x + dir_x[i];
        int _y = y + dir_y[i];
        if (_x < 0 || _x >= num_rows || _y < 0 || _y >= num_cols)
            continue;
        if (map[_x][_y] == '*') {
            c++;
            if (!test)
                map[_x][_y] = '.';
        }
    }
    return c;
}

int check(char org_map[][60], int num_rows, int num_cols, int num_mines) {
    static char map[60][60];

    int change = 1;
    int c;
    int x, y;
    static int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int dir_y[] = {0, -1, -1, -1, 0, 1, 1, 1};
    memcpy(map, org_map, sizeof(map));
    while (change) {
        change = 0;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (map[i][j] == 'c' || map[i][j] == '0') {
                    for (int k = 0; k < 8; ++k) {
                        x = i + dir_x[k];
                        y = j + dir_y[k];
                        if (x < 0 || x >= num_rows || y < 0 || y >= num_cols)
                            continue;
                        if (map[x][y] != '.')
                            continue;
                        c = mark(map, x, y, num_rows, num_cols, 1);
                        map[x][y] = '0' + c;
                        change = 1;
                    }
                }
            }
        }
    }
    c = 0;
    int valid = 1;
    for (int i = 0; i < num_rows; ++i)
        for (int j = 0; j < num_cols; ++j)
            if (map[i][j] == '*')
                c++;
            else if (map[i][j] == '.')
                valid = 0;
    if (valid == 0 || c != num_mines)
        return 0;
    return 1;
    for (int i = 0; i < num_rows; ++i) {
        map[i][num_cols] = 0;
        puts(map[i]);
    }
}

int fill_c(char map[][60], int num_rows, int num_cols, int &x, int &y) {
    for (int i = 0; i < num_rows; ++i)
        for (int j = 0; j < num_cols; ++j) {
            if (map[i][j] != '.')
                continue;
            int c = mark(map, i, j, num_rows, num_cols, 1);
            if (c == 0) {
                x = i;
                y = j;
                return 1;
            }
        }
    return 0;
}

int dfs(char map[][60], int x, int y, int num_rows, int num_cols, int num_mines, int goal, char symbol) {
    int t;
    if (y >= num_cols) {
        y = 0;
        x++;
    }
    if (x >= num_rows) {
        if (goal != 0)
            return 0;
        int cx, cy;
        if (!fill_c(map, num_rows, num_cols, cx, cy))
            return 0;
        map[cx][cy] = 'c';
        if (check(map, num_rows, num_cols, num_mines))
            return 1;
        map[cx][cy] = '.';
        return 0;
    }
    if (dfs(map, x, y + 1, num_rows, num_cols, num_mines, goal, symbol))
        return 1;
    char keep = map[x][y];
    map[x][y] = symbol;
    if (dfs(map, x, y + 1, num_rows, num_cols, num_mines, goal - 1, symbol))
        return 1;
    map[x][y] = keep;
    return 0;
}

void brute_force(int num_rows, int num_cols, int num_mines) {
    puts("Impossible");
    return;
    char map[60][60];
    int ans;
    if (num_mines > num_rows * num_cols) {
        memset(map, '*', sizeof(map));
        ans = dfs(map, 0, 0, num_rows, num_cols, num_mines, num_rows * num_cols - num_mines, '.');
    }
    else {
        memset(map, '.', sizeof(map));
        ans = dfs(map, 0, 0, num_rows, num_cols, num_mines, num_mines, '*');
    }

    if (ans) {
        for (int i = 0; i < num_rows; ++i) {
            map[i][num_cols] = 0;
            puts(map[i]);
        }
    }
    else {
        puts("Impossible");
    }
}

int dfs2(char map[][60], int num_rows, int num_cols, 
    int current, int order_x[], int order_y[], int order_size, 
    int need_empties, int num_mines) {
    if (need_empties < 0)
        return 0;
    else if (need_empties == 0) {
        map[0][0] = 'c';
        if (check(map, num_rows, num_cols, num_mines))
            return 1;
        map[0][0] = '.';
        return 0;
    }
    else if (current >= order_size)
        return 0;

    int x = order_x[current];
    int y = order_y[current];
    int c = mark(map, x, y, num_rows, num_cols, 0);
    if (dfs2(map, num_rows, num_cols, 
        current + 1, order_x, order_y, order_size, 
        need_empties - 1, num_mines)) {
        return 1;
    }
}

void brute_force2(int num_rows, int num_cols, int num_mines) {
    char map[60][60];
    int order_x[3000], order_y[3000], order_size;
    int level = 0;
    int x, y;
    order_size = 0;
    for (level = 0; level <= num_rows + num_cols - 2; level++) 
        for (x = 0; x <= level && x < num_rows; ++x) {
            y = level - x;
            order_x[order_size] = x;
            order_y[order_size] = y;
            order_size++;
        }
    memset(map, '*', sizeof(map));
    if (!dfs2(map, num_rows, num_cols, 0, order_x, order_y, order_size, 
        num_rows * num_cols - num_mines, num_mines))
        puts("Impossible");
    else {
        for (int i = 0; i < num_rows; ++i) {
            map[i][num_cols] = 0;
            puts(map[i]);
        }
    }
}

int fill(char map[][60], int num_rows, int num_cols, int num_mines, int strategy) {
    int x = 0, y = 0;
    int c;
    int num_empties = num_rows * num_cols - num_mines;
    memset(map, '*', 60 * 60);
    int level = 0;
    for (level = 0; num_empties > 0 && 
        level <= num_rows + num_cols - 2; level++) {
        for (x = 0; num_empties > 0 && x <= level && x < num_rows; ++x) {
            y = level - x;
            c = mark(map, x, y, num_rows, num_cols, 1);
            if (num_empties == 1 && c > 1)
                continue;
            if (strategy == 1) {
                if (num_empties == 2 && c == 1)
                    continue;
            }
            c = mark(map, x, y, num_rows, num_cols, 0);
            //printf("mark %d %d %d %d\n", x, y, c, num_empties);
            num_empties -= c;
        }
    }
    if (num_empties != 0)
        return 0;
    map[0][0] = 'c';
    if (!check(map, num_rows, num_cols, num_mines)) 
        return 0;
    return 1;
}

void gen(int num_rows, int num_cols, int num_mines) {
    char map[60][60];
    if (!fill(map, num_rows, num_cols, num_mines, 0)) {
        if (!fill(map, num_rows, num_cols, num_mines, 1)) {
            brute_force(num_rows, num_cols, num_mines);
            return;
        }
    }
    for (int i = 0; i < num_rows; ++i) {
        map[i][num_cols] = 0;
        puts(map[i]);
    }
}

void gen2(int num_rows, int num_cols, int num_mines) {
    int map[60][60];
    memset(map, 0, sizeof(map));
    int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dir_y[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int num_empty = num_rows * num_cols;
    while (num_mines > 0) {
        int min = 20;
        int ans_x, ans_y;
        for (int i = 0; i < num_rows; ++i)
            for (int j = 0; j < num_cols; ++j) {
                if (map[i][j] == -1)
                    continue;
                int c = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dir_x[k];
                    int y = j + dir_y[k];
                    if (x < 0 || x >= num_rows || y < 0 || y >= num_cols)
                        continue;
                    if (map[x][y] == 0)
                        c++;
                }
                if (map[i][j] == 0)
                    c++;
                if (c < min) {
                    min = c;
                    ans_x = i;
                    ans_y = j;
                }
            }
        if (min == 20)
            break;
        if (map[ans_x][ans_y] == 0)
            --num_empty;
        map[ans_x][ans_y] = -1;
        for (int k = 0; k < 8; ++k) {
            int x = ans_x + dir_x[k];
            int y = ans_y + dir_y[k];
            if (x < 0 || x >= num_rows || y < 0 || y >= num_cols)
                continue;
            if (map[x][y] == 0) {
                map[x][y] = 1;
                --num_empty;
            }
        }
        --num_mines;
    }
    if (num_mines > 0 || num_empty < 1) {
        puts("Impossible");
        return;
    }
    int clicked = 0;
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            if (map[i][j] == -1) {
                putchar('*');
            }
            else if (map[i][j] == 0 && clicked == 0) {
                putchar('c');
                clicked = 1;
            }
            else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

void run() {
    int num_rows, num_cols;
    int num_mines;
    scanf("%d%d%d", &num_rows, &num_cols, &num_mines);
    int total = num_rows * num_cols;
    if (num_mines == total - 1)
        fill_all(num_rows, num_cols);
    else
        gen(num_rows, num_cols, num_mines); 
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d:\n", t);
        run();
    }
    return 0;
}
