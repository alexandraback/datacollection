#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXUS 1001
using namespace std;
int main() {
    int z,n,r,c,w;
    char input[MAXUS];
    scanf("%d",&z);
    for (int j = 0; j < z; j++) {
        scanf("%d %d %d", &r,&c,&w);
        
        printf("Case #%d: %d\n", j+1, (int) ceil(((double) c)/((double) w) - 1 + w));
    }

	return 0;
}
