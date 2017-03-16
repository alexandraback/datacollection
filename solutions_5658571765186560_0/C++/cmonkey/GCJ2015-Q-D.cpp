#include <cstdio>
#include <cstdlib>

int main(){
    int t, T;
    int X, R, C;
    char ans;
    FILE* fin = fopen("D-small-attempt0.in", "r");
    FILE* fout = fopen("D.out", "w");
    fscanf(fin, "%d", &T);
    for (t = 1; t <= T; t++){
        fscanf(fin, "%d %d %d", &X, &R, &C);
        if (X == 1) ans = 'G';
        else if (X == 2){
            if ((R * C) % X != 0) ans = 'R';
            else ans = 'G';
        }else if (X == 3){
            if ((R * C) % X != 0) ans = 'R';
            else{
                if (R == 1 || C == 1) ans = 'R';
                else ans = 'G';
            }
        }else if (X== 4){
            if ((R * C) % X != 0) ans = 'R';
            else{
                if (R < 2 || C < 2 || (R < 4 && C < 4)) ans = 'R';
                else if ((R == 2 && C == 4) || (R == 4 && C == 2)) ans = 'R';
                else ans = 'G';
            }
        }else{
            printf("Error X = %d\n", X);
        }
        fprintf(fout, "Case #%d: %s\n", t, ans == 'G' ? "GABRIEL" : "RICHARD");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
