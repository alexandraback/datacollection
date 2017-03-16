#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int comparator(const void *, const void *);
#define EL(l, r, c) (l)[(r) * cols + (c)]
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int rev_int_cmp(const void *lhs, const void *rhs) {
    return *(const int *)rhs - *(const int *)lhs;
}

static void run_row(int *lawn, int *target, int rows, int cols, int row, int h)
{
    for (int col = 0; col < cols; ++col) {
        if (EL(target, row, col) > h) {
            return;
        }
    }
    for (int col = 0; col < cols; ++col) {
        int el = EL(lawn, row, col);
        EL(lawn, row, col) = MIN(el, h);
    }
}

static void run_col(int *lawn, int *target, int rows, int cols, int col, int h)
{
    for (int row = 0; row < rows; ++row) {
        if (EL(target, row, col) > h) {
            return;
        }
    }
    for (int row = 0; row < rows; ++row) {
        int el = EL(lawn, row, col);
        EL(lawn, row, col) = MIN(el, h);
    }
}

static const char *solve(int *lawn, int rows, int cols)
{
    int sz = rows * cols;
    int cur_lawn[100 * 100];
    for (int i = 0; i < sz; ++i) {
        cur_lawn[i] = 100;
    }
    int heights[100 * 100];
    memcpy(heights, lawn, sz * sizeof(int));
    qsort(heights, sz, sizeof(int), &rev_int_cmp);
    int prev_h = -1;
    // For every unique height.
    for (int i = 0; i < sz; ++i) {
        int h = heights[i];
        if (h == prev_h) {
            continue;
        }
        prev_h = h;
        for (int r = 0; r < rows; ++r) {
            run_row(cur_lawn, lawn, rows, cols, r, h);
        }
        for (int c = 0; c < cols; ++c) {
            run_col(cur_lawn, lawn, rows, cols, c, h);
        }
    }
    return memcmp(lawn, cur_lawn, sz * sizeof(int)) ? "NO" : "YES";
}

int main(void)
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        int rows, cols;
        scanf("%d %d\n", &rows, &cols);
        int lawn[100 * 100];
        int *p = lawn;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                scanf("%d", p);
                ++p;
            }
            scanf("\n");
        }
        printf("Case #%d: %s\n", i + 1, solve(lawn, rows, cols));
    }
}
