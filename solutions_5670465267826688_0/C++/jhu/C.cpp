//
//  C.cpp
//  Cpp
//
//  Created by Johnson Hu on 11/4/15.
//  Copyright (c) 2015 Johnson Hu. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main( )
{
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("C-small-attempt0.in");    out_stream.open("C-small-attempt0.out");

    int T; //cases
    in_stream >> T;
    int L, X;
    string s;
    int table[4][4] = {
      {0, 1, 2, 3},
      {1, 0, 3, 2},
      {2, 3, 0, 1},
      {3, 2, 1, 0}
    };
    int sig[4][4] = {
      {1, 1, 1, 1},
      {1, -1, 1, -1},
      {1, -1, -1, 1},
      {1, 1, -1, -1}
    };
    for (int i = 0; i < T; i++) {
      bool ans = true;
      in_stream >> L >> X;
      in_stream >> s;
      int a[99999];
      for (int j = 0; j < L; j++) {
        if (s[j] == 'i') {
          a[j] = 1;
        } else if (s[j] == 'j') {
          a[j] = 2;
        } else if (s[j] == 'k') {
          a[j] = 3;
        }
      }
      int total = 0;
      int sgn = 1;
      for (int j = 0; j < L; j++) {
        int k = table[total][a[j]];
        int l = sig[total][a[j]];
        total = k;
        sgn = sgn * l;
      }
      if (total != 0 && (X % 4 != 2)) {
        ans = false;
      } else if (total == 0 && sgn == 1) {
        ans = false;
      } else if (total == 0 && sgn == -1 && (X % 2 != 1)) {
        ans = false;
      } else if (X <= 8) {
        for (int m = 1; m < X; m++) {
          for (int j = 0; j < L; j++) {
            a[j + m * L] = a[j];
          }
        }
        int total1 = 0;
        int sgn1 = 1;
        int pos1 = -1;
        while (total1 != 1 || sgn1 != 1) {
          pos1++;
          int k = table[total1][a[pos1]];
          int l = sig[total1][a[pos1]];
          total1 = k;
          sgn1 = sgn1 * l;
          //out_stream<<total1<<endl<<sgn1<<endl;
          if (pos1 == L * X - 1) {
            total1 = 1;
            sgn1 = 1;
            ans = false;
          }
        }
        //out_stream<<pos1<<endl;
        int total2 = 0;
        int sgn2 = 1;
        int pos2 = L * X;
        while (total2 != 3 || sgn2 != 1) {
          pos2--;
          int k = table[a[pos2]][total2];
          int l = sig[a[pos2]][total2];
          total2 = k;
          sgn2 = sgn2 * l;
          if (pos2 == 1) {
            total2 = 3;
            sgn2 = 1;
            ans = false;
          }
        }
        //out_stream<<pos2<<endl;
        if (pos1 >= pos2) ans = false;
      } else if (X > 8) {
        for (int m = 1; m < 8; m++) {
          for (int j = 0; j < L; j++) {
            a[j + m * L] = a[j];
          }
        }
        int total1 = 0;
        int sgn1 = 1;
        int pos1 = -1;
        while (total1 != 1 || sgn1 != 1) {
          pos1++;
          int k = table[total1][a[pos1]];
          int l = sig[total1][a[pos1]];
          total1 = k;
          sgn1 = sgn1 * l;
          if (pos1 == L * 8 - 1) {
            total1 = 1;
            sgn1 = 1;
            ans = false;
          }
        }
        int total2 = 0;
        int sgn2 = 1;
        int pos2 = L * 8;
        while (total2 != 3 || sgn2 != 1) {
          pos2--;
          int k = table[a[pos2]][total2];
          int l = sig[a[pos2]][total2];
          total2 = k;
          sgn2 = sgn2 * l;
          if (pos2 == 1) {
            total2 = 3;
            sgn2 = 1;
            ans = false;
          }
        }
        if (pos1 >= pos2) ans = false;
      }
      out_stream << "Case #" << i+1 << ": ";
      if (ans) {
        out_stream << "YES";
      } else out_stream << "NO";
      if (i < T - 1) out_stream << endl;
    }


    in_stream.close();
    out_stream.close();
    return 0;
}
