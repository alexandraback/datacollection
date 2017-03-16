#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//used to store string rep of an int
static char num_buf[8];

void print_case(int case_num, int output) {
    if (case_num == 1)
        printf("Case #1: %d", output);
    else
        printf("\nCase #%d: %d", case_num, output);
    return;
}

//another "dumb" pow function
inline int pow10(int n) {
    int acc = 1;
    while (n > 0) {
        acc *= 10;
        n--;
    }
    return acc;
}

// sees if n is in seen array
int not_seen(int n, int *seen) {
    int i = 0;
    
    while (seen[i] != 0) {
        if (seen[i] == n)
            return 0;
        i++;
    }
    return 1;
}

// count pairs (test,m) where m is related to test, greater that test, and 
// leq to high
int count_matches(int test, int high) {
    int len;
    int temp_val;
    int count = 0;
    int i;
    int j;
    int seen[8];
    
    seen[0] = 0;

    sprintf(num_buf, "%d", test);
    len = strlen(num_buf);
    
    for (i = 1; i < len; i++) {
        temp_val = 0;
        for (j = 0; j < len; j++) {
            temp_val += (pow10(len - j - 1) * (num_buf[(i + j) % len] - '0'));
        }
        if ((temp_val <= high) && (temp_val > test)){
            if (not_seen(temp_val, seen)) {
                seen[count] = temp_val;
                count++;
                seen[count] = 0;
            }
        }
    }
    return count;
}

int solve (int lower, int upper) {
    int acc = 0;
    int test_lesser = lower;

    while (test_lesser < upper) {
        acc += count_matches(test_lesser, upper);
        test_lesser++;
    }
    return acc;
}

int main () {
    int tests;
    int count = 1;
    int lower;
    int upper;

    scanf("%d", &tests);

    while (count <= tests) {
        scanf("%d %d", &lower, &upper);
        print_case(count, solve(lower, upper));
        count++;
    }

    return 0;
}



