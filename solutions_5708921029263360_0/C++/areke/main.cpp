#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

string toBinary(long long num, long long b) {
    string s;
    while (num != 0) {
        s = (num % 2 == 0 ? "0" : "1") + s;
        num /= 2;
    }
    while (s.length() < b) {
        s = "0" + s;
    }
    return s;
}

int main() {
    
    
    ifstream fin ("C-small-attempt2.in");
    ofstream fout ("output.out");
    
    long long tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        fout << "Case #" << test+1 << ": ";
        long long j, p, s, k;
        fin >> j >> p >> s >> k;
        
        map<pair<int, int>, int> ab;
        map<pair<int, int>, int> ac;
        map<pair<int, int>, int> bc;
        long long cnt = 0;
        for (int a = 1; a <= j; a++) {
            for (int b = 1; b <= p; b++) {
                for (int c = 1; c <= s; c++) {
                    pair<int, int> ab1 = make_pair(a, b);
                    pair<int, int> ac1 = make_pair(a, c);
                    pair<int, int> bc1 = make_pair(b, c);
                    bool bo = true;
                    if (ab.count(ab1) == 1 && ab[ab1] >= k) {
                        bo = false;
                    }
                    if (ac.count(ac1) == 1 && ac[ac1] >= k) {
                        bo = false;
                    }
                    if (bc.count(bc1) == 1 && bc[bc1] >= k) {
                        bo = false;
                    }
                    if (bo) {
                        cnt++;
                        //cout << test << " " << a << " " << b << " " << ab[ab1] << " " << k << endl;
                        if (ab.count(ab1) == 1) {
                            ab[ab1]++;
                        }
                        else {
                            ab[ab1] = 1;
                        }
                        if (ac.count(ac1) == 1) {
                            ac[ac1]++;
                        }
                        else {
                            ac[ac1] = 1;
                        }
                        if (bc.count(bc1) == 1) {
                            bc[bc1]++;
                        }
                        else {
                            bc[bc1] = 1;
                        }
                    }
                }
            }
        }
        fout << cnt << endl;
        ab.clear();
        ac.clear();
        bc.clear();
        for (int a = 1; a <= j; a++) {
            for (int b = 1; b <= p; b++) {
                for (int c = 1; c <= s; c++) {
                    pair<int, int> ab1 = make_pair(a, b);
                    pair<int, int> ac1 = make_pair(a, c);
                    pair<int, int> bc1 = make_pair(b, c);
                    bool bo = true;
                    if (ab.count(ab1) == 1 && ab[ab1] >= k) {
                        bo = false;
                    }
                    if (ac.count(ac1) == 1 && ac[ac1] >= k) {
                        bo = false;
                    }
                    if (bc.count(bc1) == 1 && bc[bc1] >= k) {
                        bo = false;
                    }
                    if (bo) {
                        fout << a << " " << b << " " << c << endl;
                        if (ab.count(ab1) == 1) {
                            ab[ab1]++;
                        }
                        else {
                            ab[ab1] = 1;
                        }
                        if (ac.count(ac1) == 1) {
                            ac[ac1]++;
                        }
                        else {
                            ac[ac1] = 1;
                        }
                        if (bc.count(bc1) == 1) {
                            bc[bc1]++;
                        }
                        else {
                            bc[bc1] = 1;
                        }
                    }
                }
            }
        }
    }
    
    
}