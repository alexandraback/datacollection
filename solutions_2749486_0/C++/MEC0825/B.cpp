//
//  main.cpp
//  Google
//
//  Created by Mec0825 on 13-4-13.
//  Copyright (c) 2013年 Mec0825. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

int T;

//#define DD 500


//bool map[1005][1005];
//char back[1005][1005];
//
//bool isIn(int x, int y) {
//    if(-DD <= x && x <= DD &&
//       -DD <= y && y <= DD) return true;
//    return false;
//}
//
//bool dfs(int x, int y, int l) {
//    if(map[x+DD][y+DD]) return false;
//    
//    map[x+DD][y+DD] = 1;
//    
//    if(isIn(x+l, y)) {
//        if(dfs(x+l, y, l+1)) {
//            back[x+DD+l][y+DD] = 'E';
//        }
//    }
//    
//    if(isIn(x-l, y)) {
//        if(dfs(x-l, y, l+1)) {
//            back[x+DD-l][y+DD] = 'W';
//        }
//    }
//    
//    if(isIn(x, y+l)) {
//        if(dfs(x, y+l, l+1)) {
//            back[x+DD][y+DD+l] = 'N';
//        }
//    }
//    
//    if(isIn(x, y-l)) {
//        if(dfs(x, y-l, l+1)) {
//            back[x+DD][y+DD-l] = 'S';
//        }
//    }
//    
//    return true;
//}

//void Init() {
//    memset(map, 0, sizeof(map));
//    dfs(0,0,1);
//    
//    for(int i = -20; i < 20; i++) {
//        for(int j = -20; j < 20; j++)
//            printf("%d", map[i+100][j+100]);
//        printf("\n");
//    }
//}

void Solve() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    if(x < 0) {
        for(int i = 0; i < -x; i++) {
            printf("EW");
        }
    }
    else {
        for(int i = 0; i < x; i++) {
            printf("WE");
        }
    }
    
    if(y < 0) {
        for(int i = 0; i < -y; i++) {
            printf("NS");
        }
    }
    else {
        for(int i = 0; i < y; i++) {
            printf("SN");
        }
    }
}

int main()
{
    freopen("/Users/Mec0825/Documents/Google/2013/Round 1C/B-in.txt", "r", stdin);
    freopen("/Users/Mec0825/Documents/Google/2013/Round 1C/B-out.txt", "w", stdout);
    
//    Init();
    
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        printf("Case #%d: ",i+1);
        Solve();
        printf("\n");
    }
    
    return 0;
}
