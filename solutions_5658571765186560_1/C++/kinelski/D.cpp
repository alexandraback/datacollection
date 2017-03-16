#include <stdio.h>

int Min (int x, int y){
    if (x < y) return x;
    return y;
}
int Max (int x, int y){
    if (x > y) return x;
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

        case 5: //ESTUDAR ESSE O CASO 3x(5k)
            if (r*c%5 != 0) printf ("RICHARD\n");
            else if (Min(r,c) < 3) printf ("RICHARD\n");
            else if (Min(r,c) == 3 && Max(r,c) == 5) printf ("RICHARD\n");
            else printf ("GABRIEL\n");
            break;

        case 6:
            if (r*c%6 != 0) printf ("RICHARD\n");
            else if (Min(r,c) < 4) printf ("RICHARD\n");
            else printf ("GABRIEL\n");
            break;

        default:
            printf ("RICHARD\n");
        }
    }

    return 0;
}
