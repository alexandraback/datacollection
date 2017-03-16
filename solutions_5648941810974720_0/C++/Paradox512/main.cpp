#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    cin.ignore();
    for(int i=0; i<t; i++){
        vector<int> digits;
        map<char, int> hist;
        string line;
        getline(cin, line);
        for(char c : line) hist[c]++;
        while(hist['X']>0){ digits.push_back(6); hist['X']--; hist['I']--; hist['S']--; }
        while(hist['Z']>0){ digits.push_back(0); hist['Z']--; hist['E']--; hist['R']--; hist['O']--; }
        while(hist['W']>0){ digits.push_back(2); hist['T']--; hist['W']--; hist['O']--; }
        while(hist['G']>0){ digits.push_back(8); hist['E']--; hist['I']--; hist['G']--; hist['H']--; hist['T']--; }
        while(hist['U']>0){ digits.push_back(4); hist['F']--; hist['O']--; hist['U']--; hist['R']--; }
        while(hist['F']>0){ digits.push_back(5); hist['F']--; hist['I']--; hist['V']--; hist['E']--; }
        while(hist['V']>0){ digits.push_back(7); hist['S']--; hist['E']-=2; hist['V']--; hist['N']--; }
        while(hist['O']>0){ digits.push_back(1); hist['O']--; hist['N']--; hist['E']--; }
        while(hist['T']>0){ digits.push_back(3); hist['T']--; hist['H']--; hist['R']--; hist['E']-=2; }
        while(hist['I']>0){ digits.push_back(9); hist['N']-=2; hist['I']--; hist['E']--; }
        sort(digits.begin(), digits.end());
        cout << "Case #" << i+1 << ": ";
        for(int d : digits) cout << d;
        cout << endl;
    }
    return 0;
}
