//
//  B.cpp
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
    in_stream.open("B-large.in");    out_stream.open("B-large.out");

    int T; //cases
    int D; //non-empty plates
    int P[1000];
    in_stream >> T;
    for (int i = 0; i < T; i++) {
      in_stream >> D;
      int max = 0;
      for (int j = 0; j < D; j++) {
        in_stream >> P[j];
        if (P[j] > max) max = P[j];
      }
      int total = max;
      for (int j = 1; j < max; j++) {
        int sum = 0;
        for (int k = 0; k < D; k++) {
          sum += (P[k] + j - 1) / j - 1;
        }
        if (sum + j < total) total = sum + j;
      }
      out_stream << "Case #" << i+1 << ": " << total;
      if (i < T - 1) out_stream << endl;
    }


    in_stream.close();
    out_stream.close();
    return 0;
}
