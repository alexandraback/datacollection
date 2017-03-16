/*
 * main.cpp
 *
 *  Created on: 2011/09/24
 *      Author: taik
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long s64;

//#define debug_printf printf
#define debug_printf



int main(int argc,const char *argv[]){



  int T,prob = 1;
  double D;
  int N,A;
  for (cin >> T;T--;){
    cin >> D >> N >> A;
    double t[2001];
    double x[2001];
    double a[251];

    for(int i=0;i<N;++i){
      cin >> t[i] >> x[i];
    }
    for(int i=0;i<A;++i){
      cin >> a[i];
    }

    printf("Case #%d:\n",prob++);
    if ((N == 1) || (x[0] >= D)){ // 車は目標より遠い
      for(int i=0;i<A;++i){
        printf("%f\n",sqrt(2.0 * D / a[i]));
      }
    }
    else{
      // N == 2 のときのみ考える.
      double car_time = (D - x[0])/((x[1] - x[0]) / (t[1] - t[0]));
      double thres = 2.0 * D / (car_time * car_time);

      for(int i=0;i<A;++i){
        if (a[i] > thres){
          printf("%f\n",car_time);
        }
        else{
          printf("%f\n",sqrt(2.0 * D / a[i]));
        }

      }


    }




  }


  return 0;
}


