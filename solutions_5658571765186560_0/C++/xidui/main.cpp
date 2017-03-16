//
//  main.cpp
//  Ominous Omino
//
//  Created by apple on 15/4/11.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

#define RICHARD(i) (cout << "Case #" << (i) << ": RICHARD" << endl);continue;
#define GABRIEL(i) (cout << "Case #" << (i) << ": GABRIEL" << endl);continue;
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a < b ? b : a)

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Documents/coding/Xcode/Google Code Jam/Ominous Omino/Ominous Omino/output1.txt");
    ifstream cin("/Users/apple/Documents/coding/Xcode/Google Code Jam/Ominous Omino/Ominous Omino/D-small-attempt6.in.txt");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        int X, R, C;
        cin >> X >> R >> C;
//        if (X >= 7 || (R * C) % X != 0 || X > MAX(R, C) || ((MIN(R, C) != 1) && (X >= MIN(R, C) * 2)) ){
//            RICHARD(t);
//        }
//        if (MIN(R, C) == 1){
//            if (X >= 3){
//                RICHARD(t);
//            }else{
//                GABRIEL(t);
//            }
//        }
//        if (X == 1 || X <= MIN(R, C)){
//            /* these cases are so fucking */
//            if (X == 3 && R == 3 && C == 3){
//                RICHARD(t);
//            }
//            GABRIEL(t);
//        }
//        
//        /* to deal with 4 (3, 4) and 3 (2, 3)
//         */
//        if (X == 3){
//            GABRIEL(t);
//        }
//        else if (X == 4){
//            RICHARD(t);
//        }
//        continue;
        
        int temp = R + C;
        R = MIN(R, C);
        C = temp - R;
        if (R == 1 && C == 1 && X == 1){
            GABRIEL(t);
        }
        if (R == 1 && C == 1 && X >= 2){
            RICHARD(t);
        }
        if (R == 1 && C == 2 && X == 1){
            GABRIEL(t);
        }
        if (R == 1 && C == 2 && X == 2){
            GABRIEL(t);
        }
        if (R == 1 && C == 2 && X >= 3){
            RICHARD(t);
        }
        if (R == 1 && C == 3 && X == 1){
            GABRIEL(t);
        }
        if (R == 1 && C == 3 && X == 2){
            RICHARD(t);
        }
        if (R == 1 && C == 3 && X == 3){
            RICHARD(t);
        }
        if (R == 1 && C == 3 && X == 4){
            RICHARD(t);
        }
        if (R == 1 && C == 4 && X == 1){
            GABRIEL(t);
        }
        if (R == 1 && C == 4 && X == 2){
            GABRIEL(t);
        }
        if (R == 1 && C == 4 && X == 3){
            RICHARD(t);
        }
        if (R == 1 && C == 4 && X == 4){
            RICHARD(t);
        }
        if (R == 2 && C == 2 && X == 1){
            GABRIEL(t);
        }
        if (R == 2 && C == 2 && X == 2){
            GABRIEL(t);
        }
        if (R == 2 && C == 2 && X == 3){
            RICHARD(t);
        }
        if (R == 2 && C == 2 && X == 4){
            RICHARD(t);
        }
        if (R == 2 && C == 3 && X == 1){
            GABRIEL(t);
        }
        if (R == 2 && C == 3 && X == 2){
            GABRIEL(t);
        }
        if (R == 2 && C == 3 && X == 3){
            GABRIEL(t);
        }
        if (R == 2 && C == 3 && X == 4){
            RICHARD(t);
        }
        if (R == 2 && C == 4 && X == 1){
            GABRIEL(t);
        }
        if (R == 2 && C == 4 && X == 2){
            GABRIEL(t);
        }
        if (R == 2 && C == 4 && X == 3){
            RICHARD(t);
        }
        if (R == 2 && C == 4 && X == 4){
            RICHARD(t);
        }
        if (R == 3 && C == 3 && X == 1){
            GABRIEL(t);
        }
        if (R == 3 && C == 3 && X == 2){
            RICHARD(t);
        }
        if (R == 3 && C == 3 && X == 3){
            GABRIEL(t);
        }
        if (R == 3 && C == 3 && X == 4){
            RICHARD(t);
        }
        if (R == 3 && C == 4 && X == 1){
            GABRIEL(t);
        }
        if (R == 3 && C == 4 && X == 2){
            GABRIEL(t);
        }
        if (R == 3 && C == 4 && X == 3){
            GABRIEL(t);
        }
        if (R == 3 && C == 4 && X == 4){
            GABRIEL(t);
        }
        if (R == 4 && C == 4 && X == 1){
            GABRIEL(t);
        }
        if (R == 4 && C == 4 && X == 2){
            GABRIEL(t);
        }
        if (R == 4 && C == 4 && X == 3){
            RICHARD(t);
        }
        if (R == 4 && C == 4 && X == 4){
            GABRIEL(t);
        }
    }
    return 0;
}
