#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>

using namespace std;

string A, B, AA, BB;
int n;

long long best1, best2;
string ans1, ans2;

long long convert(string a) {
    long long rez = 0;
    for (int i = 0; i < a.size(); i++) {
        rez = (rez * 10 + a[i] - '0');
    }
    return rez;
}

long long mabs(long long a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

void optimize(string q, string w) {
    long long Q = convert(q);
    long long W = convert(w);
    if (best1 == -1) {
        best1 = Q;
        best2 = W;
        ans1 = q;
        ans2 = w;
        return;
    }
    if (mabs(Q - W) < mabs(best1 - best2)) {
        best1 = Q;
        best2 = W;
        ans1 = q;
        ans2 = w;
        return;   
    }
    if (mabs(Q - W) > mabs(best1 - best2)) {
        return;
    }
    if (Q < best1 || (Q == best1 && W < best2)) {
        best1 = Q;
        best2 = W;
        ans1 = q;
        ans2 = w;
        return;
    }
}

void gen(string a, string b, int sign) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '?') {
            if (sign == -1) {
                a[i] = '9';
            } else {
                a[i] = '0';
            }
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '?') {
            if (sign == 1) {
                b[i] = '9';
            } else {
                b[i] = '0';
            }
        }
    }
    optimize(a, b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);        
    int testCases;
    cin >> testCases;    
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
        
        cin >> A >> B;
        n = A.size();
        bool broken;
        
        best1 = -1;
        
        AA = A;
        BB = B;
        broken = false;
        for (int eq = 0; eq < n; eq++) {
            if (AA[eq] != '?' && BB[eq] != '?') {
                if (AA[eq] < BB[eq]) {
                    gen(AA, BB, -1);
                    broken = true;
                    break;
                }
                if (AA[eq] > BB[eq]) {
                    broken = true;
                    break;
                }                
                continue;
            }            
            if (AA[eq] == '?' && BB[eq] == '?') {
                AA[eq] = '0';
                BB[eq] = '1';
                gen(AA, BB, -1);
                AA[eq] = '0';
                BB[eq] = '0';
                continue;
            }
            if (AA[eq] == '?') {
                if (BB[eq] != '0') {
                    AA[eq] = BB[eq] - 1;
                    gen(AA, BB, -1);
                }
                AA[eq] = BB[eq];
                continue;
            }
            if (AA[eq] != '9') {
                BB[eq] = AA[eq] + 1;
                gen(AA, BB, -1);
            }
            BB[eq] = AA[eq];                
        } 
        if (!broken) {
            optimize(AA, BB);
        }
        
        AA = A;
        BB = B;
        broken = false;
        for (int eq = 0; eq < n; eq++) {
            if (AA[eq] != '?' && BB[eq] != '?') {
                if (AA[eq] > BB[eq]) {
                    gen(AA, BB, 1);
                    broken = true;
                    break;
                }
                if (AA[eq] < BB[eq]) {
                    broken = true;
                    break;
                }                
                continue;
            }            
            if (AA[eq] == '?' && BB[eq] == '?') {
                AA[eq] = '1';
                BB[eq] = '0';
                gen(AA, BB, 1);
                AA[eq] = '0';
                BB[eq] = '0';
                continue;
            }
            if (AA[eq] == '?') {
                if (BB[eq] != '9') {
                    AA[eq] = BB[eq] + 1;
                    gen(AA, BB, 1);
                }
                AA[eq] = BB[eq];
                continue;
            }
            if (AA[eq] != '0') {
                BB[eq] = AA[eq] - 1;
                gen(AA, BB, 1);
            }
            BB[eq] = AA[eq];                
        } 
        if (!broken) {
            optimize(AA, BB);
        }
        
        cout << ans1 << " " << ans2 << endl;
    } 
    return 0;
}