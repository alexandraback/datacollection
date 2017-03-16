/*
 * abeakkas
 * Google CodeJam 2016 - Round 1B
 * Problem 1
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
ifstream fin("A.in");
ofstream fout("A.out");

int main(){
    int T;
    fin >> T;
    for(int iT = 1; iT <= T; iT++) {
        // Brute force foreva
        int digits[] = {0,0,0,0,0,0,0,0,0,0};
        int bow[200];
        for(char c = 'A'; c <= 'Z'; c++) {
            bow[c] = 0;
        }
        string s;
        fin >> s;
        for(int i = 0; i < s.length(); i++) {
            bow[s[i]]++;
        }
        while(bow['Z'] != 0) {
            bow['Z']--;
            bow['E']--;
            bow['R']--;
            bow['O']--;
            digits[0]++;
        }
        while(bow['W'] != 0) {
            bow['T']--;
            bow['W']--;
            bow['O']--;
            digits[2]++;
        }
        while(bow['U'] != 0) {
            bow['F']--;
            bow['O']--;
            bow['U']--;
            bow['R']--;
            digits[4]++;
        }
        while(bow['X'] != 0) {
            bow['S']--;
            bow['I']--;
            bow['X']--;
            digits[6]++;
        }
        while(bow['G'] != 0) {
            bow['E']--;
            bow['I']--;
            bow['G']--;
            bow['H']--;
            bow['T']--;
            digits[8]++;
        }
        while(bow['O'] != 0) {
            bow['O']--;
            bow['N']--;
            bow['E']--;
            digits[1]++;
        }
        while(bow['H'] != 0) {
            bow['T']--;
            bow['H']--;
            bow['R']--;
            bow['E']--;
            bow['E']--;
            digits[3]++;
        }
        while(bow['F'] != 0) {
            bow['F']--;
            bow['I']--;
            bow['V']--;
            bow['E']--;
            digits[5]++;
        }
        while(bow['S'] != 0) {
            bow['S']--;
            bow['E']--;
            bow['V']--;
            bow['E']--;
            bow['N']--;
            digits[7]++;
        }
        while(bow['N'] != 0) {
            bow['N']--;
            bow['I']--;
            bow['N']--;
            bow['E']--;
            digits[9]++;
        }
        fout << "Case #" << iT << ": ";
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < digits[i]; j++) {
                fout << i;
            }
        }
        fout << endl;
    }
	return 0;
}
