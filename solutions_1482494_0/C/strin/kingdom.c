#include "stdio.h"

int star[2000][2];
int memory[2000];
int flag0[2000], flag1[2000];
int s0[2000][2], s1[2000][2];
int f0, f1;

int compare( int x, int y) {
    if( s0[x][0] < s0[y][0]) {
        return -1;
    }else if( s0[x][0] > s0[y][0]) {
        return 1;
    }else{
        if( s0[x][1] > s0[y][1]) {
            return -1;
        }else if( s0[x][1] < s0[y][1]) {
            return 1;
        }else return 0;
    }
}

int qsort0( int l, int r) {
    int i = l-1, j = r+1, x = l;
    if( l >= r) return 0;
    while( 1) {
        do{ ++i;}while( compare( i, x) == -1);
        do{ --j;}while( compare( j, x) == 1);
        if( i < j) {
            s0[i][0] ^= s0[j][0];
            s0[j][0] ^= s0[i][0];
            s0[i][0] ^= s0[j][0];
            s0[i][1] ^= s0[j][1];
            s0[j][1] ^= s0[i][1];
            s0[i][1] ^= s0[j][1];
            flag0[i] ^= flag0[j];
            flag0[j] ^= flag0[i];
            flag0[i] ^= flag0[j];
        }else break;
    }    
    qsort0( l, j);
    qsort0( j+1, r);
    return 0;
}

int qsort1( int l, int r) {
    int i = l-1, j = r+1, x = s1[l][1];
    if( l >= r) return 0;
    while( 1) {
        do{ ++i;}while( s1[i][1] < x);
        do{ --j;}while( s1[j][1] > x);
        if( i < j) {
            s1[i][0] ^= s1[j][0];
            s1[j][0] ^= s1[i][0];
            s1[i][0] ^= s1[j][0];
            s1[i][1] ^= s1[j][1];
            s1[j][1] ^= s1[i][1];
            s1[i][1] ^= s1[j][1];
            flag1[i] ^= flag1[j];
            flag1[j] ^= flag1[i];
            flag1[i] ^= flag1[j];
        }else break;
    }    
    qsort1( l, j);
    qsort1( j+1, r);
    return 0;
}


int main() {
    FILE* fpin = fopen( "kingdom.in", "r");
    FILE* fpout = fopen( "kingdom.out", "w");
    int t, n;
    int starN, playN;
    
    fscanf( fpin, "%d", &t);
    for( int ti = 1; ti <= t; ti++) {
        fscanf( fpin, "%d", &n);
        for( int i = 0; i < n; i++) {
            fscanf( fpin, "%d %d", &star[i][0], &star[i][1]);
            memory[i] = 0;
            flag0[i] = i;
            flag1[i] = i;
            s0[i][0] = s1[i][0] = star[i][0];
            s0[i][1] = s1[i][1] = star[i][1];
        }
        //if( ti != 6) continue;
        printf( "1\n");
        qsort0( 0, n-1);
        qsort1( 0, n-1);
        printf( "2\n");
        f0 = f1 = 0;
        starN = playN = 0;
        for( int i = 0; i < n;i ++) {
            printf( "%d %d %d\n", s0[i][0], s0[i][1], flag0[i]);
        }
        printf( "..............\n");
        for( int i = 0; i < n;i ++) {
            printf( "%d %d %d\n", s1[i][0], s1[i][1], flag1[i]);
        }
        while( 1) {
            if( s1[f1][1] <= starN) {
                if( memory[flag1[f1]] == 1) starN++;
                else starN += 2;
                printf( "f1: %d memory: %d\n star: %d\n", f1, memory[f1], starN);
                memory[flag1[f1]] = 2;
                f1++;
                playN++;
                if( f1 == n) break;
            }else if( s0[f0][0] <= starN) {
                printf( "f0: %d star: %d\n", f0, starN);
                if( memory[flag0[f0]] == 2) {
                    f0++;
                    continue;
                }
                memory[flag0[f0]]++;
                f0++;
                playN++;
                starN += 1;
            }else{
                break;
            }
        }
        if( f1 != n) {
            fprintf( fpout, "Case #%d: Too Bad\n", ti);
        }else{
            fprintf( fpout, "Case #%d: %d\n", ti, playN);
        }
    }
    fclose( fpin);
}
