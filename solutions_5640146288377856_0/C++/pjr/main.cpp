#include <iostream>
#include <stdio.h>

using namespace std;

FILE *fin = fopen("input.txt", "r");
FILE *fout = fopen("output.txt", "w");

int r,c,w;
int result;

void input();
void process();

int main() {
    int i, T;
    fscanf(fin, "%d", &T);
    for ( i=0; i<T; i++ ) {
        input();
        process();
        fprintf(fout, "Case #%d: %d\n", i+1, result);
    }
    return 0;
}

void input() {
    fscanf(fin, "%d%d%d", &r, &c, &w);
}

void process() {
    int i;
    
    result = 0;
    for ( i=0; i<r; i++ ) {
        
        int leftWall = 0;
        int rightWall = c+1;
        
        if ( i== r-1 ) { // must hit
            while( leftWall < rightWall ) {
                if ( leftWall + w >= rightWall ) { // hit start
                    if ( leftWall + 1 == rightWall) {
                        result += w-1;
                    } else {
                        result += w;
                    }
                    break;
                } else {
                    result++;
                    leftWall = leftWall + w;
                }
            }
        } else { // do not need hit
            while( leftWall + w < rightWall ) {
                result++;
                leftWall = leftWall + w;
            }
        }
    }
}






/*
 Input
 
 3
 1 4 2
 1 7 7
 2 5 1
 
 
 Output
 
 Case #1: 3
 Case #2: 7
 Case #3: 10
 */