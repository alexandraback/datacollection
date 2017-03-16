/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int tests,
    components,
    perm[16];
char word[16][128];

bool test(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        printf("Case #%d: ", t + 1);
        scanf("%d", &components);
        for(int c = 0; c < components; ++ c)
        {
            perm[c] = c;
            scanf("%s", word[c]);
        }

        int count = 0;
        do
        {
            count += test();
        }
        while(next_permutation(perm, perm + components));
        printf("%d\n", count);
    }

    return 0;
}

inline
bool test(void)
{
    bool done[256] = {};
    int last = 0;
    for(int c = 0; c < components; ++ c)
        for(int w = 0; word[perm[c]][w]; ++ w)
        {
            if(last != word[perm[c]][w])
                done[last] = true;

            last = word[perm[c]][w];
            if(done[last])
                return false;
        }

    return !done[last];
}
