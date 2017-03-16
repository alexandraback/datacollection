#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>


using namespace std;


typedef long long LL;


int smpl[20] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };


string to_bin(LL nmasc, int n) {
    string s = "";
    for (int i = 0; i < n; ++i) {
        if (nmasc % 2 == 1) {
            s += '1';
        }
        else {
            s += '0';
        }
        nmasc >>= 1;
    } 
    //reverse(s.begin(), s.end());
    return s;
}


vector < int > check(int masc, int n) {
    string s = to_bin((LL) masc, n);
    
    vector < int > ans;
    for (int i = 2; i <= 10; ++i) {
        LL val = 0;
        for (int j = 0; j < n; ++j) {
            val *= i;
            val += (LL) (s[j] - '0');
        }

        for (int j = 2; j * j <= val; ++j) {
            if (val % j == 0) {
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}


vector < int > long_check(LL masc, int n) {
        vector < int > ans;

    string s = to_bin(masc, n);
    reverse(s.begin(), s.end());
    for (int i = 2; i <= 10; ++i) {
        vector < int > rev (20, 0);

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 20; ++k) {
                rev[k] *= i;
                rev[k] += s[j] - '0';
                rev[k] %= smpl[k];
            }
        }
        for (int k = 0; k < 20; ++k) {
            if (rev[k] == 0) {
                ans.push_back(smpl[k]);
                break;
            }
        }
    } 
    return ans;
}


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ":\n";
        int n, j;
        cin >> n >> j;
        if (n <= 15) {
            for (int masc = 0; masc < (1 << (n - 2)); ++masc) {
                int nmasc = ((1 << (n - 1)) + masc * 2 + 1);
                vector < int > cans = check(nmasc, n);
                if (cans.size() == 9) {
                    string ds = to_bin(nmasc, n);
                    reverse(ds.begin(), ds.end());
                    cout << ds;
                    for (int i = 0; i < 9; ++i) {
                        cout << " " << cans[i];
                    } 
                    cout << "\n";
                    --j;
                    if (j == 0) break;
                }
            }
            
        }
        else {
            int num = 0;
            for (LL masc = 0; masc < (1ll << (n - 2ll)); ++masc) {
                LL nmasc = ((1ll << (n - 1ll)) + masc * 2ll + 1ll);
                vector < int > cans = long_check(nmasc, n);
                if (cans.size() == 9) {
                    ++num;
                    string ds = to_bin(nmasc, n);
                    reverse(ds.begin(), ds.end());
                    cout << ds << " ";
                    for (int i = 0; i < 9; ++i) {
                        cout << cans[i] << " ";
                    }
                    cout << endl;
                    if (num >= j) {
                        
                        break;
                    }
                }
                
            }
        }
    }
    return 0;
}