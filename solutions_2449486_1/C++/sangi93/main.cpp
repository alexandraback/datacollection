//
//  main.cpp
//  Lawnmower
//
//  Created by Ignas Kancleris on 2013-04-13.
//  Copyright (c) 2013 Ignas Kancleris. All rights reserved.
//

#include <iostream>
#include <cstdio>


using namespace std;

int main(int argc, const char * argv[])
{
    
    
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int n, w, h;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> h >> w;
        int map[w][h];
        int map2[w][h];
        for (int a = 0; a < h; a++) {
            int maxH = 0;
            for (int b = 0; b < w; b++) {
                cin >> map[b][a];
                maxH = max(maxH, map[b][a]);
            }
            for (int b = 0; b < w; b++) {
                map2[b][a] = maxH;
            }
        }
        for (int a = 0; a < w; a++) {
            int maxH = 0;
            for (int b = 0; b < h; b++) {
                maxH = max(maxH, map[a][b]);
            }
            for (int b = 0; b < h; b++) {
                if (map2[a][b] > maxH) {
                    map2[a][b] = maxH;
                }
            }
        }
        bool ok = true;
        for (int a = 0; a < w && ok; a++) {
            for (int b = 0; b < h && ok; b++) {
                if (map[a][b] != map2[a][b]) {
                    ok = false;
                }
            }
        }
        cout << "Case #"<<i+1 << ": " << (ok?"YES":"NO") << endl;
    }
    return 0;
}

