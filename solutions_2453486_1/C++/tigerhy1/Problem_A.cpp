#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
#include <sstream>
using namespace std; 

string a[4]; 

bool win(char ch) {
    for (int i = 0; i < 4; i++) {
        bool tmp = true; 
        for (int j = 0; j < 4; j++) {
            if (a[i][j] != ch && a[i][j] != 'T') {
                tmp = false; 
                break; 
            }
        }
        if (tmp) {
            return true; 
        }
    }    
    
    for (int j = 0; j < 4; j++) {
        bool tmp = true; 
        for (int i = 0; i < 4; i++) {
            if (a[i][j] != ch && a[i][j] != 'T') {
                tmp = false; 
                break; 
            }
        } 
        if (tmp) {
            return true; 
        }
    }
   
    bool tmp = true;  
    for (int i = 0; i < 4; i++) {
        if (a[i][i] != ch && a[i][i] != 'T') {
            tmp = false; 
            break; 
        }
    }
    if (tmp) {
        return true; 
    }
    
    tmp = true; 
    for (int i = 0; i < 4; i++) {
        if (a[i][3-i] != ch && a[i][3-i] != 'T') {
            tmp = false; 
            break; 
        }
    }
    if (tmp) {
        return true; 
    }
    
    return false; 
}

bool check_full() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == '.') {
                return false; 
            }
        }
    }
    return true; 
}

void solve(int t) {
    //string ret = "Case #";
    bool x = win('X');
    bool o = win('O');
    
    //cout << x << " " << o << endl; 
    
    string res = ""; 
    if (x) {
        res = "X won"; 
    }
    else if (o) {
        res = "O won"; 
    }
    else if (!x && !o) {
        bool full = check_full(); 
        if (full) {
            res = "Draw"; 
        }
        else {
            res = "Game has not completed"; 
        }
    }
    
    
    //ret = ret + " " + res; 
    cout << "Case #" << t << ": " << res << endl; 
}

int main() {
    int T; 
    cin >> T; 
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[j];
        }        
        solve(i + 1); 
    }
    //system("pause"); 
}
