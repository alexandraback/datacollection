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
    char *cp = line;
    int n = atoi(strtok(cp,delim));
    cp = NULL;
    int s = atoi(strtok(cp,delim));
    int p = atoi(strtok(cp,delim));

    int ans = 0;
    if (p==0){
      ans = n;
    }
    else{
      for (int j=0;j<n;++j){
        int t = atoi(strtok(cp,delim));
        if (p == 1){
          if (t >= 1){
            ++ans;
          }
        }
        else{
          if (t >= (3*p-2)){
            ++ans;
          }
          else if ((s>0) && (t >= (3*p-4))){
            ++ans;
            --s;
          }
        }
      }
    }
    printf("%d\n",ans);
  }

  fclose(file);



  return 0;
}


