/*
 * main.cpp
 *
 *  Created on: 2011/09/24
 *      Author: taik
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>

typedef long long s64;

//#define debug_printf printf
#define debug_printf

static char code_map[26] = {
    'y',//a
    'h',//b
    'e',//c
    's',//d
    'o',//e
    'c',//f
    'v',//g
    'x',//h
    'd',//i
    'u',//j
    'i',//k
    'g',//l
    'l',//m
    'b',//n
    'k',//o
    'r',//p
    'z',//q
    't',//r
    'n',//s
    'w',//t
    'j',//u
    'p',//v
    'f',//w
    'm',//x
    'a',//y
    'q',//z
};



int main(int argc,const char *argv[]){

  if (argc < 2){
    printf("Usage : %s input\n",argv[0]);
    return 0;
  }

  FILE *file = fopen(argv[1],"r");

  char line[65536];
  int tc; // test case
  const char *delim = " ";

  if(fgets(line,sizeof(line),file) == NULL){
    return 0;
  }
  tc = atoi(line);
  for(int i=0;i<tc;++i){
    printf("Case #%d: ",i+1);
    fgets(line,sizeof(line),file);
    for(int j=0;j<strlen(line);j++){
      if ((line[j] >= 'a') && (line[j] <= 'z')){
        printf("%c",code_map[line[j] - 'a']);
      }
      else{
        printf("%c",line[j]);
      }
    }
   }

  fclose(file);



  return 0;
}


