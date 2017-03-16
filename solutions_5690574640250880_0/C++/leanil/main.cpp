#include <cstdio>
#include <algorithm>

using namespace std;

void putMines(int r, int c, int m, char field[50][50]) {
    if(r < c) {
        for(int i=1;i<=min(m,r);i++) {
            field[r-i][c-1] = '*';
        }
        if(m > r) {
            putMines(r,c-1,m-r,field);
        }
        else if(m == r-1){
            field[1][c-1] = '.';
            field[r-1][c-2] = '*';
        }
    }
    else {
        for(int i=1;i<=min(m,c);i++) {
            field[r-1][c-i] = '*';
        }
        if(m > c) {
            putMines(r-1,c,m-c,field);
        }
        else if(m == c-1){
            field[r-1][1] = '.';
            field[r-2][c-1] = '*';
        }
    }
}

int main()
{
    const int impossible[4] = {2,3,5,7};
    FILE* in = fopen("input.txt","r");
    FILE* out = fopen("output.txt","w");
    int t;
    fscanf(in,"%d",&t);
    for(int i=1;i<=t;i++) {
        int r, c, m;
        fscanf(in,"%d%d%d",&r,&c,&m);
        int possible = true;
        int emp = r*c-m;
        for(int j=0;j<4;j++) {
            if(emp == impossible[j]) {
                possible = false;
            }
        }
        fprintf(out,"Case #%d:\n",i);
        if(min(r,c) == 1 || (possible && (emp%2 == 0 || emp == 1 || min(r,c) >2))) {
            char field[50][50];
            for(int j=0;j<r;j++) {
                for(int k=0;k<c;k++) {
                    field[j][k] = '.';
                }
            }
            field[0][0] = 'c';
            if(m>0) {
                putMines(r,c,m,field);
            }
            for(int j=0;j<r;j++) {
                for(int k=0;k<c;k++) {
                    fprintf(out,"%c",field[j][k]);
                }
                fprintf(out,"\n");
            }
        }
        else {
            fprintf(out,"Impossible\n");
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
