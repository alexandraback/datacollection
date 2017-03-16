/*
 * main.cpp
 *
 *  Created on: 2011/09/24
 *      Author: taik
 */


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long s64;

//#define debug_printf printf
#define debug_printf

static double a1(int ji,int N,int s,int s_dash){
  return ((double)(s + s_dash - ji * N )) / (double)(s * N);
}

int main(int argc,const char *argv[]){

  int T,prob = 1;
  int N;
  int j[201];
  vector<int> all;
  int ans;
  for (cin >> T;T--;){
    cin >> N;
    all.clear();

    int sum = 0;
    for(int i=0;i<N;++i){
      cin >> j[i];
      sum += j[i];
      all.push_back(j[i]);
    }

    sort(all.begin(),all.end());

    printf("Case #%d:",prob++);
    for(int i=0;i<N;++i){
      int s_dash = sum;
      double cand;
      for(int k=all.size()-1;k>=0;k--){
        cand = a1(j[i],k + 1,sum,s_dash);
        if (cand < 0){
          cand = 0.0;
          break;
        }

        int p = j[i] + ((double)sum) * cand;
        if (p >= all[k] ){
          break;
        }

        s_dash -= all[k];
      }
      printf(" %f",cand * 100.0);
    }
    printf("\n");


  }


  return 0;
}


