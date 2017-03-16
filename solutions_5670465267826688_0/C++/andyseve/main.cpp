#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int S[200004];
int mul(int a, int b){
    if(a == 1 || b == 1 || a == -1 || b == -1) return a * b;
    if(a < 0) return -mul(-a,b);
    if(b < 0) return -mul(a,-b);
    if(a == b) return -1;
    if(a == 2 && b == 3) return 4; if(a == 3 && b == 2) return -4;
    if(a == 3 && b == 4) return 2; if(a == 4 && b == 3) return -2;
    if(a == 4 && b == 2) return 3; if(a == 2 && b == 4) return -3;
    return 0;
}


int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        long long L, X;
        cin >> L >> X;
        for(int i = 0; i < L; i++){
            char c;
            cin >> c;
            for(int j = 0; j < X && j < 12; j++) S[L*j + i] = c - 'g';
        }
        int prod = 1;
        for(int i = 0; i < L; i++) prod = mul(prod,S[i]);
        if(prod == 1) {
            cout << "Case #" << T+1<< ": " << "NO" << "\n";
            continue;
        }
        if(prod == -1){
            if(X % 2 == 0){
                cout << "Case #" << T+1<< ": " << "NO" << "\n";
                continue;
            }
            else{
                if(6 < X) X = 6;
                int find = 1, cur = 2;
                for(int i = 0; i < X * L; i++){
                    find = mul(find,S[i]);
                    if(find== cur) {cur++; find = 1;}
                    if(cur == 5){
                        cout << "Case #" << T+1<< ": " << "YES" << "\n";
                        break;
                    }
                    if(i == X * L - 1){
                        cout << "Case #" << T+1<< ": " << "NO" << "\n";
                    }
                }
            }
        }
        else{
            if(X % 4 == 0 || X % 2 == 1){
            cout << "Case #" << T+1<< ": " << "NO" << "\n";
            continue;
            }
            if(12 < X) X = 12;
            int find = 1, cur = 2;
            for(int i = 0; i < X * L; i++){
                find = mul(find,S[i]);
                if(find== cur) {cur++; find = 1;}
                if(cur == 5){
                    cout << "Case #" << T+1<< ": " << "YES" << "\n";
                    break;
                }
                if(i == X * L - 1){
                    cout << "Case #" << T+1<< ": " << "NO" << "\n";
                }
            }
        }
    }
    return 0;
}
