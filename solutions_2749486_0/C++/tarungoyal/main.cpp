/* 
 * File:   main.cpp
 * Author: tarungoyal
 *
 * Created on May 12, 2013, 2:40 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

typedef unsigned long long ulint;
/*
 * 
 */



int main(int argc, char** argv) {
    
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int I=1;I<=t;I++)
    {
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        char *str = new char[510];
        int i=0;
        if(x>0)
        {
            for(;i<x*2;i+=2)
            {
                str[i] = 'W';
                str[i+1] = 'E';
            }
        }
        else
        {
            x = x*-1;
            for(;i<x*2;i+=2)
            {
                str[i] = 'E';
                str[i+1] = 'W';
            }
        }
        if(y>0)
        {
            for(;i<x*2+y*2;i+=2)
            {
                str[i] = 'S';
                str[i+1] = 'N';
            }
        }
        else
        {
            y = y*-1;
            for(;i<x*2+y*2;i+=2)
            {
                str[i] = 'N';
                str[i+1] = 'S';
            }
        }
        str[i] = '\0';
        fprintf(fout,"Case #%d: %s\n",I,str);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
