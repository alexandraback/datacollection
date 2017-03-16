#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

enum coord {one=1, i, j, k};

int m[10][10];

void start(){
    m[1][1] = 1; m[1][i] = i; m[1][j] = j; m[1][k] = k;
    m[i][1] = i; m[i][i] = -1; m[i][j] = k; m[i][k] = -j;
    m[j][1] = j; m[j][i] = -k; m[j][j] = -1; m[j][k] = i;
    m[k][1] = k; m[k][i] = j; m[k][j] = -i; m[k][k] = -1;
}

int prod(int x, int y){
    if (x > 0 && y > 0) return m[x][y];
    if (x < 0 && y < 0) return m[-x][-y];
    if (x < 0) return -m[-x][y];
    return -m[x][-y];
}

void interval(int first, int last, string word){
    int p=1;

    for (int c=first; c<last; c++){
        if (word[c] == 'i') p = prod(p,i);
        else if (word[c] == 'j') p = prod(p,j);
        else p = prod(p,k);
    }

    printf ("p = %d\n", p);
}

int main(){
    bool fail;
    int l, x, numi, numk, firstx, t, p;
    string input, total;
    scanf ("%d", &t);

    start();

    for (int K=1; K<=t; K++){
        scanf ("%d %d", &l, &firstx);
        input="";

        x = firstx;
        for (int c=0; c<l; c++){
            char aux;
            scanf (" %c", &aux);
            input = input + aux;
        }
        fail = false;

        x %= 8;
        if (x == 0) x = 8;

        total = "";
        for (int c=0; c<x; c++)
            total = total + input;

        p = 1;
        for (int c=0; c<l*x; c++){
            if (total[c] == 'i') p = prod(p,i);
            else if (total[c] == 'j') p = prod(p,j);
            else p = prod(p,k);
        }

        if (p != -1){
            fail = true;
            goto FAIL;
        }

        numi = 0;
        numk = 0;

        p = 1;
        for (int c=0; c<l*x && numi==0; c++){
            if (total[c] == 'i') p = prod(p,i);
            else if (total[c] == 'j') p = prod(p,j);
            else p = prod(p,k);

            if (p == i) numi = c+1;
        }

        p = 1;
        for (int c=l*x-1; c>=0 && numk==0; c--){
            if (total[c] == 'i') p = prod(i,p);
            else if (total[c] == 'j') p = prod(j,p);
            else p = prod(k,p);

            if (p == k) numk = l*x-c;
        }

        if ((long long)(numi + numk) >= ((long long)l)*((long long)firstx)) fail = true;
        if (numi == 0 || numk == 0) fail = true;

        //interval(0,numi,total);
        //interval(numi,l*x-numk,total);
        //interval(l*x-numk,l*x,total);

        FAIL:
        printf ("Case #%d: ", K);
        if (fail) printf ("NO\n");
        else printf ("YES\n");
    }

    return 0;
}
