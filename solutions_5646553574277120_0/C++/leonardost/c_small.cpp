#include <cstdio>

int main() {
    
    int testCases;
    int numbers[30] = { 1, 2, 4, 8, 16 };

    scanf("%d", &testCases);
    
    for (int testCase = 1; testCase <= testCases; ++testCase) {

        int c, d, v;

        scanf("%d %d %d", &c, &d, &v);
        
        int isPossible[31], values[5];
        isPossible[0] = 1;
        for (int i = 1; i < 30; ++i)
            isPossible[i] = 0;

        for (int i = 0; i < d; ++i) {
            scanf("%d", &values[i]);
            isPossible[values[i]] = 1;
            //~ for (int j = 30; j >= 0; --j) {
                //~ if (isPossible[j - values[i]]) {
                    //~ isPossible[j] = 1;
                //~ }
            //~ }
        }

        int limit;
        if (v < 4)
            limit = 2;
        else if (v < 8)
            limit = 3;
        else if (v < 16)
            limit = 4;
        else if (v < 32)
            limit = 5;
        
        int add = 0;
        for (int i = 0; i < limit; ++i) {
            if (!isPossible[ numbers[i] ]) {
                add++;
            }
        }

        //~ for (int i = 1; i < v; ++i) {
            //~ if (!isPossible[i])
                //~ printf("%d is not possible\n", i);
        //~ }
        //~ printf("---\n");

        printf("Case #%d: %d\n", testCase, add);
        
    }
    
    return 0;
    
}
