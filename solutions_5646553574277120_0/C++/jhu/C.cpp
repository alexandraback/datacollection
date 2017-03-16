//
//  C.cpp
//  Cpp
//
//  Created by Johnson Hu on 10/5/15.
//  Copyright (c) 2015 Johnson Hu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }

    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */

     return subset[sum][n];
}

int main( )
{
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("C-small-attempt0.in");    out_stream.open("C-small-attempt0.out");

    int T; //cases
    int C, D, V;
    int deno[30];
    bool values[31];
    in_stream >> T;
    for (int i = 0; i < T; i++) {
        in_stream >> C >> D >> V;

        for (int j = 0; j < D; j++) {
            in_stream >> deno[j];
        }
        int n = 0;
        for (int j = 1; j <= V; j++) {
            values[j] = isSubsetSum(deno, D, j);
            if (values[j]) n++;
        }
        int l = 0;
        while (n < V)
        {
            int k = 1;
            while (values[k]) k++;
            deno[D] = k;
            D++;
            l++;
            for (int j = k; j <= V; j++) {
                if (!values[j]) {
                    values[j] = isSubsetSum(deno, D, j);
                    if (values[j]) n++;
                }
            }
        }
        out_stream << "Case #" << i+1 << ": " << l;
        if (i < T - 1) out_stream << endl;
    }


    in_stream.close();
    out_stream.close();
    return 0;
}
