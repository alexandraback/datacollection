#include <stdio.h>

int main(){
    int t, smax, shy[10000], up, inv;
    char input[10000];
    scanf ("%d", &t);

    for (int k=1; k<=t; k++){
        scanf ("%d", &smax);
        scanf ("%s", input);

        for (int i=0; i<=smax; i++)
            shy[i] = input[i] - '0';

        up = 0;
        inv = 0;
        for (int i=0; i<=smax; i++){
            if (up < i){
                inv += i-up;
                up = i + shy[i];
            } else {
                up += shy[i];
            }
        }

        printf ("Case #%d: %d\n", k, inv);
    }

    return 0;
}
