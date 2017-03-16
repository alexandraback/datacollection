//
//  main.cpp
//  Tic_Tac_Toe_Tomek
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
    
    char lenta[4][4];
    
    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {
        bool complete = true;
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                cin >> lenta[a][b];
                if (lenta[a][b] == '.') {
                    complete = false;
                }
            }
        }

        char laimi = '.';
        for (int a = 0; a < 4; a++) {
            char cur = lenta[a][0];
            if (cur == '.') {
                continue;
            }
            if (cur == 'T') {
                cur = lenta[a][1];
                if (cur == '.') {
                    continue;
                }
            }
            bool l = true;
            for (int b = 1; b < 4; b++) {
                if (lenta[a][b] == '.') {
                    complete = false;
                }
                if (lenta[a][b] != cur && lenta[a][b] != 'T') {
                    l = false;
                    break;
                }
            }
            if (l) {
                laimi = cur;
            }
        }
        for (int a = 0; a < 4; a++) {
            char cur = lenta[0][a];
            if (cur == '.') {
                continue;
            }
            if (cur == 'T') {
                cur = lenta[1][a];
                if (cur == '.') {
                    continue;
                }
            }
            bool l = true;
            for (int b = 1; b < 4; b++) {
                if (lenta[b][a] == '.') {
                    complete = false;
                }
                if (lenta[b][a] != cur && lenta[b][a] != 'T') {
                    l = false;
                    break;
                }
            }
            if (l) {
                laimi = cur;
            }
        }
        bool l = true;
        char cur = lenta[0][0];
        if (cur != '.') {
            bool calc = true;
            if (cur == 'T') {
                cur = lenta[1][1];
                if (cur == '.') {
                    l = false;
                }
            }
            for (int a = 1; a < 4; a++) {
                if (lenta[a][a] != cur && lenta[a][a] != 'T') {
                    l = false;
                    break;
                }
            }
            if (l) {
                laimi = cur;
            }
        }
        
        
        l = true;
        cur = lenta[3][0];
        if (cur != '.') {
            if (cur == 'T') {
                cur = lenta[2][1];
                if (cur == '.') {
                    l = false;
                }
            }
            for (int a = 1; a < 4; a++) {
                if (lenta[3-a][a] != cur && lenta[3-a][a] != 'T') {
                    l = false;
                    break;
                }
            }
            if (l) {
                laimi = cur;
            }
        }
        
        
        if (laimi != '.') {
            cout << "Case #" << i+1 << ": " << laimi << " won" << endl;
        }else if(!complete){
            cout << "Case #" << i+1 << ": Game has not completed" << endl;
        }else{
            cout << "Case #" << i+1 << ": Draw" << endl;
        }
    }
    
    return 0;
}

