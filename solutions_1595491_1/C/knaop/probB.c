#include <stdio.h>

#define HAS_SURPRISE 1

void print_case(int case_num, int output) {
    if (case_num == 1) 
        printf("Case #1: %d", output);
    else 
        printf("\nCase #%d: %d", case_num, output);
    return;
}

inline int max (int x, int y) {
    return ((x > y) ? x : y);
}

inline int can_break(int total, int threshold, int surprise) {
    if (total - threshold < 0) return 0;

    if (surprise) {
        if (((total - threshold) / 2) >= (threshold - 2)) 
            return 1;
        else return 0;
    }
    else {
        if (((total - threshold) / 2) >= (threshold - 1))
            return 1;
        else return 0;
    }
}

int solve(int num_googs, int num_surprises, int threshold, int *totals) {
    int used_surp;
    int nused_surp;

    if (num_googs == 0) return 0;

    if (can_break(totals[0], threshold, !HAS_SURPRISE)) {
        nused_surp = solve(num_googs - 1, num_surprises,
                                                    threshold, totals + 1);
        return 1 + nused_surp;
    }

    else if ((num_surprises > 0) && 
                             (can_break(totals[0], threshold, HAS_SURPRISE))) {
        used_surp = solve(num_googs - 1, num_surprises - 1,
                                                    threshold, totals + 1);
        return 1 + used_surp;
    }

    else {
        nused_surp = solve(num_googs - 1, num_surprises,
                                                    threshold, totals + 1);
        return nused_surp;
    }
}

int main() {
    int totals[100];
    int tests;
    int count = 1;
    int num_googs;
    int threshold;
    int num_surprises;
    int goog_count;

    scanf("%d", &tests);

    while (count <= tests) {
        scanf("%d %d %d", &num_googs, &num_surprises, &threshold);
        goog_count = 0;
        while (goog_count < num_googs) {
            scanf("%d", totals + goog_count);
            goog_count += 1;
        }
        print_case(count, solve(num_googs, num_surprises, threshold, totals));
        count += 1;
    }
    return 0;
}


