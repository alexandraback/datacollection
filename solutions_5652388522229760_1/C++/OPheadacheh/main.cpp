//
//  main.cpp
//  1
//
//  Created by Wanjia He on 4/9/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin;
    ofstream fout;
    fin.open("1.in");
    fout.open("1.out");
    int n, i, j, num, x, y, r, x_now;
    int f[10];
    fin >> n;
    for (i = 1; i <= n; i++){
        fin >> x;
        if (x==0){
            fout << "Case #" << i << ": INSOMNIA" << endl;
        }else{
            num = 0;
            for (j = 0; j <= 9; j++){
                f[j] = 0;
            }
            x_now = 0;
            while (num < 10){
                x_now += x;
                y = x_now;
                while (y > 0){
                    r = y % 10;
                    y = y / 10;
                    if (f[r] == 0){
                        f[r] = 1;
                        num++;
                    }
                }
            }
            fout << "Case #" << i << ": " << x_now << endl;
        }
    }
    cout << "done" << endl;
    fin.close();
    fout.close();
}
