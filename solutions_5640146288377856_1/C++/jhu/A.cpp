//
//  A.cpp
//  Cpp
//
//  Created by Johnson Hu on 10/5/15.
//  Copyright (c) 2015 Johnson Hu. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main( )
{
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("A-large.in");
    out_stream.open("A-large.out");

    int T; //cases
    int R, C, W;
    in_stream >> T;
    for (int i = 0; i < T; i++) {
        in_stream >> R >> C >> W;
        int n; //least tries;
        n = 0;
        int k;
        if (C % W == 0) {
            k = C / W;
        } else k = C / W + 1;
        n = n + k * (R - 1);
        n = n + (k - 1) + W;
        out_stream << "Case #" << i+1 << ": " << n;
        if (i < T - 1) out_stream << endl;
    }


    in_stream.close();
    out_stream.close();
    return 0;
}
