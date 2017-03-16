#include <stdio.h>
#include <string.h>
int main () {
    FILE *fin  = fopen ("A.in", "r");
    FILE *fout = fopen ("output.txt", "w");
    /* -------------- START -------------- */
    int n,l;
    int c,i;
    char g[150];
    fscanf(fin, "%d\n", &n);
    for(c=1;c<=n;c++){
        fgets(g,125,fin);
        l=strlen(g);
        for(i=0;i<l;i++){
            switch(g[i]){
                case 'a' : g[i]='y'; break;
                case 'b' : g[i]='h'; break;
                case 'c' : g[i]='e'; break;
                case 'd' : g[i]='s'; break;
                case 'e' : g[i]='o'; break;
                case 'f' : g[i]='c'; break;
                case 'g' : g[i]='v'; break;
                case 'h' : g[i]='x'; break;
                case 'i' : g[i]='d'; break;
                case 'j' : g[i]='u'; break;
                case 'k' : g[i]='i'; break;
                case 'l' : g[i]='g'; break;
                case 'm' : g[i]='l'; break;
                case 'n' : g[i]='b'; break;
                case 'o' : g[i]='k'; break;
                case 'p' : g[i]='r'; break;
                case 'q' : g[i]='z'; break;
                case 'r' : g[i]='t'; break;
                case 's' : g[i]='n'; break;
                case 't' : g[i]='w'; break;
                case 'u' : g[i]='j'; break;
                case 'v' : g[i]='p'; break;
                case 'w' : g[i]='f'; break;
                case 'x' : g[i]='m'; break;
                case 'y' : g[i]='a'; break;
                case 'z' : g[i]='q'; break;
            }
        }
        fprintf(fout, "Case #%d: %s", c,g);
    }

    /* --------------- END --------------- */
}

/*
fscanf(fin, "%s", a);
fprintf(fout, "%d", a);
*/
