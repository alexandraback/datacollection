#include <stdio.h>

int Min (int x, int y){
    if (x < y) return x;
    return y;
}

int main(){
    int t, x, r, c;
    scanf ("%d", &t);

    for (int k=1; k<=t; k++){
        scanf ("%d %d %d", &x, &r, &c);
        printf ("Case #%d: ", k);

        switch (x){
        case 1:
            printf ("GABRIEL\n");
            break;

        case 2:
            if (r*c%2 != 0) printf ("RICHARD\n");
            else printf ("GABRIEL\n");
            break;

        case 3:
            if (r*c%3 != 0) printf ("RICHARD\n");
            else if (Min(r,c) < 2) printf ("RICHARD\n");
            else printf ("GABRIEL\n");
            break;

        case 4:
            if (r*c%4 != 0) printf ("RICHARD\n");
            else if (Min(r,c) < 3) printf ("RICHARD\n");
            else printf ("GABRIEL\n");
            break;

        case 5:
            if (r*c%5 != 0) printf ("RICHARD\n");
            else if (Min(r,c) < 4) printf ("RICHARD\n");
            break;

        default:
            printf ("RICHARD\n");
        }
    }

    return 0;
}
