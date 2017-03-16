/* 
 * File:   main.c
 * Author: paulo
 * GCJ2013 Problem B
 * Created on 13 de Abril de 2013, 00:09
 */

#include <stdio.h>
#include <stdlib.h>

int middle_pos_ok(int grass[100][100], int height, int width, int line, int column);

int middle_pos_ok(int grass[100][100], int height, int width, int line, int column)
{
    int x,y, ul=0,ur=0,uu=0, ud=0;
    // goes towards the right side to find an up value
    for(x=column+1;x<width;x++){
        if(grass[line][x] > grass[line][column]){
            ur = -1;
            break;
        }
    }
    // goes towards the left side to find an up value
    for(x=column-1;x>=0;x--){
        if(grass[line][x] > grass[line][column]){
            ul = -1;
            break;
        }
    }
    // goes downwards to find an up value
    for(y=line+1;y<height;y++){
        if(grass[y][column] > grass[line][column]){
            ud = -1;
            break;
        }
    }
    // goes upwards to find an up value
    for(y=line-1;y>=0;y--){
        if(grass[y][column] > grass[line][column]){
            uu = -1;
            break;
        }
    }

    if( (ur || ul) && (uu || ud))
        return 0;
    return -1;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int grass[100][100];
    int cases, count, width, height, line, column, ok;
    scanf("%d", &cases);
    for(count=0;count<cases;count++)
    {
        scanf("%d", &height);
        scanf("%d", &width);
        for(line=0;line<height;line++)
            for(column=0;column<width;column++)
                scanf("%d", &grass[line][column]);
        ok = -1;
        for(line=0;line<height && ok;line++)
            for(column=0;column<width && ok;column++)
            {
                if(!middle_pos_ok(grass, height, width, line, column))
                    ok=0;
            }
        if(ok)
            printf("Case #%d: YES\n", count+1);
        else
            printf("Case #%d: NO\n", count+1);
    }
    
    return (EXIT_SUCCESS);
}

