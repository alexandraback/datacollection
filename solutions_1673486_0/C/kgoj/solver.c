#include <stdio.h>

#define MAX 100002

int main(int argc, char const *argv[]) {
    int num_cases, case_no;
    scanf("%d", &num_cases);

    for(case_no = 1; case_no <= num_cases; ++case_no) {
        int a, b;
        double p[MAX], _c_data[MAX+1], *c = _c_data + 1;
        // p[i] - p. correctly typing char i
        // c[i] - p. correctly typing chars up to i (incl.)
        double result = 0;
        c[-1] = 1;
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; i++) {
            scanf("%lf", p + i);
            c[i] = c[i-1] * p[i];
        }
        int retype = b + 1;
        double nowcost = 1 + retype;
        result = nowcost;
        for (int j = 0; j <= a; j++) {
            // j - number of backspaces
            int k = a - j;
            // k - number of chars after deletes
            int totype = j + b-k+1;
            double tmp = c[k-1] * totype + (1-c[k-1]) * (totype+retype);
            if (tmp < result)
                result = tmp;
        }
        printf("Case #%d: %.6lf\n", case_no, result);
    }

    return 0;
}
