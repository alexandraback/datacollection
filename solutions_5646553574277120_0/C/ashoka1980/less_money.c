#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

uint32_t d_val[200];

int
main (void)
{
    uint32_t n_test, c, d, v, i, j, t, e, cnt, cover;
    int rc;

    rc = scanf("%u", &n_test);
    assert(rc == 1);

    for (i = 0; i < n_test; i++) {
        rc = scanf("%u %u %u", &c, &d, &v);
        assert(rc == 3);

        for (j = 0; j < d; j++) {
            rc = scanf("%u", &d_val[j]);
            assert(rc == 1);
        }

        cnt = 0;
        j = 0;
        e = 1;
        if (d_val[j] != e) {
            cnt++;
        } else {
            j++;
        }

        while (v >= (2 * e)) {
            cover = 2 * e - 1;
            while ((j < d) && (d_val[j] < (2 * e))) {
               if (d_val[j] <= (cover + 1))
                   cover = cover + d_val[j];
               j++;
            }

            if (v <= cover) {
                break;
            }

            if ((j < d) && (d_val[j] == (2 * e))) {
                j++;
            } else {
                cnt++;
            }

            e = 2 * e;
        }

        printf("Case #%u: %u\n", i + 1, cnt);
    }

    return 0;
}
