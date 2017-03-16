#include <stdio.h>

int main() {
    FILE *input = fopen("bullin.txt", "r");
    FILE *output = fopen("bullout.txt", "w");

    unsigned long long num_tests;
    unsigned long long r, paint;
    unsigned long long min, max, mid;
    unsigned long long i;
    fscanf(input, "%llu ", &num_tests);

    for (i = 0; i < num_tests; i++) {
        fscanf(input, "%llu %llu ", &r, &paint);
        min = 1; max = 2100000000;
        while (min != max) {
            //printf("%d %d\n", min, max);
            mid = (min+max+1)/2;
            if ((2*r*mid) + mid*(2*mid - 1) > paint) {
                max = mid-1;
            }
            else min = mid;
        }
        fprintf(output, "Case #%llu: %llu\n", i+1, min);
        printf("Case #%llu: %llu\n", i+1, min);
    }
    

    fclose(input); fclose(output);
    return 0;
}