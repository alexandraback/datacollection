#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int tests, googlers, score, p, suprising;

    scanf("%d", &tests);

    for (int i = 0; i < tests; ++i) {

        scanf("%d %d %d", &googlers, &suprising, &p);

        int res = 0;

        while (googlers--) {

            scanf("%d", &score);

            if (score > 1) {

                if (score >= 3 * p - 2) {
                    res++;
                } else if (score >= 3 * p - 4 && suprising > 0) {
                    res++;
                    suprising--;
                }
            } else if (score > 0) {

                if (score >= 3 * p - 2)
                    res++;
                
            } else {

                if (p == 0)
                    res++;
            }
        }

        printf("Case #%d: %d\n", i + 1, res);
    }

    return 0;
}