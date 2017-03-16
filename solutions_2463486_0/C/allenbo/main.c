#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fair(int n) {
    int num = n;
    if(num < 10) return 1;
    int fake = 0;
    
    while(num) {
        fake = 10 * fake + (num % 10);
        num /= 10;
    }
    return fake == n;
}

int check(int num) {
    float fnum = (float) num;
    float sq = sqrt(fnum);
    if(sq > (int)sq) return 0;

    int sqr = (int) sq;
    return fair(num) && fair(sqr);
}


int main() {
    char* filename = "test.in";
    int numCase =0;
    
    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d\n", &numCase);

    int i,j,k;
    for(i = 0; i < numCase; i ++ ) {
        int from;
        int to;
        fscanf(fin, "%d %d", &from, &to);

        int count = 0;
        while(1) {
            if(from > to) break;
            count  += check(from ++);
        }

        printf("Case #%d: %d\n", i+1, count);

    }
    return 0;
}
