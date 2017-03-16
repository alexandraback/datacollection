//
//  main.cpp
//  Lottery S
//
//  Created by Ignas Kancleris on 2014-05-03.
//  Copyright (c) 2014 Ignas Kancleris. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        int ans = 0;
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < b; k++) {
                if (s > (j&k)) {
                    ans++;
                }
            }
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}

