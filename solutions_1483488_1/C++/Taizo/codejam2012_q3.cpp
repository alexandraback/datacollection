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
#include <set>
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

    int ans = 0;

    char *s = strtok(cp,delim);
    int digit_num = strlen(s);
    int a = atoi(s);
    cp = NULL;
    int b = atoi(strtok(cp,delim));


    for(int j=b;j>=a;j--){
      std::set<int> already;
      already.clear();

      char num[32];
      sprintf(num,"%d",j);

      while(strlen(num) < digit_num){// 0 を左詰め
        char tmp[32];
        strcpy(tmp,"0");
        strcat(tmp,num);
        strcpy(num,tmp);
      }


      for(int k=1;k<digit_num;++k){
        int m_pos = 0;
        int n_pos = k;
        bool recycled = false;// n > m を満たすか
        while (n_pos != k - 1){
          if (num[m_pos] < num[n_pos]){
            break;
          }
          if (num[m_pos] > num[n_pos]){
            recycled = true;
            break;
          }
          else {
            m_pos = (m_pos + 1) % digit_num;
            n_pos = (n_pos + 1) % digit_num;
          }
        }

        if (recycled){
          char recycled_num[32];
          strcpy(recycled_num,&num[k]);
          strncat(recycled_num,num,k);
          int candidate = atoi(recycled_num);
          if (candidate >= a){
            if (already.find(candidate) == already.end()){
              already.insert(candidate);
              ++ans;
            }
          }
        }
      }
    }
    printf("%d\n",ans);
  }

  fclose(file);



  return 0;
}


