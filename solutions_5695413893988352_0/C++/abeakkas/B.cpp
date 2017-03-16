/*
 * abeakkas
 * Google CodeJam 2016 - Round 1B
 * Problem B
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

// #define pr pair<ll,ll>
// #define vpr vector<pair<ll,ll> >

// Code snippets:
// (int*)calloc(1000000, sizeof(int));
// (int*)malloc(1000000 * sizeof(int));
// cout << setprecision(20);

using namespace std; 
ifstream fin("B.in");
ofstream fout("B.out");

ull tailmin(string s, int i) {
    ull x = 0;
    for(; i < s.length(); i++) {
        x *= 10;
        if(s[i] != '?') {
            x += s[i] - '0';
        }
    }
    return x;
}
string fillmin(string s, int i) {
    for(; i < s.length(); i++) {
        if(s[i] == '?') {
            s[i] = '0';
        }
    }
    return s;
}
ull tailmax(string s, int i) {
    ull x = 0;
    for(; i < s.length(); i++) {
        x *= 10;
        if(s[i] != '?') {
            x += s[i] - '0';
        } else {
            x += 9;
        }
    }
    return x;
}
string fillmax(string s, int i) {
    for(; i < s.length(); i++) {
        if(s[i] == '?') {
            s[i] = '9';
        }
    }
    return s;
}

ull pow(ull a, ull b) {
    if(b == 0) return 1;
    else return a * pow(a, b - 1);
}

int main(){
    int T;
    fin >> T;
    for(int iT = 1; iT <= T; iT++) {
        string C, J;
        fin >> C >> J;
        for(int i = 0; i < C.length(); i++) {
            ull cmax = tailmax(C, i + 1);
            ull cmin = tailmin(C, i + 1);
            ull jmax = tailmax(J, i + 1);
            ull jmin = tailmin(J, i + 1);
            if(C[i] == '?' && J[i] == '?') {
                if(cmin > jmax && cmin - jmax > pow(10, C.length() - 1 - i) + jmin - cmax) {
                        C[i] = '0';
                        J[i] = '1';
                        C = fillmax(C, i + 1);
                        J = fillmin(J, i + 1);
                        break;
                } else if(jmin > cmax && jmin - cmax > pow(10, C.length() - 1 - i) + cmin - jmax) {
                        J[i] = '0';
                        C[i] = '1';
                        J = fillmax(J, i + 1);
                        C = fillmin(C, i + 1);
                        break;
                } else {
                    C[i] = '0';
                    J[i] = '0';
                }
            } else if(C[i] == '?') {
                if(cmin > jmax && J[i] != '0' && cmin - jmax > pow(10, C.length() - 1 - i) + jmin - cmax) {
                        C[i] = J[i] - 1;
                        C = fillmax(C, i + 1);
                        J = fillmin(J, i + 1);
                        break;
                } else if(jmin > cmax && J[i] != '9' && jmin - cmax > pow(10, C.length() - 1 - i) + cmin - jmax) {
                        C[i] = J[i] + 1;
                        J = fillmax(J, i + 1);
                        C = fillmin(C, i + 1);
                        break;
                } else {
                    C[i] = J[i];
                }
            } else if(J[i] == '?') {
                if(jmin > cmax && C[i] != '0' && jmin - cmax > pow(10, C.length() - 1 - i) + cmin - jmax) {
                        J[i] = C[i] - 1;
                        J = fillmax(J, i + 1);
                        C = fillmin(C, i + 1);
                        break;
                } else if(cmin > jmax && C[i] != '9' && cmin - jmax > pow(10, C.length() - 1 - i) + jmin - cmax) {
                        J[i] = C[i] + 1;
                        C = fillmax(C, i + 1);
                        fillmin(J, i + 1);
                        break;
                } else {
                    J[i] = C[i];
                }
            }
        }
        fout << "Case #" << iT << ": " << C << " " << J << endl;
    }
	return 0;
}
