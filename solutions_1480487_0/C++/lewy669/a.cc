/*
 * =====================================================================================
 *
 *       Filename:  a.cc
 *
 *    Description:  jjjjjjjjjjjjjjjjj
 *
 *        Version:  1.0
 *        Created:  05.05.2012 18:04:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


  double licz(double a, double b, double s) {
    return 100.0f * max<double>((a - b + s) / (2 * s), 0.0f);
  }



  double ile_na_k(int k, double suma, vector<int>& in) {
    double ret = 0.0;
    int cc = 0;
    for(int i =0 ; i < in.size(); ++i) {
      if(in[i] < k) {
        ret += in[i];
        ++cc;
      }
    }
    return (k * cc - ret) / suma;
  }

  int suma_mniejszych(int k, vector<int> &in) {
    int ret = 0;
    for(int i = 0; i < in.size(); ++i) {
      ret += (in[i] < k) * in[i];
    }
    return ret;
  }
  int ile_mniejszych(int k, const vector<int> &in) {
    int ret = 0;
    for(int i = 0; i < in.size(); ++i) {
      ret += (in[i] < k) ;
    }
    return ret;
  }


int main() {



  cout.precision(8);
  int t;
  scanf("%d", &t);

  for(int p = 0; p < t; ++p) {
    double res = 0;
    int n;
    scanf("%d", &n);
    vector<int> in;
    vector<int> inc;
    double suma = 0.0;
    for(int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      in.push_back(a);
      suma += a;
    }

    cout << "Case #" << (p + 1) << ":";
    for(int i = 0; i < n; ++i) {
      double ret = 0.0;
      if(ile_na_k(in[i], suma, in) >= 1.0) {
        ret = 0.0;
      } else {
        int j = 1;
        while(ile_na_k(in[i] + j, suma, in) <= 1.0) {
            ++j;
        }
        double ile = ile_mniejszych(in[i] + j,  in);
        ret =  ile_na_k(in[i] + j -  1, suma, in);
        ret = ((1.0 - ret) / ile) + ((j - 1) / suma);
      }
      cout << " " << (100.0 * ret);
    }

    cout << endl;
  }
  return 0;
}
