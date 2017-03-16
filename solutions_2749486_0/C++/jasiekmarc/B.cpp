#include <cstdio>

void tcase() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x > 0)
        while(x --)
            printf("WE");
    else if(x < 0)
        while(x ++)
            printf("EW");
    if(y > 0)
        while(y --)
            printf("SN");
    else if(y < 0)
        while(y ++)
            printf("NS");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        tcase();
        printf("\n");
    }
}