//
//  main.cpp
//  4
//
//  Created by Wanjia He on 4/9/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin;
    ofstream fout;
    fin.open("4.in");
    fout.open("4.out");
    int n, i, j, k, l, c, s, least;
    long f[101];
    fin >> n;
    for (l = 1; l <= n; l++){
        fin >> k >> c >> s;
        least = ceil(double(k) / c);
        if (s < least){
            fout << "Case #" << l << ": IMPOSSIBLE" << endl;
        }else{
            for (i = 1; i <= k; i++)
                f[i] = i;
            for (i = 2; i <= c; i++)
                for (j = 1; j <= k; j++)
                    if (j == k){
                        f[j] = f[j] * k;
                    }else{
                        f[j] = (f[j] - 1) * k + min(i + j - 1, k);
                    }
            fout << "Case #" << l << ":";
            for (i = 0; i < least; i++)
                fout << ' ' << f[i * c + 1];
            fout << endl;
        }
    }
    cout << "done" << endl;
    fin.close();
    fout.close();
}
