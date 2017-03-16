#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct box {
    int x, y;
    int down, right, rightdown, leftdown, rightup, up, leftup, left;
};

int a[51][51]; // a[0][.]=points in raw .
int r, c, m, transformed;
int transformed;
struct box b[2000];
int bn = 0; // depth

#define point_cover(xx,yy) {\
    empty += (a[xx][yy] == 0) ? 1 : 0; \
    a[xx][yy] += factor;\
}

int cover(int x, int y, int factor) {
    int empty = 0;
    if (x > 1) {
        point_cover(x - 1, y)
        if (y > 1)
            point_cover(x - 1, y - 1)
            //added += (a[x - 1][y - 1] == 0) ? 1 : 0;
        if (y < c)
            point_cover(x - 1, y + 1)
            //added += (a[x - 1][y + 1] == 0) ? 1 : 0;
    }
    if (x < r) {
        //added += (a[x + 1][y] == 0) ? 1 : 0;
        point_cover(x + 1, y)
        if (y > 1)
            point_cover(x + 1, y - 1)
            //added += (a[x + 1][y - 1] == 0) ? 1 : 0;
        if (y < c)
            point_cover(x + 1, y + 1)
            //added += (a[x + 1][y + 1] == 0) ? 1 : 0;
    }
    if (y > 1)
        point_cover(x, y - 1)
        //added += (a[x][y - 1] == 0) ? 1 : 0;
    if (y < c)
        point_cover(x, y + 1)
        //added += (a[x][y + 1] == 0) ? 1 : 0;
    a[x][y] += factor;
    return empty;
}

int init_box(int i, int x, int y) {
    int added = 0;
    b[i].down = b[i].right = b[i].rightdown = b[i].leftup = b[i].leftdown = b[i].up = b[i].rightup = b[i].left = 0;
    b[i].x = x;
    b[i].y = y;
    if ((added = cover(x, y, 1)) == 0)
        cover(x, y, -1); //uncover!
    return added;
}

int solve(int remain) {
    int i;
    if (remain == 0)
        return 1;
    else if (remain < 0)
        return 0;
    for (i = 0; i <= bn; i++) {
        int added = 0;
        // right
        if (b[bn].right == 0 && b[bn].y < c) {
            added = init_box(bn + 1, b[bn].x, b[bn].y + 1);
            if (added > 0) {
                b[bn].right = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].right = 0;
                cover(b[bn].x, b[bn].y + 1, -1);//uncover
            }
        }
        // down
        if (b[bn].down == 0 && b[bn].x < r) {
            added = init_box(bn + 1, b[bn].x + 1, b[bn].y);
            if (added > 0) {
                b[bn].down = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].down = 0;
                cover(b[bn].x + 1, b[bn].y, -1);//uncover
            }
        }
        // down
        if (b[bn].up == 0 && b[bn].x > 1) {
            added = init_box(bn + 1, b[bn].x - 1, b[bn].y);
            if (added > 0) {
                b[bn].up = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].up = 0;
                cover(b[bn].x - 1, b[bn].y, -1);//uncover
            }
        }
        // rightdown

        if (b[bn].rightdown == 0 && b[bn].x < r && b[bn].y < c) {
            added = init_box(bn + 1, b[bn].x + 1, b[bn].y + 1);
            if (added > 0) {
                b[bn].rightdown = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].rightdown = 0;
                cover(b[bn].x + 1, b[bn].y + 1, -1);//uncover
            }
        }

        if (b[bn].leftdown == 0 && b[bn].x < r && b[bn].y > 1) {
            added = init_box(bn + 1, b[bn].x + 1, b[bn].y - 1);
            if (added > 0) {
                b[bn].leftdown = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].leftdown = 0;
                cover(b[bn].x + 1, b[bn].y - 1, -1);//uncover
            }
        }
        if (b[bn].leftup == 0 && b[bn].x > 1 && b[bn].y > 1) {
            added = init_box(bn + 1, b[bn].x - 1, b[bn].y - 1);
            if (added > 0) {
                b[bn].leftup = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].leftup = 0;
                cover(b[bn].x - 1, b[bn].y - 1, -1);//uncover
            }
        }
        if (b[bn].rightup == 0 && b[bn].x > 1 && b[bn].y < c) {
            added = init_box(bn + 1, b[bn].x - 1, b[bn].y + 1);
            if (added > 0) {
                b[bn].rightup = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].rightup = 0;
                cover(b[bn].x - 1, b[bn].y + 1, -1);//uncover
            }
        }
        if (b[bn].left == 0 && b[bn].y > 1) {
            added = init_box(bn + 1, b[bn].x, b[bn].y - 1);
            if (added > 0) {
                b[bn].left = 1;
                bn++;
                if (solve(remain - added))
                    return 1;
                b[--bn].left = 0;
                cover(b[bn].x, b[bn].y - 1, -1);//uncover
            }
        }
    }
    return 0;
}

int main()
{
    FILE* fin = fopen("mines.in", "r");
    FILE* fou = fopen("mines.txt", "w");
    int t, cc;
    //fou = stdout;
    fscanf(fin, "%d\n", &t);
    for (cc = 0; cc < t; cc++) {
        int remain, result, cx, cy;
        fscanf(fin, "%d %d %d\n", &r, &c, &m);
        fprintf(fou, "Case #%d:\n", cc + 1);
        memset(a, 0, sizeof(a));
        transformed = 0;
        if (r > c) {
            r = r + c;
            c = r - c;
            r = r - c;
            transformed = 1;
        }

        if (r * c - m <= 1) {
            cx = cy = 1;
            goto RESULT;
        }
        // Simple cases: r=1, always put at (1,2)
        else {
            bn = 0;
            remain = r * c - m - init_box(bn, 1, 1) - 1;
            cx = 1, cy = 1;
            if (solve(remain) == 1)
                goto RESULT;
            cover(b[0].x, b[0].y, -1);

            fprintf(fou, "Impossible\n");
            continue;
        }
        // Solve
RESULT:
        if (!transformed) {
            int i, j;
            for (i = 1; i <= r; i++) {
                for (j = 1; j <= c; j++)
                    if (i != cx || j != cy)
                        fprintf(fou, "%c", (a[i][j] > 0) ? '.' : '*');
                    else
                        fprintf(fou, "c");
                fprintf(fou, "\n");
            }
        }
        else {
            int i, j;
            for (j = 1; j <= c; j++) {
                for (i = 1; i <= r; i++)
                    if (i != cx || j != cy)
                        fprintf(fou, "%c", (a[i][j] > 0) ? '.' : '*');
                    else
                        fprintf(fou, "c");
                fprintf(fou, "\n");
            }

        }
    }
    fclose(fou);
    fclose(fin);
    return 0;
}
