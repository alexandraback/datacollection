#include <stdio.h>
#include <stdint.h>
#include <assert.h>

int
main (void)
{
    uint32_t n_test, row, col, w, i, hit;
    int rc;

    rc = scanf("%u", &n_test);
    assert(rc == 1);

    for (i = 0; i < n_test; i++) {
        rc = scanf("%u %u %u", &row, &col, &w);
        assert(rc == 3);

        hit = (col - 1) / w + w;
        printf("Case #%u: %u\n", i + 1, hit);
    }

    return 0;
}
