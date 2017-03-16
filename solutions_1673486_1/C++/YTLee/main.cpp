#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTING

#define MIN(x, y) ((x) < (y)) ? (x) : (y)

int main()
{
#ifdef TESTING
    FILE *f = freopen("sample.in", "r", stdin);
    FILE *fout = freopen("result.out", "w", stdout);
#endif

    int num_case;
    scanf("%d", &num_case);

    int A, B;
    float prob_i_c;
    for (int i = 0 ; i < num_case ; ++i)
    {
        scanf("%d %d", &A, &B);

        float min_exp = 2.0f + (float)B;
        float prob_all_right = 1.0f;
        float prob_not_all_right;
        for (int j = 1 ; j <= A ; ++j)
        {
            scanf("%f", &prob_i_c);

            prob_all_right *= prob_i_c;
            prob_not_all_right = 1.0f - prob_all_right;

            int done_keystork = ((A - j) + (B - j + 1));
            float temp_exp = prob_all_right * done_keystork + prob_not_all_right * (done_keystork + B + 1);
            min_exp = MIN(min_exp, temp_exp);
        }

        printf("Case #%d: %f\n", (i+1), min_exp);
    }

#ifdef TESTING
    fclose(f);
    fclose(fout);
#endif

    return 0;
}