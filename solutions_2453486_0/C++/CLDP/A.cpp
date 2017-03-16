#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string p[4];


int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "Case #" << i << ": ";
        for (int j = 0; j < 4; ++j) cin >> p[j];  
        
        bool flag = false;
        int a, b, emp = 0;
        for (int j = 0; j < 4; ++j) {
            a = 0; b = 0;
            for (int k = 0; k < 4; ++k)
             if (p[j][k] == 'X') {
                 ++a;         
             } else
             if (p[j][k] == 'O') {
                 ++b;         
             } else 
             if (p[j][k] == 'T') {
                 ++a; ++b;         
             } else {
                 ++emp;       
             }
            if (a == 4) {
                cout << "X won" << endl; 
                flag = true;
            } else
            if (b == 4) {
                cout << "O won" << endl; 
                flag = true;
            }
            if (flag) break;
        }
        
        if (flag) continue;
        
        for (int j = 0; j < 4; ++j) {
            a = 0; b = 0;
            for (int k = 0; k < 4; ++k)
             if (p[k][j] == 'X') {
                 ++a;         
             } else
             if (p[k][j] == 'O') {
                 ++b;         
             } else 
             if (p[k][j] == 'T') {
                 ++a; ++b;         
             } else {
                 ++emp;       
             }
            if (a == 4) {
                cout << "X won" << endl; 
                flag = true;
            } else
            if (b == 4) {
                cout << "O won" << endl; 
                flag = true;
            }
            if (flag) break;
        }
        
        if (flag) continue;
        
        a = 0; b = 0;
        for (int j = 0; j < 4; ++j) {
             if (p[j][j] == 'X') {
                 ++a;         
             } else
             if (p[j][j] == 'O') {
                 ++b;         
             } else 
             if (p[j][j] == 'T') {
                 ++a; ++b;         
             } else {
                 ++emp;       
             }
        }
        
        if (a == 4) {
            cout << "X won" << endl; 
            flag = true;
        } else
        if (b == 4) {
            cout << "O won" << endl; 
            flag = true;
        }
        
        if (flag) continue;
        
        a = 0; b = 0;
        for (int j = 0; j < 4; ++j) {
             if (p[3-j][j] == 'X') {
                 ++a;         
             } else
             if (p[3-j][j] == 'O') {
                 ++b;         
             } else 
             if (p[3-j][j] == 'T') {
                 ++a; ++b;         
             } else {
                 ++emp;       
             }
        }
        
        if (a == 4) {
            cout << "X won" << endl; 
            flag = true;
        } else
        if (b == 4) {
            cout << "O won" << endl; 
            flag = true;
        }
        
        if (flag) continue;
        
        if (emp == 0) {
            cout << "Draw" << endl;     
        } else {
            cout << "Game has not completed" << endl;
        }
        
          
    }
    return 0;    
}
