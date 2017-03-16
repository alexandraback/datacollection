//
//  D.cpp
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
    in_stream.open("D-small-attempt0.in");    out_stream.open("D-small-attempt0.out");

    int T; //cases
    in_stream >> T;
    int X, R, C;
    for (int i = 0; i < T; i++) {
      bool possible = true;
      in_stream >> X >> R >> C;
      if ( X > 6) {
        possible = false;
      } else if ((R * C % X) != 0){
        possible = false;
      } else {
        int max, min;
        if (R > C) {
          max = R;
          min = C;
        } else {
          max = C;
          min = R;
        }
        if (max < X) {
          possible = false;
        } else if (min < (X - 1) / 2 + 1) {
          possible = false;
        } else if (X == 4 && min == 2) {
          possible = false;
        } else if (X == 6 && min == 3) {
          possible = false;
        }
      }
      out_stream << "Case #" << i+1 << ": ";
      if (possible) {
        out_stream << "GABRIEL";
      } else out_stream << "RICHARD";
      if (i < T - 1) out_stream << endl;
    }

    in_stream.close();
    out_stream.close();
    return 0;
}
