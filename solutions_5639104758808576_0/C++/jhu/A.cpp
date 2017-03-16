//
//  A.cpp
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
    in_stream.open("A-small-attempt0.in");    out_stream.open("A-small-attempt0.out");

    int T; //cases
    in_stream >> T;
    int max;
    string s;
    int shyness[1000];
    for (int i = 0; i < T; i++) {
      in_stream >> max;
      in_stream >> s;
      for (int j = 0; j <= max; j++) {
        shyness[j] = s[j] - '0';
      }
      int n = 0;
      int total = 0;
      for (int j = 0; j <= max; j++) {
        if (total < j) {
          n = n + (j - total);
          total = j;
        }
        total = total + shyness[j];
      }
      out_stream << "Case #" << i+1 << ": " << n;
      if (i < T - 1) out_stream << endl;
    }


    in_stream.close();
    out_stream.close();
    return 0;
}
