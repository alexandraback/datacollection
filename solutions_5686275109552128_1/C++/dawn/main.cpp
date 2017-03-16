//GTK是我男神！！男神么么哒XD
//  main.cpp
//  15b
//
//  Created by dawn on 15-4-11.
//  Copyright (c) 2015年 dawn. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t,i = 0;
    cin >> t;
    while (i++ < t) {
        cout << "Case #" << i << ": ";
        int d,pii;
        cin >> d;
        int arr[1024] = {0}, max = 1;
        for (int j = 0; j < d; ++j) {
            cin >> pii;
            if (pii > max)
                max = pii;
            arr[pii]++;
        }
        int tm = max;
        for (int sml = 2; sml < max; ++sml) {
            int t = 0;
            for (int j = max; j > 0 && t < tm; --j) {
                int a = arr[j];
                if (a) {
                    t += (j - 1) / sml * a;
                }
            }
            if (tm > t + sml) {
                tm = t + sml;
            }
        }
        cout << tm << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
