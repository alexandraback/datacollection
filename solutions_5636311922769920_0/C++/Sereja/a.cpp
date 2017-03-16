#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>

using namespace std;

void gen(string what, int c) {
    string original = what;
    string G = "";
    for (int j = 0; j < what.size(); j++) {
        G += 'G';
    }
    int e = 1;
    for (int i = 2; i <= c; i++) {
        string rez = "";
        for (int j = 0; j < what.size(); j++) {
            if (what[j] == 'L') {
                rez += original;
            } else {
                rez += G;
            }
        }
        what = rez;
        e *= original.size();  
    }    
    for (int i = 0; i <= e - 1; i++) {
        cout << what[i];
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
           
        int k, c, s;
        cin >> k >> c >> s;
        if (s < k - c + 1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            long long len = 1;
            if (c > k) {
                c = k;
            }
            for (int i = 1; i <= c; i++) {
                len *= k;
            }            
            long long pos = 1;            
            for (int i = 1; i <= c; i++) {                
                len /= k;
                long long left = len * (i - 1) + 1;
                long long pos2;
                if (left < pos) {
                    pos2 = ((pos - left) / (len * k)) * len * k + left;
                    while (pos2 < pos) {
                        pos2 += len * k;
                    }
                } else {
                    pos2 = left;
                }
                pos = pos2;
            }
            for (int i = k; i > c; i--) {
                cout << i << " ";
            }
            cout << pos << endl;
        }
    } 
    /*
    int p = 4;
    int len = 5;
    for (int i = 1; i <= len; i++) {
        string s = "";
        for (int j = 1; j <= len; j++) {
            if (j == i) {
                s += 'G';
            } else {
                s += 'L';
            }
        }
        gen(s, p);
    }*/
    return 0;
}