#include <cstdio>

int main() {
    
    int testCases;
    
    scanf("%d", &testCases);
    
    for (int testCase = 1; testCase <= testCases; ++testCase) {
        
        int r, c, w;
        int numTries = 0;
        
        scanf("%d %d %d", &r, &c, &w);
        
        numTries = r * (c / w);

        if (c % w == 0) {
            numTries += w - 1;
        }
        else {
            numTries += w;
        }

        printf("Case #%d: %d\n", testCase, numTries);

    }
    
    return 0;
    
}
